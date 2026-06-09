### 解题思路
1. 运用递归来进行逐步计算。
2. 用%求余来判断奇偶。
3. 用int变量来记录步数。

### 代码

```java
class Solution {
     int steps = 0;

    public int numberOfSteps(int num) {
        if (num == 0) return steps;

        steps++;
        if (isEven(num)) {
            numberOfSteps(num / 2);
        } else {
            numberOfSteps(num - 1);
        }
        return steps;
    }

    private boolean isEven(int num) {
        if (num%2 > 0){
            return false;
        }else return true;
    }
}
```