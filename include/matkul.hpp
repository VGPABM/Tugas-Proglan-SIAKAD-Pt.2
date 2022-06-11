#ifndef __MATKUL_HPP__
#define __MATKUL_HPP__

#include <iostream>

class matkul{
private:
    std::string namamatkul;
    std::string dosenpengajar;
    std::string deptpengurus;
    int jumlah_sks,jumlahkelas,minimalSemester,kuotaterdaftar,siswaterdaftar;
public:
    matkul(std::string namamatkul, std::string dosenpengajar,std::string deptpengurus,
            int jumlah_sks, int jumlahkelas, int kuotaterdaftar ,int minimalSemester,int siswaterdaftar);
    

    void setNama(std::string namamatkul);
    std::string getNama();

    void setDosen(std::string dosenpengajar);
    std::string getDosen();

    void setDeptPeng(std::string deptpengurus);
    std::string getDeptPeng();

    void setJumlahSKS(int jumlah_sks);
    int getJumlahSKS();

    void setJumlahkls(int jumlahkelas);
    int getJumlahkls();

    void setJumlahsiswaterdaftar(int jumlahsiswaterdaftar);
    int getjumlahsiswaterdaftar();

    void setminimalSemester(int minimalSemester);
    int getminimalSemester();

    void setKuotasiswa(int kuotaterdaftar);
    int getKuotasiswa();

    void addmahasiswaterdaftar();
    int getmahasiswaterdaftar();
};




#endif