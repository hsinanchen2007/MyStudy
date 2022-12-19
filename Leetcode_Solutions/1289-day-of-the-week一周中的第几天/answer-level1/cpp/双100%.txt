![image.png](https://pic.leetcode-cn.com/f0a379f6b1177f341b90179db5dd5462e8ce501818363a2db3befc6870b22c4a-image.png)
### 因为是从今天开始算的，所以有点麻烦。毕竟不查资料的话只知道这个。。
```cpp
class Solution {
private:
    int month_days[13][2]={ {0, 0}, {31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31} };
    string weeks[7]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
public:
    //判断闰年
    int isLeap(int year){
        if((year%4==0 && year%100) || year%400==0) return 1;
        else return 0;
    }
    int delta_days(int y1, int m1, int d1, int y2, int m2, int d2){
        //默认 y1m1d1 > y2m2d2
        int ans=0;
        //时间调到m2月1日
        while((y1>y2 || m1>m2 || d1>d2) && d2!=1){
            ans++;
            d2++;
            if(d2==month_days[m2][isLeap(y2)]+1){
                d2=1;
                m2++;
            }
            if(m2==13){
                m2=1;
                y2++;
            }
        }
        //按年跳
        while(y1 > y2+1){
            if(m2>2){
                if(isLeap(y2+1)==1) ans+=366;
                else ans+=365;
            }
            else{
                if(isLeap(y2)==1) ans+=366;
                else ans+=365;
            }
            y2++;
        }
        //按月跳
        while(y1>y2 || m1>m2+1){
            ans+=month_days[m2][isLeap(y2)];
            m2++;
            if(m2==13){
                m2=1;
                y2++;
            }
        }
        //把时间准确调到y1m1d1
        while(y1>y2 || m1>m2 || d1>d2){
            ans++;
            d2++;
            if(d2==month_days[m2][isLeap(y2)]+1){
                d2=1;
                m2++;
            }
            if(m2==13){
                m2=1;
                y2++;
            }
        }
        return ans;
    }
    string dayOfTheWeek(int day, int month, int year) {
        int d; //d表示距2019.12.27（今天）的天数
        if(year*10000+month*100+day > 20191227){
            d = delta_days(year, month, day, 2019, 12, 27);
            return weeks[(d+5)%7];//2019.12.27是周五
        }
        else{
            d = delta_days(2019, 12, 27, year, month, day);
            return weeks[(12-(d%7))%7];
        }
    }
};
```