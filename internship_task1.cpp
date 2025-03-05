#include<iostream>
using namespace std;
double gradetoPoint(char grade) {
    switch(grade) {
        case'A':
        return 4.0;
        case'B':
        return 3.0;
        case'c':
        return 2.0;
        case'D':
        return 1.0;
        case'F':
        return 0.0;
        default:
        return-1.0;
    }
}

int main() {
    int numcourses;
    cout<<"Enter the number of courses: ";
    cin>>numcourses;
    while(numcourses<=0) {
        cout<<"Invalid input. Number of courses must be greater than 0. try again ";
        cin>>numcourses;
    }
    int credits[numcourses];
    char grades[numcourses];
    double totalcredits=0.0,totalgradePoints=0.0;
    for(int i=0;i<numcourses;++i) {
        cout<<"Enter credits for course "<<i+1<<": ";
        cin>>credits[i];
        while(credits[i]<=0) {
            cout<<"Invalid input. credits must be greater than 0. try again ";
            cin>>credits[i];
        }
    cout<<"Enter grade for course "<<i+1<<" (A, B, c, D, F): ";
    cin>>grades[i];
while(gradetoPoint(grades[i])==-1.0) {
    cout<<"Invalid grade. Please enter a valid grade (A, B, c, D, F): ";
    cin>>grades[i];
    }
   totalcredits+=credits[i];
 totalgradePoints+=credits[i]*gradetoPoint(grades[i]);
    }
double gpa=totalgradePoints/totalcredits;
    cout<<"\ncourse Details:\n";
    cout<<"course\tcredits\tgrade\tgrade Points\n";
    for(int i=0;i<numcourses;++i) {
        cout<<i+1<<"\t\t  "<<credits[i]<<"\t\t  "<<grades[i]<<"\t\t  "<<gradetoPoint(grades[i])<<endl;
    }

  cout<<"\ntotal credits: "<<totalcredits<<endl;
 cout<<"total grade Points: "<<totalgradePoints<<endl;
  cout<<"CGPA for the semester: "<<gpa<<endl;
    return 0;
}