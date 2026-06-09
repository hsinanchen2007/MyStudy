### 解题思路
两个日期相减取绝对值，选一个合适的基准日期，最容易用的就是1970-01-01。分别计算给定日期和基准日期的差值，把两次结果取绝对值即可。

### 代码

```cpp
class Solution {
private:
   int is4Times(int n){//判断闰年
            if(n%400==0)return 1;
            if(n%4==0 && n%100!=0)return 1;
            return 0;
        }

    int monthDay(int a,int b){//每月几天
        int day = 0;
        if (b==0) {
            day = 0;
        }else if (b==2) {
            if(is4Times(a)){
                day = 29;
            }else{
                day = 28;
            }
        }else if (b==4||b==6||b==9||b==11){
            day = 30;
        }else{
            day = 31;
        }
        return day;
    }
    int countDays(string date){//计算差值
        int count = 0;
        int num = 0;
        int year = stoi(date.substr(0,4));
        int month = stoi(date.substr(5,2));
        int day = stoi(date.substr(8,2));
        
        for (int i=1970; i<year; i++) {
            if (is4Times(i)) {
                num++;
            }
        }
        for (int i=0; i<month; i++) {
            count = count+monthDay(year, i);
        }
        int temp = year-num-1970;
        count = count+num*366+temp*365+day;
        
        return count;
    }
public:
    int daysBetweenDates(string date1, string date2) {
        int count = 0;
        int day1=0,day2 = 0;
        day1 = countDays(date1);
        day2 = countDays(date2);
        count = abs(day1-day2);
        return count;
    }
};

```
这是通过记录

![截屏2020-02-23下午2.03.37.png](https://pic.leetcode-cn.com/039c03836a433d181c39342a7b52e362663e7daa6000d49067694d337f4b11ee-%E6%88%AA%E5%B1%8F2020-02-23%E4%B8%8B%E5%8D%882.03.37.png)

这是错误的血泪史

![截屏2020-02-23下午2.04.46.png](https://pic.leetcode-cn.com/73b00c0a237873605db8ae4c6e27697e095c44de5f19d9f3244ad6852b6fc817-%E6%88%AA%E5%B1%8F2020-02-23%E4%B8%8B%E5%8D%882.04.46.png)
