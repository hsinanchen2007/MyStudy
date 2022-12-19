### 解题思路：

这道题目的关键是 `按字典序排列小于 A 的最大可能排列`， 那么有

- 对当前序列进行**逆序**查找，找到第一个降序的位置 `i`，使得 $A[i]>A[i+1]$

  - 由于 $A[i]>A[i+1]$，必能构造比当前字典序小的序列
  - 由于逆序查找，交换 `A[i]` 为最优解

- 寻找在 `A[i]` 最左边且小于 `A[i]` 的最大的数字 `A[j]`

  - 由于 $A[j] < A[]i]$, 交换 `A[i]` 与 `A[j]` 后的序列字典序一定小于当前字典序
  - 由于 `A[j]` 是满足关系的最大的最左的，因此一定是满足小于关系的交换后字典序最大的

  > 这里的两条，最大和最左边缺一不可，可以结合样例
  >
  > [3, 1, 1, 3] => [1, 3, 1, 3]
  >
  > [3, 1, 2, 3] => [2, 1, 3, 3]
  >
  >
  >
  > [4, 1, 2, 3] => [3, 1, 2, 4]
  >
  > 理解

### 解题方案：【字典序】 ( 1ms)

> 执行用时 : `1 ms`，在 `Previous Permutation With One Swap` 的 `Java` 提交中击败了 `90.41%` 的用户。
>
> 内存消耗 : `50.9 MB`，在 `Previous Permutation With One Swap` 的 `Java` 提交中击败了 `100.00%` 的用户。

```java [-Java]
class Solution {
    public int[] prevPermOpt1(int[] A) {
        int len = A.length;
        int curMax = -1;
        int index = -1;
        boolean hasResult = false;
        for (int i = len - 2; i >= 0; i--) {
            if (A[i+1] < A[i]) {                    // 此处逆序，需要移动A[i]
                for (int j = i + 1; j < len; j++) { // 寻找与 A[i] 交换的位置
                   if (A[i] > A[j]) {               // 必须满足 A[i] > A[j]，否则不能满足交换后的字典序小于原始字典序
                        hasResult = true;
                        if (A[j] > curMax) {        
                            curMax = A[j];
                            index = j;
                        }
                   } 
                }
                if (hasResult) {
                    int tmp = A[i];
                    A[i] = A[index];
                    A[index] = tmp;
                    return A;
                }
            }
        }
        return A;
    }
}
```

#### 复杂度分析:

时间：$O(N)$

空间：$O(1)$







