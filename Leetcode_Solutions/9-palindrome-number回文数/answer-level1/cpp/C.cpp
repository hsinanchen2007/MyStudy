### 解题思路
执行用时 :8 ms, 在所有 C++ 提交中击败了95.60%的用户
内存消耗 :5.7 MB, 在所有 C++ 提交中击败了100.00%的用户,激动一下

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        else
        {long a=0,b=0;
        long y=x;
        while(y!=0)
        {a=y%10;
         b=b*10+a;
         y=y/10;
        }
         return b==x;
        }
        
    }
};
```