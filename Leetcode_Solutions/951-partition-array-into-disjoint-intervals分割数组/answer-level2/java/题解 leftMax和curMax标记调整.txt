### 解题思路
时间复杂度：O(n)，空间复杂度：O(1)，leftMax表示左侧最大值，curMax表示当前最大值，index用于标记左右分割的下标（即左子数组的结束下标）。遍历数组，当leftMax小于当前元素时则更新curMax，当leftMax大于当前元素时则更新边界下标index，并将当前leftMax更新为curMax。根据题意，当leftMax等于当前元素时无需更新左子数组（要求左子数组尽可能小）
![批注 2019-12-07 152211.png](https://pic.leetcode-cn.com/8655aa7a2dc0f629cbcf5f8bc9327a51c838a58ad14e46d1735663be29dbeb13-%E6%89%B9%E6%B3%A8%202019-12-07%20152211.png)
### 代码

```java
class Solution {
    public int partitionDisjoint(int[] A) {
        int leftMax = A[0], curMax = A[0], index = 0;
        for(int i = 1; i < A.length; i++) {
            if (leftMax < A[i]) {
                curMax = Math.max(curMax, A[i]);
            } else if(leftMax > A[i]){
                index = i;
                leftMax = curMax;
            }
        }
        return index + 1;
    }
}
```