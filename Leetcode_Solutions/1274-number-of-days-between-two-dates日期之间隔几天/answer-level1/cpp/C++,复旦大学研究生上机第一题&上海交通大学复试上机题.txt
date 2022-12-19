```
int mon[2][13]={
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};
class Solution {
public:

    int leap(int x){
        if(x%400==0||(x%4==0&&x%100!=0))return 1;
        return 0;
    }
    int day(int y,int m,int d){
        int sum=0;
        for(int i=1971;i<y;i++){
            if(leap(i)){
                sum+=366;
            }else{
                sum+=365;
            }
        }
        for(int i=1;i<m;i++){
            sum+=mon[leap(y)][i];
        }
        sum+=d;
        return sum;
    }
    int daysBetweenDates(string date1, string date2) {
        int y1=stoi(date1.substr(0,4)),m1=stoi(date1.substr(5,2)),d1=stoi(date1.substr(8,2));
        int y2=stoi(date2.substr(0,4)),m2=stoi(date2.substr(5,2)),d2=stoi(date2.substr(8,2));
        int ans=abs(day(y2,m2,d2)-day(y1,m1,d1));
        return ans;
    }
};
```
