### 解题思路
循环R-L，每次循环内统计二进制时1的个数，然后判断是否质数。
![image.png](https://pic.leetcode-cn.com/43bc26a5d431f3afcd345e1a3269a955b2d1bfa4a851a0fa60d7e0dd882c08f3-image.png)

### 代码

```cpp
class Solution {
public:
    bool iszhishu(int n)
    {
        if(n<2) return false;
        if(n==3) return true;
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int L, int R) {
        int count=0;
        for(int sum=0,value=0;L<=R;L++)
        {
            sum=0;
            value=L;
            while(value)
            {
                sum++;
                value=value&(value-1);
            }
            if(iszhishu(sum)) count++;
        }
        return count;
    }
};
```