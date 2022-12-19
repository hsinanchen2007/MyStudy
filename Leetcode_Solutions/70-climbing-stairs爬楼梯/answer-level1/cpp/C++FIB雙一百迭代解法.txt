### 解题思路
因爲最後一步有兩種可能，一種是跳一步，另一種是跳兩步，因此加上這兩種情況的子情況數目即為所有可能組合，因此計算過程與fib求和類似，即兩種子條件下和為當前狀況的值，的只是基礎數据不同。
代碼見下。
### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
      return step(n);
    }
    int step(int n)
    {
        if(n==0) return 1;
        if(n==1) return 1;
        if(n==2) return 2;
        int a=1,b=2,c=2;
       for(int i=2;i<n;i++)
       {
           b=c;
           c=a+b;
           a=b;
       }
       return c;
    }
};
```