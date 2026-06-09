## 解法一
思路：直接暴力减法肯定会超时，比如被除数等于2^32，除数等于1，那么用时就是2^32，20亿次的运算，好点的CPU也得几秒钟，肯定超时，直接忽略这种做法，但这个思路是可以继承的。

不用每次只是减去除数，而是减去一个2的幂次，不能用乘法运算，但是可以用移位运算来形成2的幂次，然后使用被除数减去2的幂次来加快计算效率，实际执行如下：（search递归函数）
1. 被除数 = 除数 * 2^a + b
2. 满足公式的最大a，然后递归将b作为被除数
3. 直到被除数小于除数为止
4. 将所有的2^a进行求和
另外，为了防止整数溢出的情况，使用了负数进行减法运算。
```csharp
public class Solution {

    public int search(int m,int n)
    {
        if(m > n) return 0;//当被除数比除数的绝对值还小的时候结束

        int k = -1, t = n;
        while(m < t && m - t < t)
        {//使用2的幂次进行求解
            t <<= 1;
            k <<= 1;
        }
        return  k + search(m - t,n);
    }

    public int Divide(int dividend, int divisor) {
        int mFlag = dividend>0?-1:1;
        int nFlag = divisor>0?-1:1;
        int flag = -1* mFlag * nFlag; 
        //将值转换为负值进行计算
        int m = dividend * mFlag, n = divisor * nFlag;

        int r = search(m,n);
        if(r == -2147483648 && flag == -1)
        {//只有一种情况溢出，就是最小负值转换为正值时
            return 2147483647;
        }
        
        return r * flag;        
    }
}
```
![在这里插入图片描述](https://pic.leetcode-cn.com/a384f497c23657b2831e29dc4e39d98fb467810418f3789c2297d18142281ebf.png)
## 解法二
思路：
基于第一种解法的变种，商作为一个值，是由二进制组成，那么现在就是要寻找哪些二进制的值为1，只要将除数乘以2^i^可以被除，那其对应位置的值即为1，直到最后，这样就省去了递归的栈空间消耗，代码如下：
被除数 = 除数 * (2^n+2^i...+2^0) + b

```csharp
public class Solution {
    public int Divide(int dividend, int divisor) {
        int mFlag = dividend>0?-1:1;
        int nFlag = divisor>0?-1:1;
        int flag = -1* mFlag * nFlag; 
        //将值转换为负值进行计算        
        int m = dividend * mFlag, n = divisor * nFlag;
        int r=0, k = 0;
        while(m<n && m-n<=n)
        {//找最大的幂次
            n <<= 1;
            k ++;
        }
        while(k>=0)
        {
            if(m<=n)
            {//第k个二进制位为1
                m -= n;
                r += (-1 << k);
            }
            n >>= 1;
            k--;
        }
        if(r == -2147483648 && flag == -1)
        {//只有一种情况溢出，就是最小负值转换为正值时
            return 2147483647;
        }
        
        return r * flag;        
    }
}
```

![在这里插入图片描述](https://pic.leetcode-cn.com/45af8408aa400e529457e6ed5bef81bd86edd7d6d72b14aaf603dfad1d0db887.png)