### 解题思路
二分法，如果重复元素，找重复元素中的最后一个值。

### 代码

```java
class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int len = letters.length;

        int start = 0, end = len - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (letters[mid] < target) {
                start = mid + 1;
            } else if (letters[mid] > target) {
                end = mid - 1;
            } else {
                start = mid;
            }
        }

        if(letters[end] <= target) {
            return letters[(end + 1) % len];
        }
        return letters[end];
    }
}
```