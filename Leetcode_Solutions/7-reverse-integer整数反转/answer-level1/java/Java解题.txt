### 解题思路
如下

### 代码

```java
class Solution {
    public int reverse(int number) {
        long resultNumber = 0;
        while (number != 0){
            //判断数据溢出
            if ( resultNumber >  Integer.MAX_VALUE /10 || (long)resultNumber < Integer.MIN_VALUE /10) return 0;
            //取得最后一位数
           int add =  number % 10;
           //每次循环乘10 加上最后一位数
           resultNumber = resultNumber * 10 + add;
            //参数减少一位数
            number /= 10;
        }
        return (int) resultNumber;
    }
}
```