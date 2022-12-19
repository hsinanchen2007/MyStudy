### 解题思路

- 首先我们要计算出数组中需要移动的数字数量，也就是`sum(数组中重复的数字数量 - 1)`, 同时计算需要移动的次数`count += flag[i] - 1`，因为有一个数字要放在原来位子，所以要-1
- 之后我们要占到数组中出现次数为0的数字，并把移动的数字数量 + move 的次数 和移动的次数分别 - 1
- 返回move次数即可

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        int[] flags = new int[80000];

        for (int i : A) {
            flags[i]++;
        }

        int move = 0, count = 0;
        for (int i = 0; i < flags.length; i++) {
            if (flags[i] > 1) {
                move -= (i * (flags[i] - 1)); // 要移动的元素格式
                count += flags[i] - 1;
            } else if (count > 0 && flags[i] == 0) {
                count --;
                move += i;
            }
        }

        return move;
    }
}
```