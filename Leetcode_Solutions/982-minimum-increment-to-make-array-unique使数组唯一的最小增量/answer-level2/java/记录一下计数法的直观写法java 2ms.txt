执行用时 :2 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :48.2 MB, 在所有 Java 提交中击败了74.51%的用户
### 解题思路
这里动态给出计数数组的长度（max(数组长度,数组中最大值)）。
如果不进行遍历，可以直接赋值数值数值范围的2倍（80000）为数组长度。
在遍历计数数组的时候，若当前数值大于1，则需要进行累加。
如果前一个累加没有结束，那么再加上当前数值减1。
这里采用，currentNum记录当前数的统计减1的和。
统计结束后，若currentNum非0，那么这里还需要进行累加求和。--currentNum，一直到currentNum等于0为止。
此步骤优化：可以采用数学公式计算。


### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        int maxSize = A.length;
        for(int i = 0; i < A.length; ++i) {
            if (A[i] > maxSize) maxSize = A[i];
        }
        int[] baseArr = new int[maxSize+1];
        for(int i = 0; i < A.length; ++i) {
            baseArr[A[i]] += 1;
        }
        int stepSum = 0;
        int currentNum = 0;
        for(int i = 0; i <= maxSize; ++i) {
            // 前一个累加没有结束，那么再加上当前数值减1。
            currentNum += baseArr[i] - 1;
            if (currentNum > 0) {
                stepSum += currentNum;
            } else {
                // 如果currentNum为负数，则需要赋值为0
                currentNum = 0;
            }
        }
        while(currentNum > 0) {
            stepSum += --currentNum;
        }

        return stepSum;
    }
}
```