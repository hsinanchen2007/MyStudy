### 解题思路
![image.png](https://pic.leetcode-cn.com/baa9f88e9cb870758ce5c0d782386f223a8b404cf97a24de738d4edaa1b03282-image.png)


### 代码

```cpp
class Solution {
public:
    int getDays(string date)
    {
        int result;
        //1971-01-01
        int year = atoi(date.substr(0,4).c_str());
        int month = atoi(date.substr(5,2).c_str());
        int day = atoi(date.substr(8,2).c_str());
        
        //计算闰年次数
        int count = 0;
        for (int i=1971; i<year; i++)
        {
            if (i%400 == 0)
                count++;
            
            else if (i%4 == 0 && i%100 != 0)
                count++;
        }
        
        result = (year-1971)*365+count;
        bool bl = false;
        if (year%400 == 0 || (year%4 == 0 && year%100 != 0))
            bl = true;
        count = 0;
        for (int i=1; i<month; i++)
        {
            switch(i)
            {
                case 1:
                    count += 31;
                    break;
                case 2:
                    if (bl)
                    {
                        count += 29;
                        break;
                    }
                    else
                    {
                        count += 28;
                        break;
                    }
                case 3:
                    count += 31;
                    break;
                case 4:
                    count += 30;
                    break;
                case 5:
                    count += 31;
                    break;
                case 6:
                    count += 30;
                    break;
                case 7:
                    count += 31;
                    break;
                case 8:
                    count += 31;
                    break;
                case 9:
                    count += 30;
                    break;
                case 10:
                    count += 31;
                    break;
                case 11:
                    count += 30;
                    break;
                default:
                    break;
            }
        }
        result = result + count + day;
        
        return result;
    }
    int daysBetweenDates(string date1, string date2) {
        int days1 = getDays(date1);
        int days2 = getDays(date2);
        int result = abs(days1 - days2);
        return result;
    }
};
```