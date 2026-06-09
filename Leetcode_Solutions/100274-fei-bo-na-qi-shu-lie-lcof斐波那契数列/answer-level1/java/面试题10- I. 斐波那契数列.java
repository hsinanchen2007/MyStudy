### 解题思路
初次尝试使用递归法：
 →超出时间限制。

第二次尝试使用动态规划：实际就是三个临时变量，交替存储F(N - 1)和F(N - 2)的值
 →当n逐渐变大时，F(N)的值超出int取值范围，导致结果错误。

第三次尝试在每次计算时都取模%1000000007，将其带入计算。
 →→(a+b)%p = (a%p+b%p)%p

**证明**：
a = t1*p + a%p
b = t2*p + b%p
→ (a+b)%p = ((t1*p + a%p) + (t2*p + b%p)) %p
          = ((t1+t2)*p + a%p + b%p) %p
          = (a%p + b%p) %p

时间复杂度：O(n)，空间复杂度O(1)

### 代码

```java
class Solution {
    public int fib(int n) {
        if(n==0||n==1){
            return n;
        }
        int a=0,b=1;
        int sum=0;
        for(int i=2;i<=n;i++){
            sum=(a+b)%1000000007;
            a=b;
            b=sum;
        }
        return sum;
    }
}
```