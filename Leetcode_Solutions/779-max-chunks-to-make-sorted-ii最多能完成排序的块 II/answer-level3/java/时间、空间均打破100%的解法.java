### 解题思路
执行用时: **1 ms**, 在所有 Java 提交中击败了**100.00**%的用户
内存消耗: **39.7 MB**, 在所有 Java 提交中击败了**100.00**%的用户

### 代码

```java
class Solution {
    public int maxChunksToSorted(int[] arr) {
        int[] minStack = new int[arr.length];
        int[] maxStack = new int[arr.length];
        int p = 0;

        for (int i : arr) {
            if (p == 0 || i >= maxStack[p - 1]) {
                minStack[p] = i;
                maxStack[p] = i;
                p++;
                continue;
            }

            if (i > minStack[p - 1]) {
                continue;
            }

            minStack[p - 1] = i;

            int index = p - 2;
            while (index >= 0 && maxStack[index] > i) {
                index--;
            }
            index++;
            maxStack[index] = maxStack[p - 1];
            minStack[index] = minStack[p - 1];
            p = index + 1;
        }
        return p;
    }
}
```