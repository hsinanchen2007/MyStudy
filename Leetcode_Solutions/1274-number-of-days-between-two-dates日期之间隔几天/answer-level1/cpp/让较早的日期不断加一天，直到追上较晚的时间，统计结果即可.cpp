### 解题思路
![微信图片_20200223135913.png](https://pic.leetcode-cn.com/9e2c62076560e11365f357e6d46c7c8309ac48c5a108adea6ed7c79038dac3a5-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200223135913.png)


### 代码

```cpp
class Solution {
private:
    int month[13][2]={{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};
    bool isLeap(int year){
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

public:
    int daysBetweenDates(string date1, string date2) {
        if(date1>date2){
            string temp = date1;
            date1 = date2;
            date2 = temp;
        }
        int y1,m1,d1,y2,m2,d2;
        y1=stoi(date1.substr(0,4));
        y2=stoi(date2.substr(0,4));
        m1=stoi(date1.substr(5,2));
        m2=stoi(date2.substr(5,2));
        d1=stoi(date1.substr(8,2));
        d2=stoi(date2.substr(8,2));
        int ans = 0;
        while(y1 < y2 || m1 < m2 || d1 < d2){
            d1++;
            if(d1 == month[m1][isLeap(y1)]+1){
                m1++;
                d1 = 1;
            }
            if(m1 == 13){
                y1++;
                m1 = 1;
            }
            ans++;
        }
        return ans;



    }
};
```