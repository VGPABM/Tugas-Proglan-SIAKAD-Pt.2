#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <string>

#include "include/matkul.hpp"
#include "include/person.hpp"
#include "include/mahasiswa.hpp"
#include "include/dosen.hpp"
#include "include/tendik.hpp"

using namespace std;

const int MAX_VALID_YR = 9999;
const int MIN_VALID_YR = 1800;

vector<mahasiswa> recMhs;
vector<dosen> recDosen;
vector<tendik> recTendik;
vector<matkul> recMatkul;

/*
Beberapa function penting yang banyak digunakan di dalam SIM ini:
if (cin.fail()) --> mengecek apabila dilakukan kesalahan input data sehingga fungsi cin masuk ke dalam status False --> kemudian digunakan cin.ignore untuk mematikan fungsi cin
system("@cls || clear") --> membersihkan terminal sehingga terlihat rapi. @cls untuk membersihkan terminal di vscode windows sementara clear digunakan untuk terminal di linux
isvalidate --> digunakan untuk mengecek angka tanggal,bulan dan tahun yang dimasukkan adalah sebuah tanggal yang valid dan benar-benar ada di dunia ini.
*/

unsigned urutanlog; //digunakan untuk memilih dosen/mahasiswa/tendik tersebut terdapat di bagian mana ketika dilakukan searching di vector

bool isNumber(const string& s)
{
    for (char const &ch : s) {
        if (std::isdigit(ch) == 0) 
            return false;
    }
    return true;
 }
//function untuk mengecek angka atau bukan

bool isLeap(int year) {
return (((year % 4 == 0) &&
         (year % 100 != 0)) ||
         (year % 400 == 0));
}
//function untuk mengecek tahun tersebut leap year atau bukan

bool isValidDate(int dd, int mm, int yy)
{

    if (yy > MAX_VALID_YR ||
        yy < MIN_VALID_YR)
    return false;
    if (mm < 1 || mm > 12)
    return false;
    if (dd < 1 || dd > 31)
    return false;

    if (mm == 2)
    {
        if (isLeap(yy))
        return (dd <= 29);
        else
        return (dd <= 28);
    }

    if (mm == 4 || mm == 6 ||
        mm == 9 || mm == 11)
        return (dd <= 30);
 
    return true;
}
//function untuk utama pengecekan tanggal valid atau tidak

string bulanConverter(int number){
	string bulan;
	switch (number){
		case 1: {bulan = "Januari"; return bulan;} break;
		case 2: {bulan = "Februari"; return bulan;} break;
		case 3: {bulan = "Maret"; return bulan;} break;
		case 4: {bulan = "April"; return bulan;} break;
		case 5: {bulan = "Mei"; return bulan;} break;
		case 6: {bulan = "Juni"; return bulan;} break;
		case 7: {bulan = "Juli"; return bulan;} break;
		case 8: {bulan = "Agustus"; return bulan;} break;
		case 9: {bulan = "September"; return bulan;} break;
		case 10: {bulan = "Oktober"; return bulan;} break;
		case 11: {bulan = "November"; return bulan;} break;
		case 12: {bulan = "Desember"; return bulan;} break;
	}
}
//function untuk mengkonversi tanggal, bulan dan tahun, ke dalam tulisan

int startmenu(int temp){
	string username,password;
while (temp == 0){
	system("@cls || clear");
	bool temp1,temp2,temp3;
	cout<<"Selamat datang di SIM Universitas Amediketu"<<endl;
	cout<<endl; cout<<endl; cout<<endl; cout<<endl;
	cout << "Masukkan username : ";
	cin >> username;
	cout << "Masukkan password : ";
	cin >> password;

	remove(username.begin(),username.end(),' ');
	transform(username.begin(),username.end(),username.begin(),::tolower);

	for (int i=0;i<recMhs.size();i++){
		string checker;
		urutanlog = i;
		checker = recMhs[i].getNama();
		remove(checker.begin(),checker.end(),' ');//menghilangkan spasi dari nama
		transform(checker.begin(),checker.end(),checker.begin(),::tolower);//membuat nama menjadi huruf kecil semua
		if (username == checker){
			temp1 = true;
		}
	} 

	for (int i=0;i<recDosen.size();i++){
		string checker;
		urutanlog = i;
		checker = recDosen[i].getNama();
		remove(checker.begin(),checker.end(),' ');//menghilangkan spasi dari nama
		transform(checker.begin(),checker.end(),checker.begin(),::tolower);//membuat nama menjadi huruf kecil semua
		if (username == checker){
			temp2 = true;
		}
	}

	for (int i=0;i<recTendik.size();i++){
		string checker;
		urutanlog = i;
		checker = recTendik[i].getNama();
		remove(checker.begin(),checker.end(),' ');//menghilangkan spasi dari nama
		transform(checker.begin(),checker.end(),checker.begin(),::tolower);//membuat nama menjadi huruf kecil semua
		if (username == checker){
			temp3 = true;
		}
	}

	if (username == "admin" && password == "admin"){
		temp = 1;
	} else if (temp2 = true && password == "dosen"){
		temp = 2;
	}
	else if (temp1 = true && password ==  "mahasiswa"){
		temp = 3;
	} else if (temp3 = true && password ==  "tendik"){
		temp = 4;
	} else  {
		system("@cls || clear");
		cout<<"user atau password salah";
		cout<<endl; cout<<endl; cout<<endl; cout<<endl;
		cout<<"Tekan enter untuk kembali ke awal"<<endl;
		cin.ignore();
		cin.ignore();
		temp = startmenu(temp);
	}
	return temp;
}
}
//menu login, muncul ketika varible temp = 0

int main(int argc, char** argv)
{
	int menu_terpilih;
	string username;
	int temp = 0;
	start:
	temp = 0;
	system("@cls || clear");//function untuk membersihkan terminal
	temp = startmenu(temp); //masuk ke dalam function startmenu

//Looping utama menu dari admin access
	while (temp == 1){
		admin:
		system("@cls || clear");
		cout << "Selamat datang di Universitas amediketu" << endl << endl;
		cout << "Data statistik:" << endl;
		cout << "  1. Jumlah Mahasiswa             : " << recMhs.size() << " Mahasiswa" << endl;
		cout << "  2. Jumlah Dosen                 : " << recDosen.size() << " Dosen" << endl;
		cout << "  3. Jumlah Tenaga Kependidikan   : " << recTendik.size() << " Tendik" << endl;
		cout << endl;
		cout << "Menu: " << endl;
		cout << "  1. Tambah Mahasiswa" << endl;
		cout << "  2. Tambah Dosen" << endl;
		cout << "  3. Tambah Tenaga Kependidikan" << endl;
		cout << "  4. Tampilkan semua Mahasiswa" << endl;
		cout << "  5. Tampilkan semua Dosen" << endl;	
		cout << "  6. Tampilkan semua Tenaga Kependidikan" << endl;
		cout << "  7. Kelola Mata Kuliah" << endl;
		cout << "  8. Log Out" << endl;
		cout << "-> Silahkan memilih salah satu: ";
		cin >> menu_terpilih;
		if (cin.fail())
			{cin.clear();cin.ignore();cin.ignore();}

		switch (menu_terpilih) {
		//Menambahkan Mahasiswa baru
		case 1:{
				system("@cls || clear");
				cout<< "Menu menambah mahasiswa"<<endl;
				cout<< "========================"<<endl;
				cout<<"Masukkan nama mahasiswa: ";
				string id,nama,nrp,departemen;
				float semester;
				int dd,mm,yy,tahunmasuk;
				int urutan = recMhs.size() + 1;
				string counter = to_string(urutan);
				id = "m" + counter;
				cin.ignore();
				getline(cin,nama);
				cout<<"Masukkan nrp: ";
				cin>>nrp;
				if (!isNumber(nrp)){
					system("@cls || clear");
					cout<<"NRP yang anda masukkan salah";
					cout<<endl; cout<<endl; cout<<endl; cout<<endl;
					cout<<"Tekan enter untuk kembali ke awal"<<endl;
					cin.ignore();
					cin.ignore();
					break;
				}

				cout<<"Masukkan tanggal lahir: ";
				cin>>dd;
				if (cin.fail())
				{cin.clear();cin.ignore();cin.ignore();break;}

				cout<<"Masukkan bulan lahir: ";
				cin>>mm;
				if (cin.fail())
				{cin.clear();cin.ignore();cin.ignore();break;}

				cout<<"Masukkan tahun lahir: ";
				cin>>yy;
				if (cin.fail())
				{cin.clear();cin.ignore();cin.ignore();break;}

				if (!isValidDate(dd,mm,yy)){
					system("@cls || clear");
					cout<<"Tanggal yang anda masukkan tidak valid"<<endl;
					cout<<endl; cout<<endl; cout<<endl; cout<<endl;
					cout<<"Tekan enter untuk kembali ke awal"<<endl;
					cin.ignore();
					cin.ignore();
					break;
				}

				cout<<"Masukkan asal departemen: ";
				cin.ignore();
				getline(cin,departemen);

				cout<<"Masukkan tahun masuk: ";
				cin>>tahunmasuk;

				cout<<"Masukkan semester berapa: ";
				cin>>semester;		

				int skssemesterini = 0;
				mahasiswa newMahasiswa(id,nama,dd,mm,yy,nrp,departemen,tahunmasuk,semester,skssemesterini);
				recMhs.push_back(newMahasiswa);
				
			}
			break;

		//Menambahkan Dosen Baru
		case 2:{
				system("@cls || clear");
				cout<< "Menu menambah Dosen"<<endl;
				cout<< "========================"<<endl<<endl;
				string id,namadosen,npp,departemen,pendidikan;
				int dd,mm,yy;
				id = "d" + recDosen.size();
				cout<<"Masukkan nama dosen:";
				cin.ignore();
				getline(cin,namadosen);
				cout<<"Masukkan npp:";
				cin>>npp;
				if (!isNumber(npp)){
					system("@cls || clear");
					cout<<"NRP yang anda masukkan salah";
					cout<<endl; cout<<endl; cout<<endl; cout<<endl;
					cout<<"Tekan enter untuk kembali ke awal"<<endl;
					cin.ignore();
					cin.ignore();
					break;
				}
				cout<<"Masukkan asal departemen:";
				cin.ignore();
				getline(cin,departemen);
				cout<<"Masukkan tanggal lahir:";
				cin>>dd;
				if (cin.fail())	
{cin.clear();cin.ignore();cin.ignore();break;}
				cout<<"Masukkan bulan lahir:";
				cin>>mm;
				if (cin.fail())	
{cin.clear();cin.ignore();cin.ignore();break;}
				cout<<"Masukkan tahun lahir:";
				cin>>yy;
				if (cin.fail())
				{cin.clear();cin.ignore();cin.ignore();break;}
				if (!isValidDate(dd,mm,yy)){
					system("@cls || clear");
					cout<<"Tanggal yang anda masukkan tidak valid"<<endl;
					cout<<endl; cout<<endl; cout<<endl; cout<<endl;
					cout<<"Tekan enter untuk kembali ke awal"<<endl;
					cin.ignore();
					cin.ignore();
					break;
				}
				cout<<"Masukkan pendidikan terakhir:";
				cin.ignore();
				getline(cin,pendidikan);
				dosen newDosen(id,namadosen,dd,mm,yy,npp,departemen,pendidikan);
				recDosen.push_back(newDosen);
			}
			break;

		//Menambahkan Tendik Baru
		case 3:{
				system("@cls || clear");
				cout<< "Menu menambah Tenaga Pendidik"<<endl;
				cout<< "========================"<<endl<<endl;
				string id,namatd,npp,unit;
				int dd,mm,yy;
				id = "td" + recTendik.size();
				cout<<"Masukkan nama Tenaga Pendidik:";
				cin.ignore();
				getline(cin,namatd);
				cout<<"Masukkan npp:";
				cin>>npp;
				if (!isNumber(npp)){
					system("@cls || clear");
					cout<<"NRP yang anda masukkan salah";
					cout<<endl; cout<<endl; cout<<endl; cout<<endl;
					cout<<"Tekan enter untuk kembali ke awal"<<endl;
					cin.ignore();
					cin.ignore();
					break;
				}
				cout<<"Masukkan asal unit:";
				cin.ignore();
				getline(cin,unit);
				cout<<"Masukkan hari lahir:";
				cin>>dd;
				if (cin.fail())	
{cin.clear();cin.ignore();cin.ignore();break;}
				cout<<"Masukkan bulan lahir:";
				cin>>mm;
				if (cin.fail())	
{cin.clear();cin.ignore();cin.ignore();break;}
				cout<<"Masukkan tahun lahir:";
				cin>>yy;
				if (cin.fail())	
{cin.clear();cin.ignore();cin.ignore();break;}


				if (!isValidDate(dd,mm,yy)){
					system("@cls || clear");
					cout<<"Tanggal yang anda masukkan tidak valid"<<endl;
					cout<<endl; cout<<endl; cout<<endl; cout<<endl;
					cout<<"Tekan enter untuk kembali ke awal"<<endl;
					cin.ignore();
					cin.ignore();
					break;
				}

				tendik newTd(id,namatd,dd,mm,yy,npp,unit);
				recTendik.push_back(newTd);
			}
			break;

		//Mengakses database vektor Mahasiswa
		case 4:{
			system("@cls || clear");
			cout<<"List Mahasiswa"<<endl;
			int i = 0;
			int pilihan = 0;
			for (i;i<recMhs.size();i++){
				int o=i+1;
				cout<<o;
				cout<<". ";
				cout<<recMhs[i].getNama()<<endl;
			}
			int selection;
			cout<< "Pilih mahasiswa : ";
			cin>>pilihan;
			pilihan = pilihan-1;

			inspection:
			system("@cls || clear");
			cout<<"Data Mahasiswa"<<endl;
			cout<<"=================="<<endl;
			cout<<"1. Nama Mahasiswa : ";
			cout<<recMhs[pilihan].getNama()<<endl;
			cout<<"2. Id : ";
			cout<<recMhs[pilihan].getId()<<endl;
			cout<<"3. NRP Mahasiswa :";
			cout<<recMhs[pilihan].getNRP()<<endl;
			cout<<"4. Departemen :";
			cout<<recMhs[pilihan].getDepartemen()<<endl;
			cout<<"5. Tanggal Lahir : ";
			cout<<recMhs[pilihan].getTglLahir(); cout<<" ";
			cout<<bulanConverter(recMhs[pilihan].getBulanLahir());cout<<" ";
			cout<<recMhs[pilihan].getTahunLahir()<<endl;
			cout<<"6. Tahun Masuk : ";
			cout<<recMhs[pilihan].getTahunmasuk()<<endl;
			cout<<"7. Semester ke: ";
			cout<<recMhs[pilihan].getTahunmasuk()<<endl;
			cout<<endl; cout<<endl; cout<<endl;
			cout<<"Akademik"<<endl<<"================="<<endl;
			cout<<"8. IPK : ";
			cout<<recMhs[pilihan].getIPK()<<endl;
			cout<<"9.Semester ke : ";
			cout<<recMhs[pilihan].getSemester()<<endl;
			cout<<"10. SKS Lulus : ";
			cout<<recMhs[pilihan].getSKSLulus()<<endl;
			cout<<"11. Tahun Masuk : ";
			cout<<recMhs[pilihan].getTahunmasuk()<<endl;
			cout<<endl; cout<<endl; cout<<endl; cout<<endl;
			cout<<"Press 1 to edit biodata "<<endl << "Press 2 to input IPS"<<endl<<"Press 3 to exit";
			cin>>selection;

			int mode=0;
				switch (selection)
				{
					case 1:{
						mode = 1;
						while (mode == 1){
							system("@cls || clear");
							cout<<"Edit Biodata"<<endl;
							cout<<"=================="<<endl;
							cout<<"1. Nama Mahasiswa : ";
							cout<<recMhs[pilihan].getNama()<<endl;
							cout<<"2. NRP Mahasiswa :";
							cout<<recMhs[pilihan].getNRP()<<endl;
							cout<<"3. Departemen : ";
							cout<<recMhs[pilihan].getDepartemen()<<endl;
							cout<<"4. Tanggal Lahir : ";
							cout<<recMhs[pilihan].getTglLahir(); cout<<" ";
							cout<<bulanConverter(recMhs[pilihan].getBulanLahir());cout<<" ";
							cout<<recMhs[pilihan].getTahunLahir()<<endl;
							cout<<"5. Tahun Masuk : ";
							cout<<recMhs[pilihan].getTahunmasuk();
							cout<<endl; cout<<endl; cout<<endl;
							
							string sel;
							cout<<"Pilih data yang mau di edit : ";
							cin>>sel;
							if (sel == "1"){
							string nama;
							cout<<"Masukkan nama yang baru : ";
							cin.ignore();
							getline(cin,nama);
							recMhs[pilihan].setNama(nama);
							} else if (sel == "2"){
							string nrp;
							cout<<"Masukkan nrp yang baru : ";
							cin.ignore();
							getline(cin,nrp);
							if (!isNumber(nrp)){
system("@cls || clear");
cout<<"NRP yang anda masukkan salah";
cout<<endl; cout<<endl; cout<<endl; cout<<endl;
cout<<"Tekan enter untuk kembali ke awal"<<endl;
cin.ignore();
cin.ignore();
	break;
				}
							recMhs[pilihan].setNRP(nrp);
							} else if (sel == "3"){
							string departemen;
							cout<<"Masukkan departemen yang baru :";
							cin.ignore();
							getline(cin,departemen);
							recMhs[pilihan].setDepartemen(departemen);
							} else if (sel == "4"){
							int dd,mm,yy;
							cout<<"masukkan tanggal yang baru : ";
							cin>>dd;
							if (cin.fail())
{cin.clear();cin.ignore();cin.ignore();break;}
							cout<<"masukkan bulan yang baru : ";
							cin>>mm;
							if (cin.fail())
{cin.clear();cin.ignore();cin.ignore();break;}
							cout<<"masukkan tahun yang baru : ";
							cin>>yy;
							if (cin.fail())	
{cin.clear();cin.ignore();cin.ignore();break;}

if (!isValidDate(dd,mm,yy)){
	system("@cls || clear");
	cout<<"Tanggal yang anda masukkan tidak valid"<<endl;
	cout<<endl; cout<<endl; cout<<endl; cout<<endl;
	cout<<"Tekan enter untuk kembali ke awal"<<endl;
	cin.ignore();
	cin.ignore();
	break;
	}
							recMhs[pilihan].setTglLahir(dd,mm,yy);
							} else if (sel == "5"){
							int tahunmasuk;
							cout<<"masukkan tahun yang baru : ";
							cin>>tahunmasuk;
							recMhs[pilihan].setTahunmasuk(tahunmasuk);
							} else {
							system("@cls || clear");
							goto inspection;
							}
						}
					}
					break;
				case 2:
				{
					IPS:
					system("@cls || clear");
					int semester,choice;
					cout<<"Edit Akademik siswa :"<< endl;
					cout<<"====================="<<endl;
					cout<<"Semester ke : "<<recMhs[pilihan].getSemester()<<endl;
					cout<<"Nilai IPK : "<<recMhs[pilihan].getIPK()<<endl;
					for (float i=0;i<recMhs[pilihan].getSemester();i++){
							cout<<i+1<<". ";
							cout<<"Semester "<<i+1<<": ";
							cout<<recMhs[pilihan].getIPS(i)<<endl;
					}
					cout<<endl;cout<<endl;

					cout<<"press 1 to set IPS"<<endl<<"press 2 to edit"<<endl<<"press 0 to exit";
					cin>>choice;
					if (cin.fail())
{cin.clear();cin.ignore();cin.ignore();break;}
					float ips;
					if (choice == 1){
						cout<<endl;cout<<endl;
						for (unsigned i=0;i<recMhs[pilihan].getSemester();i++){
							cout<<i+1<<". ";
							cout<<"Semester "<<i+1<<": ";
							cin>>ips;
							if (cin.fail())
{cin.clear();cin.ignore();cin.ignore();break;}
							recMhs[pilihan].setIPS(i,ips);
						
						}
					goto IPS;
					} else if (choice == 0) {goto inspection;}
					else if (choice == 2) {
						float newsems;
						cout<<"masukkan semester baru : ";
						cin>>newsems;	
						if (cin.fail())
{cin.clear();cin.ignore();cin.ignore();break;}
						recMhs[pilihan].setSemester(newsems);
						goto IPS;
					}
				}
					break;
					
			}
			}
			break;

		//Mengakses database vektor dosen
		case 5:{
			system("@cls || clear");
			cout<<"List Dosen"<<endl;
			int i = 0;
			int pilihan = 0;
			for (i;i<recDosen.size();i++){
				int o=i+1;
				cout<<o;
				cout<<". ";
				cout<<recDosen[i].getNama()<<endl;
			}
			int selection=0;
			cout<< "Pilih Dosen : ";
			cin>>pilihan;
			pilihan = pilihan-1;

			inspectDos:
			system("@cls || clear");
			cout<<"Data Dosen"<<endl;
			cout<<"=================="<<endl;
			cout<<"1. Nama Dosen : ";
			cout<<recDosen[pilihan].getNama()<<endl;
			cout<<"2. Id : ";
			cout<<recDosen[pilihan].getId()<<endl;
			cout<<"3. NPP Dosen :";
			cout<<recDosen[pilihan].getNPP()<<endl;
			cout<<"4. Departemen :";
			cout<<recDosen[pilihan].getDept()<<endl;
			cout<<"5. Pendidikan :";
			cout<<recDosen[pilihan].getPendidikan()<<endl;
			cout<<"6. Tanggal Lahir : ";
			cout<<recDosen[pilihan].getTglLahir(); cout<<" ";
			cout<<bulanConverter(recDosen[pilihan].getBulanLahir());cout<<" ";
			cout<<recDosen[pilihan].getTahunLahir()<<endl;
			
			cout<<"Press 1 to edit biodata "<<endl<<"Press 2 to exit";
			cin>>selection;
			int mode=0;

			if (selection == 1) {
				mode=1;
			editdos:
			while (mode=1){
				system("@cls || clear");
			cout<<"Edit Data Dosen"<<endl;
			cout<<"=================="<<endl;
			cout<<"1. Nama Dosen : ";
			cout<<recDosen[pilihan].getNama()<<endl;
			cout<<"2. NPP Dossen :";
			cout<<recDosen[pilihan].getNPP()<<endl;
			cout<<"3. Departemen :";
			cout<<recDosen[pilihan].getDept()<<endl;
			cout<<"4. Pendidikan :";
			cout<<recDosen[pilihan].getPendidikan()<<endl;
			cout<<"5. Tanggal Lahir : ";
			cout<<recDosen[pilihan].getTglLahir(); cout<<" ";
			cout<<bulanConverter(recDosen[pilihan].getBulanLahir());cout<<" ";
			cout<<recDosen[pilihan].getTahunLahir()<<endl;

			string sel;
			cout<<"Pilih data yang mau di edit : ";
							cin>>sel;
							if (sel == "1"){
							string nama;
							cout<<"Masukkan nama yang baru : ";
							cin.ignore();
							getline(cin,nama);
							recDosen[pilihan].setNama(nama);
							} else if (sel == "2"){
							string npp;
							cout<<"Masukkan npp yang baru : ";
							cin.ignore();
							getline(cin,npp);
							if (!isNumber(npp)){
system("@cls || clear");
cout<<"NRP yang anda masukkan salah";
cout<<endl; cout<<endl; cout<<endl; cout<<endl;
cout<<"Tekan enter untuk kembali ke awal"<<endl;
cin.ignore();
cin.ignore();
	break;
				}
							recDosen[pilihan].setNPP(npp);
							} else if (sel == "3"){
							string departemen;
							cout<<"Masukkan departemen yang baru :";
							cin.ignore();
							getline(cin,departemen);
							recDosen[pilihan].setDept(departemen);
							} else if (sel == "5"){
							int dd,mm,yy;
							cout<<"masukkan tanggal yang baru : ";
							cin>>dd;
							if (cin.fail())	
{cin.clear();cin.ignore();cin.ignore();break;}
							cout<<"masukkan bulan yang baru : ";
							cin>>mm;
							if (cin.fail())	
{cin.clear();cin.ignore();cin.ignore();break;}
							cout<<"masukkan tahun yang baru : ";
							cin>>yy;
							if (cin.fail())	
{cin.clear();cin.ignore();cin.ignore();break;}
if (!isValidDate(dd,mm,yy)){
	system("@cls || clear");
	cout<<"Tanggal yang anda masukkan tidak valid"<<endl;
	cout<<endl; cout<<endl; cout<<endl; cout<<endl;
	cout<<"Tekan enter untuk kembali ke awal"<<endl;
	cin.ignore();
	cin.ignore();
	break;
	}
							recDosen[pilihan].setTglLahir(dd,mm,yy);
							} else if (sel == "4"){
							string pendidikan;
							cout<<"masukkan pendidikan yang baru : ";
							cin.ignore();
							getline(cin,pendidikan);
							recDosen[pilihan].setPendidikan(pendidikan);
							} else {
							system("@cls || clear");
							goto inspectDos;
							}
			}
			} else{
			}
		}
			break;

		//Mengakses database vektor Tendik
		case 6:{
			system("@cls || clear");
			cout<<"List Tenaga Pendidik"<<endl;
			int i = 0;
			int pilihan = 0;
			for (i;i<recTendik.size();i++){
				int o=i+1;
				cout<<o;
				cout<<". ";
				cout<<recTendik[i].getNama()<<endl;
			}
			int selection=0;
			cout<< "Pilih Tenaga Pendidik : ";
			cin>>pilihan;
			pilihan = pilihan-1;

			inspectTd:
			system("@cls || clear");
			cout<<"Data Tenaga Pendidik"<<endl;
			cout<<"=================="<<endl;
			cout<<"1. Nama Tenaga Pendidik : ";
			cout<<recTendik[pilihan].getNama()<<endl;
			cout<<"2. Id : ";
			cout<<recTendik[pilihan].getId()<<endl;
			cout<<"3. NPP Tenaga Pendidik :";
			cout<<recTendik[pilihan].getNPP()<<endl;
			cout<<"4. Unit :";
			cout<<recTendik[pilihan].getUnit()<<endl;
			cout<<"5. Tanggal Lahir : ";
			cout<<recTendik[pilihan].getTglLahir(); cout<<" ";
			cout<<bulanConverter(recTendik[pilihan].getBulanLahir());cout<<" ";
			cout<<recTendik[pilihan].getTahunLahir()<<endl;
			
			cout<<"Press 1 to edit biodata "<<endl<<"Press 2 to exit";
			cin>>selection;
			int mode=0;

			if (selection == 1) {
				mode=1;
			editTd:
			while (mode=1){
				system("@cls || clear");
			cout<<"Edit Data Dosen"<<endl;
			cout<<"=================="<<endl;
			cout<<"1. Nama Tenaga Pendidik : ";
			cout<<recTendik[pilihan].getNama()<<endl;
			cout<<"2. NPP Tenaga Pendidik :";
			cout<<recTendik[pilihan].getNPP()<<endl;
			cout<<"3. Unit :";
			cout<<recTendik[pilihan].getUnit()<<endl;
			cout<<"4. Tanggal Lahir : ";
			cout<<recTendik[pilihan].getTglLahir(); cout<<" ";
			cout<<bulanConverter(recTendik[pilihan].getBulanLahir());cout<<" ";
			cout<<recTendik[pilihan].getTahunLahir()<<endl;

			string sel;
			cout<<"Pilih data yang mau di edit : ";
							cin>>sel;
							if (sel == "1"){
							string nama;
							cout<<"Masukkan nama yang baru : ";
							cin.ignore();
							getline(cin,nama);
							recTendik[pilihan].setNama(nama);
							} else if (sel == "2"){
							string npp;
							cout<<"Masukkan npp yang baru : ";
							cin.ignore();
							getline(cin,npp);
							if (!isNumber(npp)){
system("@cls || clear");
cout<<"NRP yang anda masukkan salah";
cout<<endl; cout<<endl; cout<<endl; cout<<endl;
cout<<"Tekan enter untuk kembali ke awal"<<endl;
cin.ignore();
cin.ignore();
	break;
}
							recTendik[pilihan].setNPP(npp);
							} else if (sel == "3"){
							string unit;
							cout<<"Masukkan unit yang baru :";
							cin.ignore();
							getline(cin,unit);
							recTendik[pilihan].setUnit(unit);
							} else if (sel == "4"){
							int dd,mm,yy;
							cout<<"masukkan tanggal yang baru : ";
							cin>>dd;
							if (cin.fail())	
{cin.clear();cin.ignore();cin.ignore();break;}
							cout<<"masukkan bulan yang baru : ";
							cin>>mm;
							if (cin.fail())	
{cin.clear();cin.ignore();cin.ignore();break;}
							cout<<"masukkan tahun yang baru : ";
							cin>>yy;
							if (cin.fail())	
{cin.clear();cin.ignore();cin.ignore();break;}
							recTendik[pilihan].setTglLahir(dd,mm,yy);
							} else {
							system("@cls || clear");
							goto inspectTd;
							}
			}
			} else{
			}
		}
			break;

		//mengelola matkul
		case 7:{
			if (recMatkul.empty()){
				pilihantujuh:
				system("@cls || clear");
				int menupilihanmatkul;
				cout<<"Tidak ada mata kuliah terdaftar";
				cout<<endl;cout<<endl;
				cout<<"Tekan 1 untuk tambah matkul"<<endl;
				cout<<"Tekan 2 untuk kembali menu utama"<<endl;
				cin>>menupilihanmatkul;if (cin.fail())
			{cin.clear();cin.ignore();cin.ignore();}

				if (menupilihanmatkul == 1){
					system("@cls || clear");
					cout<< "Menu menambah mata kuliah"<<endl;
					cout<< "========================"<<endl;
					string namamatkul,dosenpengajar,deptpengurus;
					int jumlah_sks,jumlahkelas,kuotaterdaftar,minimalSemester;
					int siswaterdaftar = 0;
					int urutan = recMatkul.size() + 1;
					cin.ignore();
					cout<<"masukkan nama matkul : ";
					getline(cin,namamatkul);
					cout<<"masukkan departemen pengurus matkul : ";
					getline(cin,deptpengurus);
					cout<<"masukkan nama dosen pengajar : ";
					getline(cin,dosenpengajar);
					cout<<"masukkan jumlah SKS : ";
					cin>>jumlah_sks;if (jumlah_sks >5 || jumlah_sks < 0){cout<<"Besar yang anda masukkan salah!!"; cin.ignore();cin.ignore(); break;}if (cin.fail()){cin.clear();cin.ignore();cin.ignore();}
					cout<<"masukkan jumlah kelas tersedia : ";
					cin>>jumlahkelas;if (cin.fail()){cin.clear();cin.ignore();cin.ignore();}
					cout<<"masukkan jumlah kuota mahasiswa mata kuliah : ";
					cin>>kuotaterdaftar;if (cin.fail()){cin.clear();cin.ignore();cin.ignore();}
					cout<<"masukkan jumlah minimal semester : ";
					cin>>minimalSemester; if (minimalSemester >10 || minimalSemester<0){cout<<"Besar yang anda masukkan salah!!"; cin.ignore();cin.ignore(); break;}if (cin.fail()){cin.clear();cin.ignore();cin.ignore();}
					matkul newMatkul(namamatkul, dosenpengajar, deptpengurus, jumlah_sks,jumlahkelas,kuotaterdaftar,minimalSemester,siswaterdaftar);
					recMatkul.push_back(newMatkul);
					break; 
				} else if (menupilihanmatkul == 2)
				{
					system("@cls || clear");
					break;
				} else {
					system("@cls || clear");
					cout<<"pilihan anda tidak valid";
					goto pilihantujuh;
				}
				
			} else {
				system("@cls || clear");
				cout<<"List Mata Kuliah"<<endl;
				int i = 0;
				int pilihan = 0;
				for (i;i<recMatkul.size();i++){
					int o=i+1;
					cout<<o;
					cout<<". ";
					cout<<recMatkul[i].getNama()<<endl;
				}
				temp = recMatkul.size()+2;
				cout<<"Pilih angka matkul untuk edit"<<endl;
				cout<<"Masukkan angka setelah matkul terakhir + 1 untuk menambah matkul"<<endl;
				cout<<"Masuskkan angka setelah matkul terakhir + 2 untuk keluar"<<endl;
				cin>>pilihan; 
				pilihan = pilihan-1;
				if (pilihan == recMatkul.size()){
					system("@cls || clear");
					cout<< "Menu menambah mata kuliah"<<endl;
					cout<< "========================"<<endl;
					string namamatkul,dosenpengajar,deptpengurus;
					int jumlah_sks,jumlahkelas,kuotaterdaftar,minimalSemester;
					int siswaterdaftar = 0;
					int urutan = recMatkul.size() + 1;
					cin.ignore();
					cout<<"masukkan nama matkul : ";
					getline(cin,namamatkul);
					cout<<"masukkan departemen pengurus matkul : ";
					getline(cin,deptpengurus);
					cout<<"masukkan nama dosen pengajar : ";
					getline(cin,dosenpengajar);
					cout<<"masukkan jumlah SKS : ";
					cin>>jumlah_sks;if (jumlah_sks >5){cout<<"Besar yang anda masukkan salah!!"; cin.ignore();cin.ignore(); break;}if (cin.fail()){cin.clear();cin.ignore();cin.ignore();}
					cout<<"masukkan jumlah kelas tersedia : ";
					cin>>jumlahkelas;if (cin.fail()){cin.clear();cin.ignore();cin.ignore();}
					cout<<"masukkan jumlah kuota mahasiswa mata kuliah : ";
					cin>>kuotaterdaftar;if (cin.fail()){cin.clear();cin.ignore();cin.ignore();}
					cout<<"masukkan jumlah minimal semester : ";
					cin>>minimalSemester; if (minimalSemester >10){cout<<"Besar yang anda masukkan salah!!"; cin.ignore();cin.ignore(); break;}if (cin.fail()){cin.clear();cin.ignore();cin.ignore();}
					matkul newMatkul(namamatkul, dosenpengajar, deptpengurus, jumlah_sks,jumlahkelas,kuotaterdaftar,minimalSemester,siswaterdaftar);
					recMatkul.push_back(newMatkul);
					break;break;
				} else if (pilihan>0 && pilihan<= recMatkul.size()){
					inspectMatkul:
					system("@cls || clear");
					int selection=0;
					cout<<"Data Mata Kuliah"<<endl;
					cout<<"=================="<<endl;
					cout<<"1. Nama mata kuliah : ";
					cout<<recMatkul[pilihan].getNama()<<endl;
					cout<<"2. Departemen pengurus : ";
					cout<<recMatkul[pilihan].getDeptPeng()<<endl;
					cout<<"3. Dosen pengurus :";
					cout<<recMatkul[pilihan].getDosen()<<endl;
					cout<<"4. Jumlah SKS :";
					cout<<recMatkul[pilihan].getJumlahSKS()<<endl;
					cout<<"5. Minimal semester :";
					cout<<recMatkul[pilihan].getminimalSemester()<<endl;
					cout<<"6. Jumlah kelas tersedia :";
					cout<<recMatkul[pilihan].getJumlahkls()<<endl;
					cout<<"7. Jumlah kuota siswa : ";
					cout<<recMatkul[pilihan].getKuotasiswa()<<endl;
					cout<<"8. Jumlah siswa terdaftar :  ";
					cout<<recMatkul[pilihan].getjumlahsiswaterdaftar()<<endl;
					
					cout<<"Press 1 to edit data mata kuliah "<<endl<<"Press 2 to exit";
					cin>>selection; if (cin.fail()){cin.clear();cin.ignore();cin.ignore();}
					int mode=0;
					if (selection > 0 && selection < 8){
						mode = 1;
						int sel = 0;
						cout<<endl;cout<<endl;
						cout<<"pilih data yang ingin diedit : ";
						cin>> sel;
						if (sel == 1){
							string newnama;
							cin.ignore();
							cout<<"masukkan nama baru : "; getline(cin,newnama);
							recMatkul[pilihan].setNama(newnama);
							goto inspectMatkul;
						} else if(sel == 2){
							string newdeptpeng;
							cin.ignore();
							cout<<"masukkan pengurus departemen baru : "; getline(cin,newdeptpeng);
							recMatkul[pilihan].setDeptPeng(newdeptpeng);
							goto inspectMatkul;
						} else if(sel == 3){
							string newDosenpengurus;
							cin.ignore();
							cout<<"masukkan dosen pengurus pengurus : "; getline(cin,newDosenpengurus);
							recMatkul[pilihan].setDosen(newDosenpengurus);
							goto inspectMatkul;
						} else if(sel == 4){
							int newsksamount;
							cin.ignore();
							cout<<"masukkan pengurus departemen baru : "; cin>>newsksamount; if (cin.fail()){cin.clear();cin.ignore();cin.ignore();}
							recMatkul[pilihan].setJumlahSKS(newsksamount); 
							goto inspectMatkul;
						} else if(sel == 5){
							int newMinSEm;
							cin.ignore();
							cout<<"masukkan minimal semester baru : "; cin>>newMinSEm; if (cin.fail()){cin.clear();cin.ignore();cin.ignore();}
							recMatkul[pilihan].setminimalSemester(newMinSEm); 
							goto inspectMatkul;
						} else if(sel == 6){
							int newJumlahkelas;
							cin.ignore();
							cout<<"masukkan jumlah kelas baru : "; cin>>newJumlahkelas; if (cin.fail()){cin.clear();cin.ignore();cin.ignore();}
							recMatkul[pilihan].setJumlahkls(newJumlahkelas); 
							goto inspectMatkul;
						}else if(sel == 7){
							int newsksamount;
							cin.ignore();
							cout<<"masukkan pengurus departemen baru : "; cin>>newsksamount; if (cin.fail()){cin.clear();cin.ignore();cin.ignore();}
							recMatkul[pilihan].setJumlahSKS(newsksamount); 
							goto inspectMatkul;
						} else {
							goto inspectMatkul;
						}
					} else if(pilihan == temp) {
						break;
					} else {
						cout<<"Pilihan anda tidak valid"<< endl; cin.ignore(); cin.ignore();
						goto admin;
					}
				}

			}
		}
		//Keluar dari login admin
		case 8:{
			goto start;
		}
			break;
		}
	}

//Looping utama menu dari dosen access
	while (temp == 2){
		int menu_terpilih = 0;
		string dosenterpilih;
		dosenterpilih = recDosen[urutanlog].getNama();
		landingD:
		system("@cls||clear");
		cout<<"Selamat datang "<<dosenterpilih<<endl;
		cout << "Data statistik:" << endl;
		cout << "  1. Jumlah Mahasiswa             : " << recMhs.size() << " Mahasiswa" << endl;
		cout << "  2. Jumlah Dosen                 : " << recDosen.size() << " Dosen" << endl;
		cout << "  3. Jumlah Tenaga Kependidikan   : " << recTendik.size() << " Tendik" << endl;
		cout << "Menu: " << endl;
		cout << "  1. Tampilkan semua Mahasiswa" << endl;
		cout << "  2. Tampilkan Biodata saya" << endl;
		cout << "  3. Log Out" <<endl;
		cin>>menu_terpilih;
		if (cin.fail())
			{cin.clear();cin.ignore();cin.ignore();}

		switch(menu_terpilih){
		//Menampilkan dan mengakses database vektor mahasiswa
		case 1:{
			system("@cls || clear");
			cout<<"List Mahasiswa"<<endl;
			int i = 0;
			int pilihan = 0;
			for (i;i<recMhs.size();i++){
				int o=i+1;
				cout<<o;
				cout<<". ";
				cout<<recMhs[i].getNama()<<endl;
			}
			int selection;
			cout<< "Pilih mahasiswa : ";
			cin>>pilihan;
			if (cin.fail())
			{cin.clear();cin.ignore();cin.ignore();}

			pilihan = pilihan-1;

			inspectionD:
			system("@cls || clear");
			cout<<"Data Mahasiswa"<<endl;
			cout<<"=================="<<endl;
			cout<<"1. Nama Mahasiswa : ";
			cout<<recMhs[pilihan].getNama()<<endl;
			cout<<"2. Id : ";
			cout<<recMhs[pilihan].getId()<<endl;
			cout<<"3. NRP Mahasiswa :";
			cout<<recMhs[pilihan].getNRP()<<endl;
			cout<<"4. Departemen :";
			cout<<recMhs[pilihan].getDepartemen()<<endl;
			cout<<"5. Tanggal Lahir : ";
			cout<<recMhs[pilihan].getTglLahir(); cout<<" ";
			cout<<bulanConverter(recMhs[pilihan].getBulanLahir());cout<<" ";
			cout<<recMhs[pilihan].getTahunLahir()<<endl;
			cout<<"6. Tahun Masuk : ";
			cout<<recMhs[pilihan].getTahunmasuk()<<endl;
			cout<<"7. Semester ke: ";
			cout<<recMhs[pilihan].getTahunmasuk()<<endl;
			cout<<endl; cout<<endl; cout<<endl;
			cout<<"Akademik"<<endl<<"================="<<endl;
			cout<<"8. IPK : ";
			cout<<recMhs[pilihan].getIPK()<<endl;
			cout<<"9.Semester ke : ";
			cout<<recMhs[pilihan].getSemester()<<endl;
			cout<<"10. SKS Lulus : ";
			cout<<recMhs[pilihan].getSKSLulus()<<endl;
			cout<<"11. Tahun Masuk : ";
			cout<<recMhs[pilihan].getTahunmasuk()<<endl;
			cout<<endl; cout<<endl; cout<<endl; cout<<endl;
			cout<<"Press 1 to input IPS "<<endl << "Press 2 to exit";
			cin>>selection;
			if (cin.fail())
			{cin.clear();cin.ignore();cin.ignore();}

			if (selection == 1){
				IPSD:
					system("@cls || clear");
					int semester,choice;
					cout<<"Edit Akademik siswa :"<< endl;
					cout<<"====================="<<endl;
					cout<<"Semester ke : "<<recMhs[pilihan].getSemester()<<endl;
					cout<<"Nilai IPK : "<<recMhs[pilihan].getIPK()<<endl;
					for (float i=0;i<recMhs[pilihan].getSemester();i++){
							cout<<i+1<<". ";
							cout<<"Semester "<<i+1<<": ";
							cout<<recMhs[pilihan].getIPS(i)<<endl;
					}
					cout<<endl;cout<<endl;

					cout<<"press 1 to set IPS"<<endl<<"press 2 to edit Semester"<<endl<<"press 0 to exit";
					cin>>choice;
					if (cin.fail())
{cin.clear();cin.ignore();cin.ignore();break;}
					float ips;
					if (choice == 1){
						cout<<endl;cout<<endl;
						for (unsigned i=0;i<recMhs[pilihan].getSemester();i++){
							cout<<i+1<<". ";
							cout<<"Semester "<<i+1<<": ";
							cin>>ips;
							if (cin.fail())
{cin.clear();cin.ignore();cin.ignore();break;}
							recMhs[pilihan].setIPS(i,ips);
						
						}
					goto IPSD;
					} else if (choice == 0) {goto inspectionD;}
					else if (choice == 2) {
						float newsems;
						cout<<"masukkan semester baru : ";
						cin>>newsems;
						if (cin.fail())
{cin.clear();cin.ignore();cin.ignore();break;}
						recMhs[pilihan].setSemester(newsems);
						goto IPSD;
			} else if (selection == 2){
				goto landingD;
			}
			
		} 
		}break;
		
		//Menampilkan Biodata dosen itu sendiri
		case 2:{
			int selection;
			inspectDosD:
			system("@cls || clear");
			cout<<"Data Dosen"<<endl;
			cout<<"=================="<<endl;
			cout<<"1. Nama Dosen : ";
			cout<<recDosen[urutanlog].getNama()<<endl;
			cout<<"2. Id : ";
			cout<<recDosen[urutanlog].getId()<<endl;
			cout<<"3. NPP Dosen :";
			cout<<recDosen[urutanlog].getNPP()<<endl;
			cout<<"4. Departemen :";
			cout<<recDosen[urutanlog].getDept()<<endl;
			cout<<"5. Pendidikan :";
			cout<<recDosen[urutanlog].getPendidikan()<<endl;
			cout<<"6. Tanggal Lahir : ";
			cout<<recDosen[urutanlog].getTglLahir(); cout<<" ";
			cout<<bulanConverter(recDosen[urutanlog].getBulanLahir());cout<<" ";
			cout<<recDosen[urutanlog].getTahunLahir()<<endl;
			
			cout<<"Press 1 to edit biodata "<<endl<<"Press 2 to exit";
			cin>>selection;
			if (cin.fail())
			{cin.clear();cin.ignore();cin.ignore();}
			int mode=0;

			if (selection == 1) {
				mode=1;
			editdosD:
			while (mode=1){
				system("@cls || clear");
			cout<<"Edit Data Dosen"<<endl;
			cout<<"=================="<<endl;
			cout<<"1. Nama Dosen : ";
			cout<<recDosen[urutanlog].getNama()<<endl;
			cout<<"2. NPP Dossen :";
			cout<<recDosen[urutanlog].getNPP()<<endl;
			cout<<"3. Departemen :";
			cout<<recDosen[urutanlog].getDept()<<endl;
			cout<<"4. Pendidikan :";
			cout<<recDosen[urutanlog].getPendidikan()<<endl;
			cout<<"5. Tanggal Lahir : ";
			cout<<recDosen[urutanlog].getTglLahir(); cout<<" ";
			cout<<bulanConverter(recDosen[urutanlog].getBulanLahir());cout<<" ";
			cout<<recDosen[urutanlog].getTahunLahir()<<endl;

			string sel;
			cout<<"Pilih data yang mau di edit : ";
							cin>>sel;
							if (sel == "1"){
							string nama;
							cout<<"Masukkan nama yang baru : ";
							cin.ignore();
							getline(cin,nama);
							recDosen[urutanlog].setNama(nama);
							} else if (sel == "2"){
							string npp;
							cout<<"Masukkan npp yang baru : ";
							cin.ignore();
							getline(cin,npp);
							if (!isNumber(npp)){
system("@cls || clear");
cout<<"NRP yang anda masukkan salah";
cout<<endl; cout<<endl; cout<<endl; cout<<endl;
cout<<"Tekan enter untuk kembali ke awal"<<endl;
cin.ignore();
cin.ignore();
break;
}
							recDosen[urutanlog].setNPP(npp);
							} else if (sel == "3"){
							string departemen;
							cout<<"Masukkan departemen yang baru :";
							cin.ignore();
							getline(cin,departemen);
							recDosen[urutanlog].setDept(departemen);
							} else if (sel == "5"){
							int dd,mm,yy;
							cout<<"masukkan tanggal yang baru : ";
							cin>>dd;
							if (cin.fail())
{cin.clear();cin.ignore();cin.ignore();break;}
							cout<<"masukkan bulan yang baru : ";
							cin>>mm;
							if (cin.fail())
{cin.clear();cin.ignore();cin.ignore();break;}
							cout<<"masukkan tahun yang baru : ";
							cin>>yy;
							if (cin.fail())
{cin.clear();cin.ignore();cin.ignore();break;}
if (!isValidDate(dd,mm,yy)){
system("@cls || clear");
cout<<"Tanggal yang anda masukkan tidak valid"<<endl;
cout<<endl; cout<<endl; cout<<endl; cout<<endl;
cout<<"Tekan enter untuk kembali ke awal"<<endl;
cin.ignore();
cin.ignore();
break;
}
							recDosen[urutanlog].setTglLahir(dd,mm,yy);
							} else if (sel == "4"){
							string pendidikan;
							cout<<"masukkan pendidikan yang baru : ";
							cin.ignore();
							getline(cin,pendidikan);
							recDosen[urutanlog].setPendidikan(pendidikan);
							} else {
							system("@cls || clear");
							goto inspectDosD;
							}
			}
			} else{
			}
			}
		break;
		
		//Keluar dari Login dosen
		case 3:{
		goto start;
		}
		break;
		}
	}

//Looping utama dari mahasiswa access
	while (temp == 3){
		int menu_terpilih = 0;
		string mahasiswaterpilih;
		mahasiswaterpilih = recMhs[urutanlog].getNama();
		landingM:
		system("@cls||clear");
		cout<<"Selamat datang "<<mahasiswaterpilih<<endl;
		cout << "Data statistik:" << endl;
		cout << "  1. Jumlah Mahasiswa             : " << recMhs.size() << " Mahasiswa" << endl;
		cout << "  2. Jumlah Dosen                 : " << recDosen.size() << " Dosen" << endl;
		cout << "  3. Jumlah Tenaga Kependidikan   : " << recTendik.size() << " Tendik" << endl;
		cout << "Menu: " << endl;
		cout << "  1. Tampilkan Biodata saya" << endl;
		cout << "  2. Daftar Matkul Saya" <<  endl;
		cout << "  3. Log Out" <<endl;

		cout << "  pilihan nomor 2 masih dalam pengembangan" <<endl;
		cin>>menu_terpilih;

		if (cin.fail())
			{cin.clear();cin.ignore();cin.ignore();}

		switch (menu_terpilih){
			//Mengedit Biodata Mahasiswa
			case 1: {
			inspectionM:
			int selection = 0;
			system("@cls || clear");
			cout<<"Data Mahasiswa"<<endl;
			cout<<"=================="<<endl;
			cout<<"1. Nama Mahasiswa : ";
			cout<<recMhs[urutanlog].getNama()<<endl;
			cout<<"2. Id : ";
			cout<<recMhs[urutanlog].getId()<<endl;
			cout<<"3. NRP Mahasiswa :";
			cout<<recMhs[urutanlog].getNRP()<<endl;
			cout<<"4. Departemen :";
			cout<<recMhs[urutanlog].getDepartemen()<<endl;
			cout<<"5. Tanggal Lahir : ";
			cout<<recMhs[urutanlog].getTglLahir(); cout<<" ";
			cout<<bulanConverter(recMhs[urutanlog].getBulanLahir());cout<<" ";
			cout<<recMhs[urutanlog].getTahunLahir()<<endl;
			cout<<"6. Tahun Masuk : ";
			cout<<recMhs[urutanlog].getTahunmasuk()<<endl;
			cout<<"7. Semester ke: ";
			cout<<recMhs[urutanlog].getTahunmasuk()<<endl;
			cout<<endl; cout<<endl; cout<<endl;
			cout<<"Akademik"<<endl<<"================="<<endl;
			cout<<"8. IPK : ";
			cout<<recMhs[urutanlog].getIPK()<<endl;
			cout<<"9.Semester ke : ";
			cout<<recMhs[urutanlog].getSemester()<<endl;
			cout<<"10. SKS Lulus : ";
			cout<<recMhs[urutanlog].getSKSLulus()<<endl;
			cout<<"11. Tahun Masuk : ";
			cout<<recMhs[urutanlog].getTahunmasuk()<<endl;
			cout<<endl; cout<<endl; cout<<endl; cout<<endl;
			cout<<"Press 1 to edit Biodata "<<endl << "Press 2 to see IPS" <<endl<<"Press 3 to exit";
			cin>>selection;
			int mode=0;

			//pilihan untuk mengedit biodata
			if (selection == 1){
				mode = 1;
						while (mode == 1){
							system("@cls || clear");
							biodatam:
							cout<<"Edit Biodata"<<endl;
							cout<<"=================="<<endl;
							cout<<"1. Nama Mahasiswa : ";
							cout<<recMhs[urutanlog].getNama()<<endl;
							cout<<"2. Tanggal Lahir : ";
							cout<<recMhs[urutanlog].getTglLahir(); cout<<" ";
							cout<<bulanConverter(recMhs[urutanlog].getBulanLahir());cout<<" ";
							cout<<recMhs[urutanlog].getTahunLahir()<<endl;
							
							string sel;
							cout<<"Pilih data yang mau di edit : ";
							cin>>sel;
							if (sel == "1"){
							string nama;
							cout<<"Masukkan nama yang baru : ";
							cin.ignore();
							getline(cin,nama);
							recMhs[urutanlog].setNama(nama);
							}  else if (sel == "2"){
							int dd,mm,yy;
							cout<<"masukkan tanggal yang baru : ";
							cin>>dd;
							if (cin.fail())
{cin.clear();cin.ignore();cin.ignore();break;}
							cout<<"masukkan bulan yang baru : ";
							cin>>mm;
							if (cin.fail())
{cin.clear();cin.ignore();cin.ignore();break;}
							cout<<"masukkan tahun yang baru : ";
							cin>>yy;
							if (cin.fail())
{cin.clear();cin.ignore();cin.ignore();break;}

if (!isValidDate(dd,mm,yy)){
system("@cls || clear");
cout<<"Tanggal yang anda masukkan tidak valid"<<endl;
cout<<endl; cout<<endl; cout<<endl; cout<<endl;
cout<<"Tekan enter untuk kembali ke awal"<<endl;
cin.ignore();
cin.ignore();
break;
}
							recMhs[urutanlog].setTglLahir(dd,mm,yy);
							}  else {
							system("@cls || clear");
							goto inspectionM;
							}
						}
			} 
			//Pilihan untuk melihat IPS
			else if (selection == 2){
				IPSM:
					system("@cls || clear");
					int semester,choice;
					cout<<"Edit Akademik siswa :"<< endl;
					cout<<"====================="<<endl;
					cout<<"Semester ke : "<<recMhs[urutanlog].getSemester()<<endl;
					cout<<"Nilai IPK : "<<recMhs[urutanlog].getIPK()<<endl;
					for (float i=0;i<recMhs[urutanlog].getSemester();i++){
							cout<<i+1<<". ";
							cout<<"Semester "<<i+1<<": ";
							cout<<recMhs[urutanlog].getIPS(i)<<endl;
					}
					cout<<endl;cout<<endl;
					cout<<"Press 0 to exit";
					cin>>choice;

					if (choice == 0){goto biodatam;}

			}

			}break;

			/*
			case 2:{
				if (recMhs[urutanlog].getskssemesterini() == 0){
					system("@cls || clear");
					cout<<"List Mata Kuliah anda"<<endl;
					cout<<"====================="<<endl;
					cout<<"Anda belum mengambil mata kuliah semester ini"<<endl;cout<<endl;cout<<endl;
					cout<<"Tekan 1 untuk mengambil mata kuliah"<<endl;cout<<"tekan 2 untuk kembali"<<endl;
					int pilihan = 0;
					if (pilihan == 1){
						system("@cls || clear");
						cout<<"List Mata Kuliah tersedia"<<endl;
						cout<<"====================="<<endl;
						if (recMhs.empty()){
							cout<<"tidak ada mata kuliah tersedia"<<endl;
							cin.ignore();cin.ignore();
							break;
						}else {
							int i = 0;
							for (i;i<recMatkul.size();i++){
								int o=i+1;
								cout<<o;
								cout<<". ";
								cout<<recMatkul[i].getNama()<<endl;
							}
							int choice = 0;
							cout<<"Pilih mata kuliah yang anda ingin masuk"<<endl;
							cin>>choice;
							if (recMhs[urutanlog].getSemester() >= recMatkul[choice-1].getminimalSemester() && recMatkul[choice-1].getKuotasiswa() < recMatkul[choice-1].getmahasiswaterdaftar() && recMhs[urutanlog].getskssemesterini() < 24){
								system("@cls || clear");
								recMatkul[choice-1].addmahasiswaterdaftar();
								int temp = recMhs[urutanlog].getskssemesterini() + recMatkul[choice-1].getJumlahSKS();
								recMhs[urutanlog].setskssemesterini(temp);
								cout<<"Selamat anda diterima di mata kuliah ini"<<endl;
								cin.ignore(); cin.ignore(); break;
							} else {
								system("@cls || clear");
								cout<<"Maaf anda tidak memenuhi kelas ini"<<endl;
								cin.ignore(); cin.ignore(); break;
							}
						}
					}
				}
				else {
					system("@cls || clear");
					cout<<"Halooo"<<endl;
					cin.ignore(); cin.ignore(); break;
				}
			}*/
			//Keluar dari login mahasiswa
			case 3: {
				goto start;
			}break;
		}
	}

//Looping utama dari Tendik access
	while (temp == 4){
		int menu_terpilih = 0;
		string tendikterpilih;
		tendikterpilih = recTendik[urutanlog].getNama();
		landingT:
		system("@cls||clear");
		cout<<"Selamat datang "<<tendikterpilih<<endl;
		cout << "Data statistik:" << endl;
		cout << "  1. Jumlah Mahasiswa             : " << recMhs.size() << " Mahasiswa" << endl;
		cout << "  2. Jumlah Dosen                 : " << recDosen.size() << " Dosen" << endl;
		cout << "  3. Jumlah Tenaga Kependidikan   : " << recTendik.size() << " Tendik" << endl;
		cout << "  Menu: " << endl;
		cout << "  1. Tampilkan Biodata saya" << endl;
		cout << "   2. Log Out" <<endl;
		cin  >> menu_terpilih;
		if (cin.fail())
			{cin.clear();cin.ignore();cin.ignore();}

		switch (menu_terpilih){
			//Menampilkan biodata Tendik
			case 1: {
			inspectionT:
			int selection = 0;
			system("@cls || clear");
			cout<<"Data Tenaga Pendidik"<<endl;
			cout<<"=================="<<endl;
			cout<<"1. Nama Tenaga Pendidik : ";
			cout<<recTendik[urutanlog].getNama()<<endl;
			cout<<"2. Id : ";
			cout<<recTendik[urutanlog].getId()<<endl;
			cout<<"3. NPP Tenaga Pendidik :";
			cout<<recTendik[urutanlog].getNPP()<<endl;
			cout<<"4. Unit :";
			cout<<recTendik[urutanlog].getUnit()<<endl;
			cout<<"5. Tanggal Lahir : ";
			cout<<recTendik[urutanlog].getTglLahir(); cout<<" ";
			cout<<bulanConverter(recTendik[urutanlog].getBulanLahir());cout<<" ";
			cout<<recTendik[urutanlog].getTahunLahir()<<endl;
			
			cout<<"Press 1 to edit biodata "<<endl<<"Press 2 to exit";
			cin>>selection;
			int mode=0;

			if (selection == 1) {
				mode=1;
			//editTd:
			while (mode=1){
				system("@cls || clear");
			cout<<"Edit Data Dosen"<<endl;
			cout<<"=================="<<endl;
			cout<<"1. Nama Tenaga Pendidik : ";
			cout<<recTendik[urutanlog].getNama()<<endl;
			cout<<"2. NPP Tenaga Pendidik :";
			cout<<recTendik[urutanlog].getNPP()<<endl;
			cout<<"3. Unit :";
			cout<<recTendik[urutanlog].getUnit()<<endl;
			cout<<"4. Tanggal Lahir : ";
			cout<<recTendik[urutanlog].getTglLahir(); cout<<" ";
			cout<<bulanConverter(recTendik[urutanlog].getBulanLahir());cout<<" ";
			cout<<recTendik[urutanlog].getTahunLahir()<<endl;

			string sel;
			cout<<"Pilih data yang mau di edit : ";
							cin>>sel;
							if (sel == "1"){
							string nama;
							cout<<"Masukkan nama yang baru : ";
							cin.ignore();
							getline(cin,nama);
							recTendik[urutanlog].setNama(nama);
							} else if (sel == "2"){
							string npp;
							cout<<"Masukkan npp yang baru : ";
							cin.ignore();
							getline(cin,npp);
							if (!isNumber(npp)){
system("@cls || clear");
cout<<"NRP yang anda masukkan salah";
cout<<endl; cout<<endl; cout<<endl; cout<<endl;
cout<<"Tekan enter untuk kembali ke awal"<<endl;
cin.ignore();
cin.ignore();
break;
}
							recTendik[urutanlog].setNPP(npp);
							} else if (sel == "3"){
							string unit;
							cout<<"Masukkan unit yang baru :";
							cin.ignore();
							getline(cin,unit);
							recTendik[urutanlog].setUnit(unit);
							} else if (sel == "4"){
							int dd,mm,yy;
							cout<<"masukkan tanggal yang baru : ";
							cin>>dd;
							if (cin.fail())
{cin.clear();cin.ignore();cin.ignore();break;}
							cout<<"masukkan bulan yang baru : ";
							cin>>mm;
							if (cin.fail())
{cin.clear();cin.ignore();cin.ignore();break;}
							cout<<"masukkan tahun yang baru : ";
							cin>>yy;
							if (cin.fail())
{cin.clear();cin.ignore();cin.ignore();break;}
if (!isValidDate(dd,mm,yy)){
system("@cls || clear");
cout<<"Tanggal yang anda masukkan tidak valid"<<endl;
cout<<endl; cout<<endl; cout<<endl; cout<<endl;
cout<<"Tekan enter untuk kembali ke awal"<<endl;
cin.ignore();
cin.ignore();
break;
}
							recTendik[urutanlog].setTglLahir(dd,mm,yy);
							} else {
							system("@cls || clear");
							goto inspectionT;
							}
			}
			} else{
			}

			}break;

			//Keluar dari log in Tendik
			case 2: {
				goto start;
			}break;
		}
	}

	return 0;
	
}