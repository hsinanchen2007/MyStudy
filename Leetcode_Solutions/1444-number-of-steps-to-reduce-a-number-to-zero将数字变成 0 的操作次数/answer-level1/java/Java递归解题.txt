### 解题思路
此处撰写解题思路
1和2是特殊情况(其实2也可以再次转变)，
如果num是奇数，那么次数就是num-1的次数加一；否则就是num/2的次数加一，以此作为递归条件即可。

### 代码

```java
class Solution {
    public int numberOfSteps (int num) {
        if (num == 1 || num == 2) {
            return num;
        }
        if (num % 2 == 0) {
            return 1 + numberOfSteps(num / 2);
        }
        return 1 + numberOfSteps(num - 1);
    }
}
```