### 解题思路
若char数组长度为0或1，直接返回；
若长度大于1，左右双指针直接进行逐位交换，直到重合或者left>right后停止；
（执行用时 :1 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :43.5 MB, 在所有 Java 提交中击败了99.67%的用户）

### 代码

```java
class Solution {
    public void reverseString(char[] s) {
        if (s.length <= 1) {
            return;
        }
        int left = 0;
        int right = s.length - 1;
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
}
```