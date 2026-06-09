### 解题思路
先把年月日变成整型；
年用来算二月的天数；
此月之前的月天数和+日=res


### 代码

```cpp
class Solution {
public:
    int dayOfYear(string date) {
        int year=0,month=0,day=0,res=0;
        for(int i=0;i<date.size();i++){
        
            int temp=date[i]-'0';
            if(i<=3) year=year*10+temp;
            else if(i<=6&&i>=5) month=month*10+temp;
            else if(i<=9&&i>=8) day=day*10+temp;
        }
        int mday[]={0,31,28,31,30,31,30,31,31,30,31,30,31}; //1-12月的天数
        if((year%4==0 && year%100!=0) || year%400==0) mday[2]=29;//闰年
        month--;
        while(month>0){
            res+=mday[month];
            month--;
        }
        res+=day;
        return res;
    }
};
```