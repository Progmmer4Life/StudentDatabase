
#include<bits/stdc++.h>
using namespace std;
static int roll_number=0;
class Student{
	public:		
		string stud_name,subject;
		Student(){}
		void getStudentDetails(){
			cin>>stud_name;
		}
		void displayStudent(int roll){
			cout<<roll<<"\t\t"<<stud_name<<"\t";
		}
		
};
class Subject:virtual public Student{
	public:
		string sub_code,sub_name;
		Subject(){}
		void getSubjectDetails(){
			cin>>sub_code>>sub_name;
		}
		void displaySubject(){
			cout<<"\t"<<sub_code<<"\t\t"<<sub_name<<"\t  ";
		}
	
};
class ExamMarks:virtual public Student{
	public:
		int internal,univ_mark;
		ExamMarks(){}
		void getExamMarks(){
			cin>>internal>>univ_mark;
		}
		void displayExamMarks(){
			cout<<internal<<"\t"<<" "<<univ_mark<<endl;
		}
};
class Merge:public Subject,public ExamMarks{
	public:
		Merge(){}
		void getAllDetails(){
			cout<<"Enter name of Student,his Subject Code,subject name,internal assessment and university marks "<<endl;
			getStudentDetails();
			getSubjectDetails();
			getExamMarks();			
		}
		void displayAll(int roll_position){
			displayStudent(roll_position);
			displaySubject();
			displayExamMarks();
		}
		
};
int main(){
	int option,l=0,del,edit,pos,p;
	string name;
	Merge merge[10];
	//vector<Merge> merge;
		
	while(1){
		cout<<"*****************************Facilities*********************************"<<endl
		    <<"1 Build a master table"<<endl
			<<"2 List a table"<<endl
			<<"3 Insert a new entry"<<endl
			<<"4 Delete old entry"<<endl
			<<"5 Edit an entry"<<endl
			<<"6 Search for a record"<<endl
			<<"7 Exit"<<endl;
		cin>>option;
		switch(option){
			case 1: merge[roll_number].getAllDetails();
					roll_number++;
					break;			
			case 2: cout<<"Table List\n";
					cout<<"Student No. |"<<"Student Name |"<<"Subject Code |"<<"Subject Name |"<<"Internal |"<<"University Marks"<<endl;
					for(int i=0;i<roll_number;i++){
						merge[i].displayAll(i);
					}
					break;
			case 3: cout<<"Enter At End :? Press 1   Or   Enter At Specific Position:? Press 2\n"<<endl;
					//Implementation
					cin>>pos;
					if(pos==1){
						merge[roll_number++].getAllDetails();
					}else{
						cout<<"Enter Position -->";
						cin>>p;
						merge[p].getAllDetails();
					}
					break;
			case 4: cout<<"Enter Roll Number For Which you want to Delete "<<endl;
					cin>>del;
					if(del!=0) del-=1;
					for(int i=del;i<roll_number;i++){
						merge[i]=merge[i+1];
					}
					roll_number--;
					break;
			case 5: cout<<"Enter Roll Number For Which you want to Edit "<<endl;
					cin>>edit;
					merge[edit].getAllDetails();
					break;
			case 6: cout<<"Enter Name to Search In DataBase "<<endl;
					cin>>name;
					for(int i=0;i<roll_number;i++){
						if(merge[i].stud_name==name){
							cout<<"Roll Number of "<<name<<" is "<<roll_number+1<<endl;
							merge[i].displayStudent(i);
							cout<<endl;
						}else{
							cout<<"Not Found "<<endl;
						}
					}
					break;
			case 7: return 0;
					break;
			default :cout<<"\nEnter a valid Option Number \n";
		}
		cout<<endl;
	}
	return 0;
}
