/* 
 * File:   Mol2.h
 * Author: zhang30
 *
 * Created on September 26, 2012, 2:13 PM
 */

#ifndef MOL2_H
#define	MOL2_H

#include <string>

namespace LBIND{

    class Molecule;
    
class Mol2 {
public:
    Mol2();
    Mol2(const Mol2& orig);
    virtual ~Mol2();
    
    void read(const std::string& fileName, Molecule* pMolecule);
    
private:

};

} //namespace LBIND
#endif	/* MOL2_H */
