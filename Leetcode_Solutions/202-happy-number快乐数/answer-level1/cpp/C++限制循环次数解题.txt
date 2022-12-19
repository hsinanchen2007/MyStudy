### 解题思路
直接按照题目说的做就行，这里需要设置一个次数来标记已经计算了多少次，如果计算10次还没有收敛到1，就可以认为是无限循环了。

### 代码

```cpp
class Solution {
public:
    bool isHappy(int n) {
        if(n<=0)
            return false;
        if(n==1)
            return true;
        int c=0;
        while(n!=1)
        {
            int tmp=0;
            int left=0;
            while(n>0)
            {
                left=n%10;
                tmp+=left*left;
                n=n/10;
            }
            n=tmp;
            c++;
            if(c>10)
                break;
        }
        if(c<=10)
            return true;
        return false;
    }
};
```