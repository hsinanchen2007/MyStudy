### 解题思路
我想讲nums1的无效数字用nums2覆盖，然后排序；
但是很迷，这个n是干嘛的？望大神告知，题目也不是看得很懂，总之很混，可能是样例过少，所以跑通了。
执行用时 :1 ms, 在所有 Java 提交中击败了27.28%的用户
内存消耗 :39.9 MB, 在所有 Java 提交中击败了5.01%的用户

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        for (int i = 0; i < nums2.length; i++) {
            nums1[m++] = nums2[i];
        }
        Arrays.sort(nums1);
    }
}
```