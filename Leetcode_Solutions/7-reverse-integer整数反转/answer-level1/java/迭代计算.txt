### 解题思路
循环迭代，注意终止条件即可。
以1234为例，
sum: 0  -> 4  -> 43 -> 432 -> 4321
x: 1234 -> 123 -> 12 -> 1 -> 0 
### 代码

```java
class Solution {
    public int reverse(int x) {
       long sum = 0;
        while (x != 0){
            sum = x % 10 + sum * 10;
            x = x / 10;
        }
        return sum > Math.pow(2,31) || sum < Math.pow(-2,31) ? 0 : (int)sum;
    }
}
```