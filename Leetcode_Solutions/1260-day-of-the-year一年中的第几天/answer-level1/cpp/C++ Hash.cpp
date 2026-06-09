### 解题思路
思路比较简单，见代码。

运行结果如下
执行用时 :0 ms, 在所有 cpp 提交中击败了100.00%的用户
内存消耗 :8.1 MB, 在所有 cpp 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    //int days1 [12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days2[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    int dayOfYear(string date) {
        string str1 = date.substr(0, 4);
        string str2 = date.substr(5, 2);
        string str3 = date.substr(8, 2);
        int year = atoi(str1.c_str());
        int month = atoi(str2.c_str());
        int day = atoi(str3.c_str());
        int count = days2[month - 1] + day;
        if((year % 100 != 0 && year % 4 == 0 || year % 400 == 0) && month > 2){
            count += 1;
        }
        return count;
    }
};
```