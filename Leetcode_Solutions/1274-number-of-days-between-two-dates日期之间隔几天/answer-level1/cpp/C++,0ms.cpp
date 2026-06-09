![Q1.jpg](https://pic.leetcode-cn.com/45d93862ffde22400a16beedcfa990d7e065b56027d04a44c17576d64714d1dd-Q1.jpg)

### 解题思路
算出日期是这一年的第几天就比较好办了:
- 如果两个日子是同一年的，则直接相减j；
- 如果不是，那么可以考虑日子小的那个差多少天过完这一年，然后累加相差的年的天数，最后加上大的日子在这一年的第几天的天数；

### 代码

```cpp
class Solution {
public:
    int isLeapYear(int year){
        if(year%400 == 0 || (year%4 == 0 &&year%100 != 0)) return 1;
        return 0;
    }
    int getDays(int year,int month){
        int num = 0;
        switch(month){
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                num = 31;
                break;
            case 2:
                num  = 28 + isLeapYear(year);
                break;
            default:
                num = 30;
                break;

        }
        return num;
    }
    int getDaysYear(int year){
        return 365+isLeapYear(year);
    }

    //算出这个日期是这一年的第几天;
    int getNumDaysInYear(int year,int month,int day){
        int sum = 0;
        for(int i=1;i<month;++i){
            sum += getDays(year,i);
        }
        return sum+day;
    }
    int diff(const string& date1,const string& date2){
        int year1 = stoi(date1.substr(0,4));
        int month1 = stoi(date1.substr(5,2));
        int day1 = stoi(date1.substr(8,2));

        int year2 = stoi(date2.substr(0,4));
        int month2 = stoi(date2.substr(5,2));
        int day2 = stoi(date2.substr(8,2));

        if(year1 == year2 && month1 == month2){
            return abs(day2-day1);
        }
        else if(year1 == year2){
            int num_day1 = getNumDaysInYear(year1,month1,day1);
            
            int num_day2 = getNumDaysInYear(year2,month2,day2);
            return num_day2-num_day1;
        }
        else{ 
            
            int num_day1 = getNumDaysInYear(year1,month1,day1);
            int ans = getDaysYear(year1)-num_day1;
            for(int i=year1+1;i<year2;++i){
                ans += getDaysYear(i);
            }
            
            ans += getNumDaysInYear(year2,month2,day2);
            return ans;
        }
        

    }   
    int daysBetweenDates(string date1, string date2) {
        if(date1>date2) return diff(date2,date1);
        return diff(date1,date2);
  
    }
};
```