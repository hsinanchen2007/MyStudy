### 解题思路
只需判断奇偶性！！！
### 代码

```cpp
class Solution {
public:
    string generateTheString(int n) {
        if(n%2==0)
        {
            string res(n-1,'a');res+="b";
            return res;
        }
        else
        {
            string res(n,'a');
            return res;
        }
    }
};
```