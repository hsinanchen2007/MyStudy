### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
    const int MAX = 2147483647;
    const int MIN = -2147483648;
public:
    int myAtoi(string str) {
        size_t length = str.length();
        size_t curIndex = 0;
        while (str[curIndex] == ' ') {
            curIndex++;
        }
        bool isNegative = false;
        if (curIndex < length && (str[curIndex] == '-' || str[curIndex] == '+')) {         
            isNegative = str[curIndex] == '-';
            curIndex++;
        }
        //if (curIndex < length && (str[curIndex] < '0' || str[curIndex] > '9')) {
        //    return 0;
        //}
        int res = 0;
        long long temp = 0;
        while (curIndex < length && str[curIndex] >= '0' && str[curIndex] <= '9') {
            temp = temp * 10 + (str[curIndex] - '0');
            //cout << temp << endl;
            if (temp - 1 >= MAX) {
                if (isNegative) {
                    return MIN;
                } else {
                    return MAX;
                }
            }
            curIndex++;
        }
        return isNegative ? -1 * (int)temp : (int)temp;
    }
};
```