#include <iostream>
#include <cstring>
using namespace std;

class Publication{
    protected:
    string title;
    float price;
    public:
    void get(){
        cout<<"Enter the Title of Publication : "<<endl;
        cin>>title;
        cout<<"Enter the price of publication : "<<endl;
        cin>>price;
    }
    void put(){
        try{
            if (title.length()<=1){
                throw title;
            }
        }catch(string exp){
            title="No Name";
        }
        cout<<"Publication name : "<<title<<endl;
        try{
            if (price<=0){
            throw price;
            }
        }catch(float exp){
            price=0.0;
        }
        cout<<"Price : "<<price<<endl;
    }
};
class book:public Publication {
    int pg_count;
    public:
    void get_page(){
        Publication::get();
        cout<<"Enter page count : ";
        cin>>pg_count;

    }
    void put_page(){
        try{
            if(pg_count<=0){
                throw pg_count;
            }
        }catch(int exp){
                pg_count=0;
        }
        Publication::put();
        cout<<"Page count : "<<pg_count<<endl;
    }
};
class tape:public Publication{
    float minu;
    public:
    void get_min(){
        Publication::get();
        cout<<"Enter time in min : "<<endl;
        cin>>minu;
    }
    void put_min(){
        Publication::put();
        cout<<"Time is : "<<minu<<endl;
    }
};
int main(){
    book b1;
    tape t1;
    cout<<"*****Enter Book Data**********"<<endl;
    b1.get_page();
    cout<<"*****Enter Tape Data**********"<<endl;
    t1.get_min();
    cout<<"*******Book data*********"<<endl;
    b1.put_page();
    cout<<"*******Tape data*********"<<endl;
    t1.put_min();
    return 0;
}