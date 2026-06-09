### 解题思路
此处撰写解题思路
string 转为 integer
### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
        istringstream iss(str);
        long long ans;
        iss >> ans;
        
        if(ans > INT_MAX) return INT_MAX;
        if(ans < INT_MIN) return INT_MIN;
        if(!iss.fail()) return ans;
        else return 0;
    }
};
```