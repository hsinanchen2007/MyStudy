### 解题思路
这一题至少有几道类似的题目，2的幂，3的幂，4的幂之类。
开始的时候没有加 i < Math.sqrt(Integer.MAX_VALUE)，导致判断某些数的时候陷入了死循环。
这是i * i > Integer.MAX_VALUE之后就会重新从计算。导致一直无法推出循环。
所以需要给i限定一个范围。
### 代码

```java
class Solution {
    public boolean isPerfectSquare(int num) {
        int i;
        for(i = 0; i * i < num && i < Math.sqrt(Integer.MAX_VALUE); i++);
        return i*i == num;
    }
}
```