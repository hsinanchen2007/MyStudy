### 解题思路
每次都剔除奇数，剩下偶数，把偶数除以2，则变成了连续的整数，接着又可以每次剔除奇数，剩下偶数
当交换到从右边开始剔除时，如果最右边是奇数，则直接把所有奇数剔除，如果最右边是偶数，则把所有数加1，又可以愉快地剔除所有奇数了
### 代码
```cpp
class Solution {
public:
    int lastRemaining(int n) 
    {
        if (n == 1)
            return 1;
        div(n);
        return calcRmain();
    }
    int m[31];
    int len;
    void div(int n)
    {
        len = 0;
        while(n>1)
        {
            n >>= 1;
            m[len++] = n;            
        }
    }
    int calcRmain()
    {
        int p = 1;
        for(int i=len-2; i>-1; i--)
        {
            p <<= 1;            
            if (((i%2)==0) && ((m[i] % 2)==0))
                p -= 1;                        
        }
        return p<<1;
    }
};
```