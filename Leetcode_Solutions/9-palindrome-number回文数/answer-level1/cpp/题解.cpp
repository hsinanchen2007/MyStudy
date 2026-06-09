### 解题思路
刚从整数反转过来，就按照这个思路

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        int z=x;
        long y=0;
        while(x!=0)
        {
            y=y*10+x%10;
            x=x/10;
        }
        
        if(y==z&&z>=0)
        {
            return true;
        }
        else
        {
            return false;
        }
        
        
    }
};
```