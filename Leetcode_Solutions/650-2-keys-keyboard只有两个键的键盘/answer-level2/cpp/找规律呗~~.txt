### 解题思路
n等于1直接返回0，n为质数返回本身，不是质数的话将n分解质因数，所有质因数相加就是结果。
![微信图片_20191211133247.png](https://pic.leetcode-cn.com/07908a13efcaa49bdf4b0fd7a93086d36dc1bfa4867e3fb9c6f7216588b8a28c-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20191211133247.png)
### 代码

```cpp
class Solution {
public:
    int minSteps(int n) {
        if(n==1)
        return 0;
        if(iszs(n))
        return n;
        int ans=0;
        for(int i=2;i<=sqrt(n)&&!iszs(n);i++){
            if(n%i==0)
            {ans+=i;
            n/=i;
            i=1;}
        }
        return ans+n;
    }
    bool iszs(int i){            //is zhishu
        if(i==1)
        return false;
        if(i<=3)
        return true;
        int q=sqrt(i);
        for(int u=2;u<=q;u++){
            if(i%u==0)
            return false;
        }
        return true;
    }
};
```