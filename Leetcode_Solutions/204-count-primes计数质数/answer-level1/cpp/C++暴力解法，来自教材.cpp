### 解题思路
郑莉的C++教材课后习题里有这个算质数的算法，算是很暴力的那种，这里改了一下就直接套上来了，执行用时773ms，击败了6.45%的用户，注意一定要算那个开方，不然效率更差。

### 代码

```cpp
class Solution {
public:
    int countPrimes(int n) {
        int i,j,k,flag;
        int p=0;
     for(i=2;i<n;i++)
     {
         flag = 1;
         k = sqrt(i);//这里涉及到一个算法的问题，不用算到i，到平方根就可以了，提升效率
         for(j=2;j<=k;j++)
         {
             if(i%j==0)
             {
                 flag = 0;
                 break;
             }
         }
         if(flag)
         p++;
     }
        return p;

    }
};
```