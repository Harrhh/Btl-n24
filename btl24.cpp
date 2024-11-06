#include <iostream>
#include <string>

using namespace std;

struct SinhVien 
{
    long long mssv;
    string ten;
    SinhVien* next;
};

struct Phong 
{
    int sophong;
    SinhVien* svhead;
    SinhVien* svtail;
    Phong* next;
    
    Phong(){
    	svhead = svtail = NULL;
	}
    ~Phong(){
    	delete svhead;
    	delete svtail;
    	
	}
	bool findMaSV(long long mssv);
	void addSinhVien(SinhVien* sv);
	void printSinhVien();
	void deleteSinhVien();
};
void Phong::addSinhVien(SinhVien* sv){
	if(svhead == NULL){
		this->svhead = this->svtail = sv;
	}else{
		this->svtail->next = sv;
		this->svtail = sv;
	}
}
void Phong::printSinhVien(){
	SinhVien* sv = this->svhead;
	while(sv != NULL){
		cout<<"-Ten sinh vien: "<<sv->ten<<"\t\t\tMSSV: "<<sv->mssv;
		cout<<"\n";
		sv = sv->next;
	}
	system("pause");
}
void Phong::deleteSinhVien(){
	long long mssv;
	cout<<"Nhap mssv cua sinh vien can xoa: "; cin>>mssv;
		SinhVien* sv = this->svhead;
		while(sv != NULL){
			SinhVien* svnext = sv->next;
			if(sv->mssv == mssv){
				svhead = svnext;
				delete sv;
				return;
			}
			if(svnext == NULL){
				cout<<"\nKhong ton tai sinh vien co ma so nay trong phong.";
				system("pause");
				return;
			}
			if(svnext->mssv == mssv){
				sv->next = svnext->next;
				delete svnext;
				return;
			}
		}
		sv = sv->next;
}
bool Phong::findMaSV(long long mssv){
	SinhVien* sv = this->svhead;
		while(sv != NULL){
			if(sv->mssv == mssv) return true;
			sv = sv->next;
		}
		return false;
}
class KTX 
{
private:
	SinhVien* svhead;
	SinhVien* svtail;
    Phong* phead;
    Phong* ptail;
public:
	KTX();
	~KTX();
	Phong* createNodePhong(int sophong);
	SinhVien* createNodeSV(long long mssv, string ten);
	SinhVien* findMaSV(long long mssv);
	Phong*  findPhong(int sophong);
	void addSinhVien();
	void printSinhVieninKTX();
	void deleteSinhVien();
	void addPhong();
	void printPhong();
	void deletePhong();
	void addSVtoPhong();
	void deleteSVfromPhong();
	void printSVinPhong();
};
KTX::KTX(){
	this->svhead = this->svtail = NULL;
	this->phead = this->ptail = NULL;
}
KTX::~KTX(){
	
}
Phong* KTX::createNodePhong(int sophong){
	Phong* phong = new Phong();
	phong->sophong = sophong;
	phong->next = NULL;
	phong->svhead = NULL;
	phong->svtail = NULL;
	return phong;
}
SinhVien* KTX::createNodeSV(long long mssv, string ten){
	SinhVien* sv = new SinhVien();
	sv->mssv = mssv;
	sv->ten = ten;
	sv->next = NULL;
	return sv;
}
void KTX::addSinhVien(){
	long long mssv;
	string tensv;
	cout<<"Nhap mssv: "; cin>>mssv;
	cout<<"Nhap ten sinh vien: "; cin>>tensv;
	SinhVien* sv = createNodeSV(mssv, tensv);
	
	if(this->svhead == NULL){
		this->svhead = this->svtail = sv;
	}else{
		this->svtail->next = sv;
		this->svtail = sv;
	}
}
void KTX::printSinhVieninKTX(){
	SinhVien* sv = this->svhead;
	if(sv == NULL) cout<<"Khong co sinh vien nao.\n";
	while(sv != NULL){
		cout<<"-Ten sinh vien: "<<sv->ten<<"\t\t\tMSSV: "<<sv->mssv;
		cout<<"\n";
		sv = sv->next;
	}
	system("pause");
}
void KTX::deleteSinhVien(){
	long long mssv;
	cout<<"Nhap mssv cua sinh vien can xoa: "; cin>>mssv;
		SinhVien* sv = this->svhead;
		while(sv!= NULL){
			SinhVien* svnext = sv->next;
			if(sv->mssv == mssv){
				svhead = svnext;
				delete sv;
				return;
			}
			if(sv->next == NULL){
				cout<<"Khong ton tai sinh vien nay.\n";
				system("pause");
				return;
			}
			if(svnext->mssv == mssv){
				sv->next = svnext->next;
				delete svnext;
				return;
			}
			sv = sv->next;
		}
}
SinhVien* KTX::findMaSV(long long mssv){
	SinhVien* sv = this->svhead;
		while(sv != NULL){
			if(sv->mssv == mssv) return sv;
			sv = sv->next;
		}
		return NULL;
}
Phong* KTX::findPhong(int sophong){
	Phong* phong = this->phead;
	while(phong != NULL){
		if(phong->sophong == sophong) return phong;
		phong = phong->next;
	}
	return NULL;
}
void KTX::addPhong(){
	int sophong;
	cout<<"Nhap so phong: "; cin>>sophong;
	Phong* phong = createNodePhong(sophong);
	if(this->phead == NULL){
		this->ptail = this->phead = phong;
	}else{
		this->ptail->next = phong;
		this->ptail = phong;
	}
}
void KTX::printPhong(){
	Phong* phong = this->phead;
	if(phong == NULL) cout<<"\nHien tai khong co phong nao.";
	while(phong != NULL){
		cout<<"Phong: "<<phong->sophong;
		phong = phong->next;
		cout<<"\n";
	}
}
void KTX::printSVinPhong(){
	int sophong;
	cout<<"\nNhap so phong can xem: "; cin>>sophong;
	Phong* phong = this->findPhong(sophong);
	if(phong != NULL){
		cout<<"-Phong: "<<sophong<<"\n";
		phong->printSinhVien();
	}else{
		cout<<"\nKhong ton tai phong nay.";
	}
}
void KTX::deletePhong(){
	int sophong;
	Phong* phong = this->phead;
	cout<<"Nhap so phong can xoa: "; cin>>sophong;
	while(phong != NULL){
		Phong* pnext = phong->next;
		if(phong->sophong == sophong){
			phead = pnext;
			delete phong;
			return;
		}
		if(pnext == NULL){
			cout<<"Khong ton tai phong nay.\n";
			system("pause");
			return;
		}
		if(pnext->sophong == sophong){
			phong->next = pnext->next;
			delete pnext;
			return;
		}
		phong = phong->next;
	}
	
}
void KTX::addSVtoPhong(){
	long long mssv;
	cout<<"Nhap mssv cua sinh vien can them: "; cin>>mssv;
	SinhVien* sv = this->findMaSV(mssv);
	if(sv != NULL){
		int sophong;
		cout<<"Nhap so phong de them: "; cin>>sophong;
		Phong* phong = this->findPhong(sophong);
		if(phong != NULL){
			sv->next = NULL;
			phong->addSinhVien(sv);
		}
	}else{
		cout<<"Sinh vien co mssv nay khong ton tai.";
	}
	cout<<"\n";
	system("pause");
}
void KTX::deleteSVfromPhong(){
	int sophong;
	cout<<"\nNhap phong can tim: "; cin>>sophong;
	Phong* phong = this->findPhong(sophong);
	if(phong != NULL){
		cout<<"\nPhong: "<<sophong<<"\n";
		phong->printSinhVien();
		long long luachon;
		do{
			cout<<"\nNhap mssv cua sinh vien can xoa khoi phong (-1 neu khong can xoa): "; cin>>luachon;
			SinhVien* sv = phong->svhead;
			while(sv != NULL){
				SinhVien* svnext = sv->next;
				if(svnext->mssv == luachon){
					sv->next = svnext->next;
					delete svnext;
					cout<<"Xoa thanh cong.";
					system("pause");
					return;
				}
			}
			cout<<"\nSinh vien co mssv khong co trong phong nay.";
		}while(luachon == -1);
	}else{
		cout<<"\nPhong nay khong ton tai.";
	}
}
int main() 
{
    KTX ktx;
    int luachon;
    do 
	{
		system("cls"); 
    	cout << "Menu:\n";
    	cout << "0. Thoat\n";
        cout << "1. Them phong\n";
        cout << "2. In danh sach phong\n";
        cout << "3. Xoa phong\n";
        cout << "4. Them sinh vien vao phong\n";
        cout << "5. In danh sach sinh vien theo phong\n";
        cout << "6. Xoa sinh vien ra khoi phong\n";
        cout << "7. Them sinh vien\n";
        cout << "8. Xoa sinh vien\n";
        cout << "9. In toan bo danh sach sinh vien\n";
        cout << "Nhap lua chon: ";
        cin >> luachon;

        switch (luachon) 
		{
            case 1:
                ktx.addPhong();
                break;
            case 2:
                ktx.printPhong();
                cout<<"\n";
                system("pause");
                break;
            case 3:
                ktx.deletePhong();
                break;
            case 4:
            	ktx.addSVtoPhong();
            	break;
            case 5:
            	ktx.printSVinPhong();
            	break;
            case 6:
            	ktx.deleteSVfromPhong();
            	break;
            case 7:
            	ktx.addSinhVien();
            	break;
            case 8:
            	ktx.deleteSinhVien();
            	break;
            case 9:
            	ktx.printSinhVieninKTX();
            	break;
            case 0:
                return 0;
        }
    } while (true);

    return 0;
}

