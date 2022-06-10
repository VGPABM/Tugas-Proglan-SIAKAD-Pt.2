#ifndef __MATKUL_HPP__
#define __MATKUL_HPP__


#include <iostream>

class matkul{
private:
    std::string namamatkul;
    std::string dosenpengajar;
    std::string deptpengurus;
    int jumlah_sks,jumlahkelas,jumlahsiswaterdaftar,minimalSemester,kuotaterdaftar;
public:
    matkul(std::string namamatkul, std::string dosenpengajar,std::string deptpengurus,
            int jumlah_sks, int jumlahkelas, int jumlahsiswaterdaftar);
    
    void assignMahasiswa();

};




#endif