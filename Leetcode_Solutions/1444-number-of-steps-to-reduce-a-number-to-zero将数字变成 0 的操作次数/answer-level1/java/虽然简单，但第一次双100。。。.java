### 解题思路
![image.png](https://pic.leetcode-cn.com/da5d58b73beb4a3adbd56a096f49e4a3bc0be4e1ceb891edb708e4250542d6ab-image.png)

### 代码

```java
class Solution {
    public int numberOfSteps (int num) {
        int step = 0;
        while (num > 0) {
            if (num % 2 == 0) {
                num = num / 2;
                step++;
            } else {
                num -= 1;
                step++;
            }
        }
        return step;
    }
}
```