### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        int y=0;
        if(x%10==0 and x!=0) return false;
        while(x>=y){
            if(y==x or y==x/10) return true;
            y=y*10+x%10;
            x=x/10;
        }
        return false;
    }
};
```