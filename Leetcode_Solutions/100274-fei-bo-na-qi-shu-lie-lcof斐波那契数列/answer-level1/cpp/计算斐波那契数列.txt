### 解题思路
此处撰写解题思路
注释的部分是第一次写的 vector是参看其他答案的。时间复杂度相同，空间复杂度原来是O(1)，vector版本是O(n)

### 代码

```cpp
class Solution {
public:
    int fib(int n) {
        /*
        int ResVal = 0,ResLast1=1,ResLast2 = 0;
        if(n==0)
        {
            return ResLast2;
        }else if(n==1)
        {
            return ResLast1;
        }else{
            for(int i=2;i<=n;i++)
            {
                ResVal = (ResLast1 + ResLast2) % 1000000007;
                ResLast2 = ResLast1;
                ResLast1 = ResVal;
            }
            return ResVal ;
        }
        */

        vector<int> Vec(n+1+1,0);
        Vec[1] = 1;
        for(int i=2;i<=n;i++)
        {
            Vec[i] = (Vec[i-1] + Vec[i-2]) % 1000000007;
        }
        return Vec[n];
    }
};
```