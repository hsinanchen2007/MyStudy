### 解题思路
使数组中元素**唯一**，那么只要将**重复元素**不断地去掉就行了，而这里地去掉只能通过**加1**来完成，所以只需要对数组元素做统计后，将个数大于2的元素保留1个，其余都加1，注意加1操作直接更新统计数组就行。
比如数组`[3, 2, 1, 2, 1, 7]`,
![img.jpg](https://pic.leetcode-cn.com/041ca30d901b2960de5b5f6323e10d3da0321e58cdd31508016f5c5142307e10-img.jpg)


### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        int maxLen = 80001;
        int[] count = new int[maxLen];
        int minOps = 0;
        for (int a: A) {
            count[a]++;
        }
        for (int i = 0; i < maxLen - 1; i++) {
            if (count[i] >= 2) {
                int move = count[i] - 1;
                minOps += move;
                count[i + 1] += move;
            }
        }
        return minOps;
    }
}

```