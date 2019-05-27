#include <iostream>
#include <string>
#include <algorithm>
#include <array>

class Train{
private:
    std::string destination;
    int number;
    std::string departure_time;
public:
    friend std::ostream& operator<<(std::ostream & os,Train &t){
        os<<t.destination<<" "<<t.number<<" "<<t.departure_time<<std::endl;
        return os;
    }
    friend std::istream& operator>>(std::istream & is,Train& t);
    std::string get_destination(){
        return this->destination;
    }
    std::string get_departure_time(){
        return this->departure_time;
    }
};
    std::istream& operator>>(std::istream & is,Train& t){
        std::cout<<"Enter destination : ";
        is>>t.destination;
        std::cout<<"Enter train number : ";
        is>>t.number;
        std::cout<<"Enter departure time : ";
        is>>t.departure_time;
    }

void sort(Train *arr,int size){
        for (int i = 0; i < size - 1; i++) {
                for (int j = 0; j < size - i - 1; j++) {
                    if (arr[j].get_destination() > arr[j + 1].get_destination()) {
                        // меняем элементы местами
                        Train temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
          }
     }
}
}
void get_trains(Train *t,int size,std::string time){
    int k=0;
    for(int i=0;i<size;i++)
        if(t[i].get_departure_time()>time){
            k++;
            std::cout<<t[i];
        }
    if(k==0)
        std::cout<<"No train after"<<time<<std::endl;
}
int main(){
    Train t[3];
    std::string time;
    for(int i=0;i<6;i++)
        operator>>(std::cin,t[i]);
    sort(t,6);
    for(int i=0;i<6;i++)
        std::cout<<t[i];
    std::cout<<"Enter departure time : "<<std::endl;
    std::cin>>time;
    get_trains(t,6,time);
    return 0;
}