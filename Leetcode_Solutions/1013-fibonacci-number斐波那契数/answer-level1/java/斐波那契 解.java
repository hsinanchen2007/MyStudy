### 解题思路
for(int i =0;i<n-1;i++){
            sum=one+scend;//这里是实现斐波那契规律，n=(n-2)+(n-1)
            one=scend; //然后，依次往后面推数。
            scend=sum;
        }
        return sum ;//返回最后的值

### 代码

```java
class Solution {
    public static int fib(int n) {
        if(n<=1) return n;
        int one =0;
        int scend=1;
        int sum=0;
        for(int i =0;i<n-1;i++){
            sum=one+scend;//这里是实现斐波那契规律，n=(n-2)+(n-1)
            one=scend; //然后，依次往后面推数。
            scend=sum;
        }
        return sum ;//返回最后的值
    }
}
```