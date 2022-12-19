### 解题思路
思路就是将反转的数字和原来的进行比较，主要参考题号7整数翻转.
### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
           return false;
        if(x<10)
           return 10;
        int origin=x;//记录下原始的x
        int res=0;
        while(x!=0)
        {
            int pop=x%10;
            if(res>2147483647/10||(res==2147483647/10&&pop>7))
            return false;
            res=res*10+pop;
            x=x/10;
        }
        return (origin==res);
    }
};
```