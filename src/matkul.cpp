#include <iostream>
#include <vector>
#include "include/matkul.hpp"

matkul::matkul(std::string namamatkul, std::string dosenpengajar,std::string deptPengurus,int jumlah_sks, int jumlahkelas, int kuotaterdaftar,int minimalSemester)
        : namamatkul(namamatkul), dosenpengajar(dosenpengajar), deptpengurus(deptpengurus), jumlah_sks(jumlah_sks), jumlahkelas(jumlahkelas), kuotaterdaftar(kuotaterdaftar),minimalSemester(minimalSemester)
{
}

void matkul::setNama(std::string namamatkul){
    this->namamatkul = namamatkul;
}

std::string matkul::getNama(){
    return this->namamatkul;
}

void matkul::setDosen(std::string dosenpengajar){
    this-> dosenpengajar = dosenpengajar;
}

std::string matkul::getDosen(){
    return this->dosenpengajar;
}

void matkul::setDeptPeng(std::string deptpengurus){
    this-> deptpengurus = deptpengurus;
}

std::string matkul::getDeptPeng(){
    return this->deptpengurus;
}

void matkul::setJumlahSKS(int jumlah_sks){
    this->jumlah_sks = jumlah_sks;
}

int matkul::getJumlahSKS(){
    return this->jumlah_sks;
}

void matkul::setJumlahkls(int jumlahkelas){
    this->jumlahkelas = jumlahkelas;
}

int matkul::getJumlahkls(){
    return this->jumlahkelas;
}

/*void matkul::setJumlahsiswaterdaftar(int jumlahsiswaterdaftar){
    this->jumlahsiswaterdaftar = jumlahsiswaterdaftar;
}

int matkul::getjumlahsiswaterdaftar(){
    return this->jumlahsiswaterdaftar;
}*/

void matkul::setKuotasiswa(int kuotaterdaftar){
    this-> kuotaterdaftar = kuotaterdaftar;
}

int matkul::getKuotasiswa(){
    return this-> kuotaterdaftar;
}

void matkul::setminimalSemester(int minimalSemester){
    this-> minimalSemester = minimalSemester;
}

int matkul::getminimalSemester(){
    return this-> minimalSemester;
}

/*int matkul::getmahasiswaterdaftar(){
    return this->jumlahsiswaterdaftar;
}

void matkul::addmahasiswaterdaftar(){
    this -> minimalSemester += 1;
}*/