### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        int k=x;
        if(k<0) return false;
        long long n=0;
        while(k>0)
        {
            n = k%10 + n*10;
            k/=10;
        }
        return n==x;
    }
};
```
