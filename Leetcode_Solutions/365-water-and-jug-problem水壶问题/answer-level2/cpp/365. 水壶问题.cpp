![image.png](https://pic.leetcode-cn.com/ca5fe3a1ebcb76ecdef6c891dfac93199c48afa61150e3ad407093ce8bd9d5af-image.png)


### 解题思路
首先先明确，装水范围是0-x+y，你打个表就会发现其实每次都是获得的水量是x和y的线性组合，当然啦官方题解也说明了这一点，之后呢运用裴蜀定理ax+by=z当且仅当z%gcd(a,b)==0，判断一下就好了，当然在这题中z<=x+y

### 代码

```cpp
class Solution {
public:
    inline int gcd(int x,int y)
    {
        return !y?x:gcd(y,x%y);
    }
    bool canMeasureWater(int x, int y, int z) {
        if(x==y)
        {
            return z==x||!z?true:false;
        }
        return z%gcd(x,y)==0&&z<=x+y?true:false;
    }
};
```