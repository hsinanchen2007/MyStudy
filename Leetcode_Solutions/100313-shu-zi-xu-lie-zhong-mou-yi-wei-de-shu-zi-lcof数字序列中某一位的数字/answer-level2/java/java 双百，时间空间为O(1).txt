### 解题思路
解题：

 * 位数  目标数范围    数字个数
 * 1    1-9         9 × 1
 * 2    10-99       90 × 2
 * 3    100-999     900 × 3
 * k    10^(k-1)-(10^k)-1  9*10^(k-1) * k
 * 1.确定目标数是几位数
 * 2.确定目标数的数值
 * 3.确定返回目标数中的第几位
### 代码

```java
class Solution {
    public int findNthDigit(int n) {
        if (n <= 9)
            return n;
        n--;
        int num = 1;// 位数
        long first = 1; // 当前范围内第一个数， 注意越界。
        while (n > 9 * first * num){
            n -= 9 * first * num;   // 让n在循环结束后表示当前范围的第n位数字
            num++;
            first *= 10;
        }
         // 如 456 = 100(first)  +  356（n/num）  n%num 这里表示 456 中的第几位数字 
        return String.valueOf(first + n / num).charAt(n % num) - '0';
    }
}
```