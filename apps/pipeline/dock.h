/* 
 * File:   dockBMPI.h
 * Author: zhang30
 *
 * Created on August 14, 2012, 1:53 PM
 */

#ifndef DOCKING_H
#define	DOCKING_H

#include <string>
#include <vector>

#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>



class JobInputData{
    
public:
    friend class boost::serialization::access;
    // When the class Archive corresponds to an output archive, the
    // & operator is defined similar to <<.  Likewise, when the class Archive
    // is a type of input archive the & operator is defined similar to >>.
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & useScoreCF;
        ar & flexible;
        ar & randomize;
        ar & cpu;
        ar & exhaustiveness;
        ar & num_modes;
        ar & seed;
        ar & n; 
        ar & scoreCF; 
        ar & energy_range;
        ar & granularity;
        ar & begin;
        ar & end;        
        ar & ligBuffer;
//        ar & ligFile;
        ar & recBuffer;
        ar & fleBuffer;  
        ar & nonRes;
    }

    bool useScoreCF; //switch to turn on score cutoff    
    bool flexible;
    bool randomize;
    int cpu;
    int exhaustiveness;
    int num_modes;
//    int mc_mult;
    int seed;
    int n[3]; 
    double scoreCF;  // value for score cutoff     
    double energy_range;
    double granularity;
    double begin[3];
    double end[3];       
    std::string ligBuffer;
//    std::string ligFile;
    std::string recBuffer;
    std::string fleBuffer;
    std::vector<std::string> nonRes;
};

struct JobOutData{

public:
    friend class boost::serialization::access;
    // When the class Archive corresponds to an output archive, the
    // & operator is defined similar to <<.  Likewise, when the class Archive
    // is a type of input archive the & operator is defined similar to >>.
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        
        ar & pdbID;
        ar & ligID;        
        ar & logPath;
        ar & posePath;
        ar & mesg;
        ar & scores;
        ar & nonRes;
    }
    std::string pdbID;
    std::string ligID;
    std::string logPath;
    std::string posePath;
    std::string mesg;
    std::vector<double> scores;
    std::vector<std::string> nonRes;
};

int dockjob(JobInputData& jobInput, JobOutData& jobOut, std::string& workDir);

bool getScores(std::string& log, std::vector<double>& scores);

#endif	/* DOCKING_H */

