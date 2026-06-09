![image.png](https://pic.leetcode-cn.com/c5e866b588909bf34e26b744f8b16aa416b3cc43dfc6289d3cfa76ca40f15738-image.png)

```
class Solution {
public:
    int waysToStep(int n) {
        if(n<0)
            return 0;
        if(n==0)
            return 1;
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        if(n==3)
            return 4;
        long long int a=1;
        long long int b=2;
        long long int c=4;
        for(int i(3);i<n;i++)
        {
            long long int temp=c;
            c=(a+b+c)%1000000007;
            a=b;
            b=temp;
        }
        return c;
    }
};
```
