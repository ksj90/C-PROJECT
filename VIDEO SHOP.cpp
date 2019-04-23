/*  C++ VIDEO SHOP ���� ���α׷�  */
#include <iostream>
#include <conio.h>
#include <string.h>
#define MAX_VIDEO 100         //�ִ� ���� 100���� ����
#define MAX_MEMBER 100        //�ִ� ȸ�� 100������ ����
using namespace std;


//��¥�� ǥ���ϴ� Ŭ����
class Date   
{
	
private:
	int year; //��
	int month; //��
	int day; //��
	
public:
	friend class Video;    //DateŬ������ private���� ����ϱ����� Video Ŭ������ friend����
	friend class Member;   //DateŬ������ private���� ����ϱ����� Member Ŭ������ friend����
	Date(){}; //������ �Լ�.
	
	Date(int _year, int _month, int _day) //������ �Լ�.
	{
		year=_year;
		month=_month;
		day=_day;
	}
	
	~Date(){}; //�Ҹ��� �Լ�.
	
	void setYear(int _year); //���� year�� �����Ѵ�.
	void setMonth(int _month); //�� month�� �����Ѵ�.
	void setDay(int _day); //day�� �����Ѵ�.
	
	int getYear(); //������ �����Ѵ�.
	int getMonth(); //���� �����Ѵ�.
	int getDay(); //���� �����Ѵ�.
};

void Date::setYear(int _year)  //���� year�� �����Ѵ�.
{
	year=_year;
}

void Date::setMonth(int _month)  //�� month�� �����Ѵ�.
{
	month=_month;
}

void Date::setDay(int _day)   //day�� �����Ѵ�.
{
	day=_day;
}

int Date::getYear()     //������ �����Ѵ�.
{
	return year;
}

int Date::getMonth()   //���� �����Ѵ�.
{
	return month;
}

int Date::getDay()    //���� �����Ѵ�.
{
	return day;
}


//���� Ŭ���� 
class Video
{

private:
	
	char vname[20]; //�����̸�
	char vID[20]; //������ȣ
	char vactor[20]; //���� �ֿ����
	Date publishDate; //���� �������
	Date rendDate;  //���� �뿩����
	Date inDate;    //���� �ݳ�����
	bool rended;    //���� �뿩�� ���� bool����
	//int membercheck; //���� �Ѵ뿩Ƚ���� ���� ����
	int price;       //���� �뿩������ ���� ����    
	
public:
	
	friend class Member;  //MemberŬ������ friend ����
	Video(){};  //�������Լ� 
	
	Video(char* _vname, char* _vID, char* _vactor, Date& _publishDate)// ������ �Լ�
	{
		strcpy(vname,_vname);
		strcpy(vID, _vID);
		strcpy(vactor, _vactor);
		publishDate=_publishDate;
	}
	
	~Video(){};  //�Ҹ����Լ� 
	
	void Addvideo();         // ��� 1 (�������) 
	void Searchvideo();       // ��� 2 (���� �˻�) 
	void displayvideo();      // ��� 3 (���� ��� ���) 
	void Rentvideo();         // ��� 4 (���� �뿩)
	void Invideo();           // ��� 5 (���� �ݳ�)
	void RentedvideoShow();   // ��� 6 (�뿩���� ������� ���)
	void blacklist();         // ��� 7 (������Ʈ ����)
};


//Member Ŭ���� ���� 
class Member 
{
	
private : 
	
	char name[20]; //ȸ�� �̸�
	char personID[20]; //ȸ�� �ֹε�Ϲ�ȣ
	char address[20]; //ȸ�� �ּ�
	char phonenumber[20]; //ȸ�� �ڵ�����ȣ
	Date initdate; //ȸ�� �������
	int rend;	   //ȸ���� ���� �뿩Ƚ�� 
	Video index;   //�뿩�� ���������� ������ ���� ���� 
	
	
public:
	
	friend class Video; //video Ŭ������ ������ ����
	
	Member(){};  //�������Լ� 
	Member(char *_name, char *_personID , char * _address ,char *_phonenumber,Date& _initdate)//�������Լ�
	{
		strcpy(name, _name);
		strcpy(personID ,_personID);
		strcpy(address, _address);
		strcpy(phonenumber,_phonenumber);
		initdate = _initdate;
	}
	
	~Member(){};  //�Ҹ����Լ�
	
	void Addmember();  // ��� 1 (ȸ�����)
	void modifymember();// ��� 2 (ȸ����������)
	void displaymember();// ��� 3 (ȸ��������)
};


int Video_Num = 0;            // ������� �Էµ� ���� �� 
Video vList[MAX_VIDEO];       // Video ������ ���� �迭
int member_Num = 0;           // ������� �Էµ� ȸ�� �� 
Member mList[MAX_MEMBER];     // Member ������ ���� �迭
FILE *f;                      //���� I/O�� ���� ������ ���� ����


//�����߰� �Լ� ------> vList[MAX_VIDEO] �迭�� ������������
void Video::Addvideo()
{
	cout<<"���� ������ �Է��ϼ���"<<endl;
	
	cout<<"����: ";
	cin>>vList[Video_Num].vname;
	
	cout<<"������ȣ: ";
	cin>>vList[Video_Num].vID;
	
	cout<<"�⿬���: ";
	cin>>vList[Video_Num].vactor;
    
	cout<<"�������: �� �� ��(��, 2005 05 05)";
	cin>>vList[Video_Num].publishDate.year>>vList[Video_Num].publishDate.month>>vList[Video_Num].publishDate.day;
	
	vList[Video_Num].rended = false;    //bool ������ rended ������ ���� �� ������ ���� �뿩��������
	                                    //�뿩 ��(�뿩�Ұ�)���� �Ǵ� false �� �뿩���� , true �� �뿩�Ұ�
	cout<<"�뿩����: " ;
	cin>>vList[Video_Num].price;
	
    Video_Num++; // ���� �ε��� 1 ���� 
}


//���� �˻� �Լ� ->�����̸��� �Է¹޾� vList[MAX_VIDEO] �迭�� ����� �����̸��� ���
void Video::Searchvideo()
{
	int i;
	
	int Search_Result = 0;  // 0:  �˻�����,  1: �˻�����
	char name[20];          // �˻��ϱ⸦ ���ϴ� �����̸� ���庯��
    
	cout<<"�˻��� ���� ������ �Է��ϼ���. >> "<<endl;
	
	cin>>name;       // �˻��ϱ⸦ ���ϴ� �����̸� �Է�
	
	for(i=0 ; i < Video_Num ; i++){
		if(strcmp(vList[i].vname,name)==0){
			
			cout<<" ** �˻��� �������� **"<<endl;  //�˻��� ���� ���� ���
			cout<<"[ ��� ��ȣ ] ["<<i+1<<"]"<<endl;  
			cout<<"[���� ����] " <<vList[i].vname<<endl;
			cout<<"[���� ��ȣ] " <<vList[i].vID<<endl;   
			cout<<"[ �⿬ ��� ] " <<vList[i].vactor<<endl;
			cout<<"[ ��� ���� ] " <<vList[i].publishDate.year<<"��"<<vList[i].publishDate.month<<"��"<<vList[i].publishDate.day<<"��"<<endl;; 
			cout<<"[ �뿩 ���� ] " <<vList[i].price<<"��"<<endl;
			
			if(!vList[i].rended) {  
				cout<<"�뿩 ������ ���� �Դϴ�. "<<endl;
			}
			
			else 
				cout<<"�� ������ ���� �뿩���Դϴ�. "<<endl;
			cout<<"------------------------------------"<<endl;
			
			Search_Result = 1; //�˻� ����
		}
	}
	if(Search_Result == 0)	 cout<<" �Է��� ������ �����ϴ�. "<<endl; // �����˻� ����
}
//���� ��� ����Լ� --->vList[MAX_VIDEO]�� �ִ� �������� �������
void Video::displayvideo()
{
	int i;
	cout<<"--------��ϵ� ���� ���--------"<<endl;
	f=fopen("VIDEO SHOP.txt", "a+"); //������ ���� ���� �Լ� ����
    fprintf(f, "\n\n<���� ��� ����>\n\n");//���� ����Լ�
	fclose(f);//���� �ݱ��Լ�
	for(i=0 ; i < Video_Num ; i++){
		cout<<"[ ��� ��ȣ ] ["<<i+1<<"]"<<endl;  
		cout<<"[���� ����] " <<vList[i].vname<<endl;
		cout<<"[���� ��ȣ] " <<vList[i].vID<<endl;   
		cout<<"[ �⿬ ��� ] " <<vList[i].vactor<<endl;
		cout<<"[ ��� ���� ] " <<vList[i].publishDate.year<<"��"<<vList[i].publishDate.month<<"��"<<vList[i].publishDate.day<<"��"<<endl;; 
		cout<<"[ �뿩 ���� ] " <<vList[i].price<<"��"<<endl;
		if(!vList[i].rended) 
		{
			cout<<"�뿩 ������ ���� �Դϴ�. "<<endl;
		}
		
		else 
			cout<<"�� ������ ���� �뿩���Դϴ�. "<<endl;
		
		cout<<"------------------------------------"<<endl;
	        f=fopen("VIDEO SHOP.txt", "a+");//������ ���� ���� �Լ� ����(a+�� �б�/�߰��� �ǹ�)
		//���� ��� �Լ�
		fprintf(f, "-----------------------------------------\n");
		fprintf(f, " [��Ϲ�ȣ]:%d��\n [��������]:%s\n [������ȣ]:%s��\n [�⿬���]:%s\n [�������]:%d�� %d�� %d��\n [�뿩����]:%d��\n", i+1, vList[i].vname, vList[i].vID, vList[i].vactor, vList[i].publishDate.year, vList[i].publishDate.month, vList[i].publishDate.day, vList[i].price);
	    fprintf(f, "-----------------------------------------\n");
		fclose(f);//���� �ݱ� �Լ�
	}
}


//���� �뿩 �Լ� --->
void Video::Rentvideo()
{
	int i;
	int j,k;
	int Search_Result = 0;  // 0:  �˻�����,  1: �˻�����
	char name[20];          // �뿩�ϱ⸦ ���ϴ� ���� �����Է¹޴� ���� 
	
	cout<<"�뿩�� ���� ������ �Է��ϼ���. >> "<<endl;
	
	cin>>name;       // �뿩�ϱ⸦ ���ϴ� �����̸� �Է�
	
	for(i=0 ; i < Video_Num ; i++){  //���� ��Ͽ��� �뿩 ������ ������ ã�� 
		if(strcmp(vList[i].vname,name)==0){//������Ͽ��� ������ �������� ���
			
			cout<<" ** �뿩�� �������� **"<<endl; 
			cout<<"[ ��� ��ȣ ] ["<<i+1<<"]"<<endl;  
			cout<<"[���� ����] " <<vList[i].vname<<endl;
			cout<<"[���� ��ȣ] " <<vList[i].vID<<endl;   
			cout<<"[ �⿬ ��� ] " <<vList[i].vactor<<endl;
			cout<<"[ ��� ���� ] " <<vList[i].publishDate.year<<"��"<<vList[i].publishDate.month<<"��"<<vList[i].publishDate.day<<"��"<<endl;; 
			cout<<"[ �뿩 ���� ] " <<vList[i].price<<"��"<<endl;
			if(!vList[i].rended) {  
				cout<<"�뿩 ������ ���� �Դϴ�. "<<endl;
			}
			
			else 
				cout<<"�� ������ ���� �뿩���Դϴ�. "<<endl;
				cout<<"------------------------------------"<<endl;
			
			Search_Result = 1;  //�˻� ����
			
			if(!vList[i].rended) {  //�뿩�� �������� �˻�!! (��������� �뿩���ϼ� ����!)
				
				cout<<" �� ������ �뿩���� �մϴ�. "<<endl;
				cout<<" [ �뿩 ���� ]  " <<vList[i].price<<"��"<<endl;//�뿩������ ���
				cout<<" �� ������ �뿩�Ͻðڽ��ϱ�? 1.�� , 2.�ƴϿ�  " <<endl;//1: �뿩 ,2: ���
				
				cin>>j;
				if(j==1) {
					
					cout<<" �뿩 �� ȸ�� �̸��� �Է��ϼ���. "<<endl;  //�뿩�� ȸ���̸��Է�
					cin>>name;  
					
					for(k=0 ; k < member_Num ; k++){  //�뿩�� ȸ���� ȸ����Ͽ��� �˻�
						if(strcmp(mList[k].name,name)==0){ //�뿩�� ȸ���� ������ ȸ���������
							
							cout<<" ** �뿩�� ȸ������ **"<<endl;
							cout<<"[ ȸ�� ��ȣ ] ["<<k+1<<"]"<<endl;
							cout<<"[   ��  ��  ] "<<mList[k].name<<endl;  
							cout<<"[ �ֹ� ��ȣ ] "<<mList[k].personID<<endl;   
							cout<<"[  �� �ּ�  ] "<<mList[k].address<<endl;
							cout<<"[�ڵ��� ��ȣ] "<<mList[i].phonenumber<<endl;
							cout<<"[ ���� ���� ] "<<mList[k].initdate.year<<"��"<<mList[i].initdate.month<<"��"<<mList[i].initdate.day<<"��"<<endl;
							cout<<"[�ֱٴ뿩 ����] "<<mList[k].index.vname<<endl;
							cout<<"[  �뿩   ��¥  ] "<<mList[k].index.rendDate.year<<"��"<<mList[i].index.rendDate.month<<"��"<<mList[i].index.rendDate.day<<"��"<<endl;
							cout<<"[  �뿩   Ƚ��  ] "<<mList[k].rend<<endl;
							cout<<"------------------------------------------"<<endl;
							
							
							Search_Result = 1;  //�˻�����
							
							cout<<" �뿩����: �� �� ��(��, 2007 11 21) "<<endl;  //���� �뿩���� �Է�(��ü�� ����������!)
							cin>>vList[i].rendDate.year>>vList[i].rendDate.month>>vList[i].rendDate.day;
							cout<<"["<<vList[i].vname<<"] ������ "<<mList[k].name<<"ȸ������ �뿩�Ǿ����ϴ�. "<<endl;
							
							vList[i].rended = true;   //������ �뿩�����Ƿ� �����뿩 ���� true �� ���� 
							mList[k].rend++;          //ȸ���� �뿩Ƚ�� ���� 
							mList[k].index = vList[i];	//MemberŬ������ video ������ index �� �뿩�� ������������
							           
						}
					}  //ȸ���˻��� �����Ͽ��� ��� 
					
					if(Search_Result == 0)	 cout<<" �Է��� ȸ���� �����ϴ�. "<<endl; // ����˻� ����
				}
				
				else //���� �뿩��ɿ��� 2�� ��Ҹ� ����������
					
					cout<<"������ �뿩 ���� �ʾҽ��ϴ�. "<<endl;
					
			}
			else //���� ������ �뿩���ΰ�� bool rended ���� true �϶�
				cout<<" �� ������ ���� �뿩���Դϴ�. "<<endl;
			}
		}//���� �˻����� ���������� 	
	if(Search_Result == 0)	 cout<<" ��ϵ��� ���� �����Դϴ�. "<<endl; // ����˻� ����
}


//���� �ݳ� �Լ� 
void Video::Invideo()
{
	int i;
	int Search_Result = 0;  // 0: �˻�����,  1: �˻�����
	char name[20];          // �ݳ��ϱ⸦ ���ϴ� �����̸� ����
	
	cout<<"�ݳ��� ���� ������ �Է��ϼ���. >> "<<endl;
	
	cin>>name;       // �ݳ��ϱ⸦ ���ϴ� �����̸� �Է�
	
	for(i=0 ; i < Video_Num ; i++){       
		if(strcmp(vList[i].vname,name)==0){   //������Ͽ� ������ �������
			
			cout<<" ** �ݳ��� �������� **"<<endl;
			cout<<"[ ��� ��ȣ ] ["<<i+1<<"]"<<endl;  
			cout<<"[���� ����] " <<vList[i].vname<<endl;
			cout<<"[���� ��ȣ] " <<vList[i].vID<<endl;   
			cout<<"[ �⿬ ��� ] " <<vList[i].vactor<<endl;
			cout<<"[ ��� ���� ] " <<vList[i].publishDate.year<<"��"<<vList[i].publishDate.month<<"��"<<vList[i].publishDate.day<<"��"<<endl;; 
			cout<<"[ �뿩 ���� ] " <<vList[i].price<<"��"<<endl;
			if(!vList[i].rended) {
				cout<<"�뿩 ������ ���� �Դϴ�. "<<endl;
			}
			
			else 
				cout<<"�� ������ ���� �뿩���Դϴ�. "<<endl;
				cout<<"------------------------------------"<<endl;
			
			Search_Result = 1;  //�˻�����
			
			cout<<"�ݳ�����: �� �� ��(��, 2007 11 21)"<<endl;  //�ݳ����� �Է�
			cin>>vList[i].inDate.year>>vList[i].inDate.month>>vList[i].inDate.day;
			
			//��ü�Ḧ �˻��ϴ� if�� (�����뿩��¥�� �ݳ���¥�� �˻��ؼ� 2��3���� �������� �Ϸ�� 500���� ��ü��)
			
			if((vList[i].rendDate.year < vList[i].inDate.year ) || (vList[i].rendDate.month < vList[i].inDate.month) || ((vList[i].rendDate.day+3) < vList[i].inDate.day))
			{	
				cout<<"��ü�ᰡ �ֽ��ϴ�. 2�� 3�� ����� �Ϸ�� : 500��"<<endl;
				cout<<"[ ��ü�� ]  "<<(vList[i].inDate.day - (vList[i].rendDate.day+3))*500<<"��"<<endl;
				vList[i].rended = false;  //���� �뿩���� ���� rended false �� �ٲ� 	
				cout<<"���������� �ݳ�ó�� �Ǿ����ϴ�."<<endl;
			}
			
			//�����ݳ����ڰ� 2��3�ϰ���� �ȉ�����
			else
			{  
				cout<<"��ü���� �ʰ� ���������� �ݳ�ó�� �Ǿ����ϴ�."<<endl;
				vList[i].rended = false;
			}
		}
		else //�ݳ��� ������ ��ϵǾ� ���� ������
			cout<<"��ϵǾ� ���� ���� �����Դϴ�."<<endl;
	}	
}


//�뿩���� ���� ����Լ� 
void Video::RentedvideoShow()
{
	int i;
	cout<<"--------�뿩�� ���� ���--------"<<endl; 
	f=fopen("VIDEO SHOP.txt", "a+");
   	fprintf(f, "\n\n<�뿩�� ���� ��� ����>\n\n");
	fclose(f);
	for(i=0 ; i < Video_Num ; i++){
		
		if(vList[i].rended) {  //rended ������ �˻��ؼ� true�� ������ ���
			cout<<"[ ��� ��ȣ ] ["<<i+1<<"]"<<endl;  
			cout<<"[���� ����] " <<vList[i].vname<<endl;
			cout<<"[���� ��ȣ] " <<vList[i].vID<<endl;   
			cout<<"[ �⿬ ��� ] " <<vList[i].vactor<<endl;
			cout<<"[ ��� ���� ] " <<vList[i].publishDate.year<<"��"<<vList[i].publishDate.month<<"��"<<vList[i].publishDate.day<<"��"<<endl;; 
			cout<<"[ �뿩 ���� ] " <<vList[i].price<<"��"<<endl;
			cout<<"------------------------------------"<<endl;
		}
		
		f=fopen("VIDEO SHOP.txt", "a+");
		fprintf(f, "-----------------------------------------\n");
		fprintf(f, " [��Ϲ�ȣ]:%d��\n [��������]:%s\n [������ȣ]:%s��\n [�⿬���]:%s\n [�������]:%d�� %d�� %d��\n [�뿩����]:%d��\n", i+1, vList[i].vname, vList[i].vID, vList[i].vactor, vList[i].publishDate.year, vList[i].publishDate.month, vList[i].publishDate.day, vList[i].price);
	    fprintf(f, "-----------------------------------------\n");
		fclose(f);
	}
       //cout<<"�뿩�� ������ �����ϴ�. "<<endl;
}


//��ü�� ȸ��(������Ʈ)�� ���� ������ ����ϴ� �Լ�
void Video::blacklist()
{
	int i;
	cout<<"---------������Ʈ ���� ���----------"<<endl;
	f=fopen("VIDEO SHOP.txt", "a+");
    fprintf(f, "\n\n<������Ʈ ����>\n\n");
	fclose(f);
	for(i=0 ; i < Video_Num ; i++){
	 if((vList[i].rendDate.year < vList[i].inDate.year ) || (vList[i].rendDate.month < vList[i].inDate.month) || ((vList[i].rendDate.day+3) < vList[i].inDate.day))
	 {	
	   for(i=0 ; i < member_Num ; i++){
		cout<<"[ ȸ�� ��ȣ ] ["<<i+1<<"]"<<endl;
		cout<<"[   ��  ��  ] "<<mList[i].name<<endl;  
		cout<<"[ �ֹ� ��ȣ ] "<<mList[i].personID<<endl;   
		cout<<"[  �� �ּ�  ] "<<mList[i].address<<endl;
		cout<<"[�ڵ��� ��ȣ] "<<mList[i].phonenumber<<endl;
		cout<<"[ ���� ���� ] "<<mList[i].initdate.year<<"��"<<mList[i].initdate.month<<"��"<<mList[i].initdate.day<<"��"<<endl;
		cout<<"[�ֱٴ뿩 ����] "<<mList[i].index.vname<<endl;
		cout<<"[  �뿩   ��¥  ] "<<mList[i].index.rendDate.year<<"��"<<mList[i].index.rendDate.month<<"��"<<mList[i].index.rendDate.day<<"��"<<endl;
		cout<<"[  �뿩   Ƚ��  ] "<<mList[i].rend<<endl;
		cout<<"------------------------------------"<<endl;

		f=fopen("VIDEO SHOP.txt", "a+");
		fprintf(f, "-----------------------------------------\n");
		fprintf(f, " [ȸ����ȣ]:%d��\n [�̸�]:%s\n [�ֹι�ȣ]:%s\n [�� �ּ�]:%s\n [�ڵ�����ȣ]:%s\n [��������]:%d�� %d�� %d��\n [�ֱٴ뿩����]:%s\n [�뿩��¥]:%d�� %d�� %d��\n [�뿩Ƚ��]:%d\n", i+1, mList[i].name, mList[i].personID, mList[i].address, mList[i].phonenumber, mList[i].initdate.year, mList[i].initdate.month, mList[i].initdate.day, mList[i].index.vname, mList[i].index.rendDate.year, mList[i].index.rendDate.month, mList[i].index.rendDate.day, mList[i].rend);
	   	fprintf(f, "-----------------------------------------\n");
		fclose(f);
	}
   }
 }
}
//---------------------------------VideoŬ���� �ֿ��� �� ---------------------


// ȸ�� ����Լ� Member mList[member_Num]; �迭�� ȸ���� �������� ����
void Member::Addmember()
{
	cout<<"ȸ�� ������ �Է��ϼ���"<<endl;
	
	cout<<"�̸�: ";
	cin>>mList[member_Num].name;
	
	cout<<"�ֹι�ȣ: ";
	cin>>mList[member_Num].personID;
	
	cout<<"�� �ּ�: ";
	cin>>mList[member_Num].address;
	
	cout<<"�ڵ��� ��ȣ: ";
	cin>>mList[member_Num].phonenumber;
	
	cout<<"��������: �� �� ��(��, 2007 11 21)";
	cin>>mList[member_Num].initdate.year>>mList[member_Num].initdate.month>>mList[member_Num].initdate.day;
	
	member_Num++; // ȸ�� �ε��� 1 ���� 
	
	mList[member_Num].rend = 0; //���� �뿩Ƚ�� 0���� �ʱ�ȭ
}


//ȸ�� ��� ����Լ�   -->    mList[member_Num]�迭�� �ִ� ȸ���� ���� ���
void Member::displaymember()
{	
	int i;
	cout<<"--------��ϵ� ȸ������ ���--------"<<endl;
	f=fopen("VIDEO SHOP.txt", "a+");
    fprintf(f, "\n\n<ȸ�� ����>\n\n");
	fclose(f);
	for(i=0 ; i < member_Num ; i++){
		cout<<"[ ȸ�� ��ȣ ] ["<<i+1<<"]"<<endl;
		cout<<"[   ��  ��  ] "<<mList[i].name<<endl;  
		cout<<"[ �ֹ� ��ȣ ] "<<mList[i].personID<<endl;   
		cout<<"[  �� �ּ�  ] "<<mList[i].address<<endl;
		cout<<"[�ڵ��� ��ȣ] "<<mList[i].phonenumber<<endl;
		cout<<"[ ���� ���� ] "<<mList[i].initdate.year<<"��"<<mList[i].initdate.month<<"��"<<mList[i].initdate.day<<"��"<<endl;
		cout<<"[�ֱٴ뿩 ����] "<<mList[i].index.vname<<endl;
		cout<<"[  �뿩   ��¥  ] "<<mList[i].index.rendDate.year<<"��"<<mList[i].index.rendDate.month<<"��"<<mList[i].index.rendDate.day<<"��"<<endl;
		cout<<"[  �뿩   Ƚ��  ] "<<mList[i].rend<<endl;
		cout<<"------------------------------------"<<endl;
	   
		f=fopen("VIDEO SHOP.txt", "a+");
		fprintf(f, "-----------------------------------------\n");
		fprintf(f, " [ȸ����ȣ]:%d��\n [�̸�]:%s\n [�ֹι�ȣ]:%s\n [�� �ּ�]:%s\n [�ڵ�����ȣ]:%s\n [��������]:%d�� %d�� %d��\n [�ֱٴ뿩����]:%s\n [�뿩��¥]:%d�� %d�� %d��\n [�뿩Ƚ��]:%d\n", i+1, mList[i].name, mList[i].personID, mList[i].address, mList[i].phonenumber, mList[i].initdate.year, mList[i].initdate.month, mList[i].initdate.day, mList[i].index.vname, mList[i].index.rendDate.year, mList[i].index.rendDate.month, mList[i].index.rendDate.day, mList[i].rend);
	    fprintf(f, "-----------------------------------------\n");
		fclose(f);
	}    
}


//ȸ�� ���� �����Լ� 
void Member::modifymember()
{
	
	int i;
    char name[20];         // ������ ȸ���̸� 
	int mem_Num;           // ������ ȸ���ε���(����ü �迭 �ε���) 
	int Search_Result = 0;  // ������ �˻����, 0: ������ ȸ�� �˻� ����, 1: ������ ȸ�� �˻� ����
	char key;
	
	cout<<"������ ����̸��� �Է��ϼ��� >>"<<endl;
        cin>>name;            // ������ ȸ���̸� �Է�
	
	for(i=0 ; i < member_Num ; i++){
		if(strcmp(mList[i].name,name)==0){  //������ ȸ�� �˻� ������ 
			mem_Num = i;              // ������ ȸ������ü ������ �ε��� �� ȹ��
			Search_Result = 1;     //�˻� ����
		}
	}
	
    // ȸ���˻��� �����Ͽ��� �� 
	if(Search_Result == 1){  
		cout<<"�� ���� �� ������ �����Ͻðڽ��ϱ�? "<<endl;;
		cout<<" 1. �ּ� ���� "<<endl;  //�ּҼ���
		cout<<" 2. �ڵ��� ��ȣ ����  >>"<<endl;//�ڵ�����ȣ ����
		
		fflush(stdin);
		key = getchar();
		
        	if(key=='1'){
			cout<<"�����ּ� >>"<<endl;
			fflush(stdin);
			cin>>mList[mem_Num].address;  //������ ȸ���ε��� ������ ������ �Է¹��� 
			cout<<mList[mem_Num].name<<"ȸ���� �ּҰ� "<<mList[mem_Num].address<<"(��)�� ����Ǿ����ϴ�."<<endl;
		}
		
		else if(key == '2'){
			printf("�����ڵ��� ��ȣ >>");
			cin>>mList[mem_Num].phonenumber; //������ ȸ���ε��� ������ ������ �Է¹��� 
			cout<<mList[mem_Num].name<<"ȸ����  �ڵ��� ��ȣ�� "<<mList[mem_Num].phonenumber <<"���� ����Ǿ����ϴ�."<<endl;
		}
		
		else{// 1,2 ���ƴ� �ٸ� �� �Է½� 
            cout<<"�߸� �Է��Ͽ����ϴ�. "<<endl;             
		}
	}
	// ȸ���˻��� ���� �Ͽ��� �� 
	else
		cout<<"�Է��� ȸ���� �����ϴ�. "<<endl;
}


//-----------Member Ŭ���� ��� �� -------------------


//Main  �Լ� --->�� 10�� ����� �޴��� �� �� ���� 
int main()
{
	char Menu;
	Video a;   //������ü ����
	Member b;  //��� ��ü ����	

	while(1)
	{
		cout<<" +------------------------------------+"<<endl;
		cout<<" +    C++ VIDEO SHOP �������α׷�     +"<<endl;
		cout<<" +      Visual Studio C++ 2010        +"<<endl;     
		cout<<" +       File I/O Text Version        +"<<endl;
		cout<<" +         A911049  �� �� ��          +"<<endl;
		cout<<" +------------------------------------+"<<endl;
		cout<<endl;
		cout<<" +-----------------+--------------------+---------------------+-----------------+"<<endl;
		cout<<" +   ���� ����   +     �� ����      +      �뿩 ����      +    ��     ��    +"<<endl; 
		cout<<" +-----------------+--------------------+---------------------+-----------------+"<<endl;
		cout<<" + 1.���� ���   + 4. ȸ�� ���       + 7. ���� �뿩      + q. ��     ��    +"<<endl;
		cout<<" + 2.���� �˻�   + 5. ȸ�� ��� ���  + 8. ���� �ݳ�      +                 +"<<endl;
		cout<<" + 3.���� ���   + 6. ȸ�� ���� ����  + 9. �뿩�ߺ������ +                 +"<<endl;
		cout<<" +   ���          +                    + 0. ������Ʈ ����  +                 +"<<endl;
		cout<<" +                 +                    +                     +                 +"<<endl; 
		cout<<" +-----------------+--------------------+---------------------+-----------------+"<<endl;
		cout<<">> "; 
		
		fflush(stdin);
		Menu = getchar();
		fflush(stdin);     
		
		switch(Menu)
		{
		  case '1':
			a.Addvideo(); //���� �߰��Լ� ����
			cout<<"Enter�� �Է��ϼ���"<<endl;
			getch();		
			system("cls");
			break;
			
		
		  case '2':
			a.Searchvideo();  //���� �˻��Լ� ����
			cout<<"Enter�� �Է��ϼ���"<<endl;
			getch();		
			system("cls");
			break;			
					
		
		  case '3':	   					
			a.displayvideo(); //���� ��� ��� �Լ� ����
			cout<<"Enter�� �Է��ϼ���"<<endl;
			getch();		
			system("cls");
			break;
			
			
		  case '4':						
			b.Addmember();  //ȸ���߰��Լ�  �ǻ�
			cout<<"Enter�� �Է��ϼ���"<<endl;
			getch();					
			system("cls");
			break;
			
	    
		  case '5':						
			b.displaymember();  //ȸ�� ��� ��� �Լ� ����
			cout<<"Enter�� �Է��ϼ���"<<endl;
			getch();			
			system("cls");
			break;
			
		
		  case '6':						
			b.modifymember();  //ȸ�� ���� �����Լ� ����
			cout<<"Enter�� �Է��ϼ���"<<endl;
			getch();			
			system("cls");
			break;	
		
		
		  case '7':						
			a.Rentvideo();   //���� �뿩�Լ� ����
			cout<<"Enter�� �Է��ϼ���"<<endl;
			getch();		
			system("cls");
			break;			
			
		
		  case '8':
			a.Invideo();  //���� �ݳ��Լ� ����
			cout<<"Enter�� �Է��ϼ���"<<endl;
			getch();		
			system("cls");
			break;
			
		
		  case '9':						
			a.RentedvideoShow();  //�뿩���� ���� ����Լ� ����
			cout<<"Enter�� �Է��ϼ���"<<endl;
			getch();
			system("cls");
			break;
			
			
		 case '0':
			a.blacklist();  //������Ʈ ����Լ� ����
			cout<<"Enter�� �Է��ϼ���"<<endl;
	        getch();
			system("cls");
			break;
	    
	    
	      case 'q':  //���α׷�����
			cout<<"���α׷��� �����մϴ�. "<<endl;             
			return 0;
			
			
		  default:  //�߸��� �Է�
			cout<<"�߸��� �Է��Դϴ� -> "<<Menu<<endl;
			break;
		}//end of switch
	}//end of while
}
