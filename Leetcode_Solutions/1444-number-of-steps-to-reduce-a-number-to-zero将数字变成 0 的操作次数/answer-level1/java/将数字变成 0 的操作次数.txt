### 解题思路
递归...

### 代码

```java
class Solution {
    private int step = 0;
    public int numberOfSteps (int num) {
        if(num %2 == 0) {
            num /= 2;
        } else {
            num -= 1;
        }
        step ++;
        if(num == 0) {
            return step;
        }
        return numberOfSteps(num);
    }
}
```