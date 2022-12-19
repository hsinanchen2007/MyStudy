### 解题思路
利用stringstream流函数

### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
        int num=0;
        stringstream ss;
        ss << str;//可以是其他数据类型
        ss >> num; //string -> int
        if (num > INT_MAX)
            return INT_MAX;
        else if (num < INT_MIN)
            return INT_MIN;
        else
            return num;
    }
};
```