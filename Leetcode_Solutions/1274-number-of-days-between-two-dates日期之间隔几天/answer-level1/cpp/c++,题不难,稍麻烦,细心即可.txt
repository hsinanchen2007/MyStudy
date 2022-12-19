### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        if (date1.empty() || date2.empty()) {
            return 0;
        }
        int year_a, year_b, month_a, month_b, day_a, day_b;
        Split(date1, year_a, month_a, day_a);
        Split(date2, year_b, month_b, day_b);
        if (year_a > year_b) {
            swap(year_a, year_b);
            swap(month_a, month_b);
            swap(day_a, day_b);
        } else if (year_a == year_b) {
            if (month_a > month_b) {
                swap(month_a, month_b);
                swap(day_a, day_b);
            } else if (month_a == month_b) {
                if (day_a > day_b) {
                    swap(day_a, day_b);
                }
            }
        }
        int days = 0;
        for (int i = year_a + 1; i < year_b; ++i) {
            if (IsLeapYear(i)) {
                days += 1;
            }
            days += 365;
        }
        istringstream ss("1 3 5 7 8 10 12");
        string temp;
        unordered_map<int, int> dict;
        while (ss >> temp) {
            dict[atoi(temp.c_str())] = 1;
        }
        if (year_a == year_b) {
            if (month_a == month_b) {
                return day_b - day_a;
            }
            CalcSameYearSituation(year_a, month_a, day_a, year_b, month_b, day_b,
                                    dict, days);
            return days;
        }
        DayCalc(year_a, month_a, day_a, dict, days, true);
        DayCalc(year_b, month_b, day_b, dict, days, false);
        return days;
    }
    void CalcSameYearSituation(int year_a, int month_a, int day_a,
        int year_b, int month_b,int day_b, unordered_map<int, int>& dict, int& days) {    
        for (int i = month_a + 1; i < month_b; ++i) {
            if (dict[i]) {
                days += 31;
            } else {
                days += 30;
            }
        }
        bool is_leap_year = IsLeapYear(year_a);
        if(month_a + 1 <= 2 &&  month_b > 2) {
            if (is_leap_year) {
                days -= 1;
            } else {
                days -= 2;
            }
        }
        if (dict[month_a]) {
            days += 31 - day_a;
        } else if (month_a == 2) {
            if (is_leap_year) {
                days += 29 - day_a;
            } else {
                days += (28 - day_a);
            }
        } else {
            days += 30 - day_a;
        }
        days += day_b;                                
    }
   
    void Split(const string& str, int& year, int& month, int& day) {
        year = atoi(str.substr(0, 4).c_str());
        month = atoi(str.substr(5, 2).c_str());
        day = atoi(str.substr(8,2).c_str());
    }
    bool IsLeapYear(int year) {
        return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
    }
    void DayCalc(int year, int month, int day, unordered_map<int, int>& dict, int& days, bool is_pre) {
        int num = 0;
        for (int i = 1; i < month; ++i) {
            if (dict[i]) {
                num += 31;
            } else {
                num += 30;
            }
        }
        bool is_leap_year = IsLeapYear(year);
        if (month > 2) {
            if (is_leap_year) {
                num -= 1;
            } else {
                num -= 2;
            }
        }
        num += day;
        if (is_pre) {
            if (is_leap_year) {
                days += (366 - num);
            } else {
                days += (365 - num);
            }
        } else {
            days += num;
        }
    }
};
```