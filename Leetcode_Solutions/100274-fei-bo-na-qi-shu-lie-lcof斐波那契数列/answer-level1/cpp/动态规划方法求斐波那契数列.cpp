### 解题思路
此处撰写解题思路
本题可以使用递归来解决，但是使用递归的时间复杂度是O(n*n) 因为每个问题都可以分解成为两个问题取解决(n的问题可以分解为n-1,n-2去解决n-1,n-2也是同理)
这时候使用递归就不太合适了
现在使用动态规划的方法 时间复杂度是O(n) 空间复杂度是O(1)

### 代码

```cpp
class Solution {
public:
    int fib(int n) {
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
    }
};
```