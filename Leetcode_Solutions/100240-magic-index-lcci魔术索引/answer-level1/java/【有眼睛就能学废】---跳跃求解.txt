执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :41.1 MB, 在所有 Java 提交中击败了100.00%的用户
### 解题思路
根据数组有序这一性质，假设A[i]=n,如果n>i，则可知在索引i~~n之间的元素值都是大于索引的（即A[i] < n）,我们可以直接跳跃到索引n处，比较n和A[n]的关系。依次往后类推，直到找到第一个A[i]=i的索引，或者查找到数组最后一个元素。如果在索引i处，A[i] < i,则i++即可。

### 代码

```java
class Solution {
    public int findMagicIndex(int[] nums) {
        int start = 0;
        int index = -1;
        while (start < nums.length) {
            int n = nums[start];
            if (n == start) {
                index = n;
                break;
            } else if (n > start) {
                start += n;
            } else {
                start++;
            }
        }
        return index;
    }
}
```