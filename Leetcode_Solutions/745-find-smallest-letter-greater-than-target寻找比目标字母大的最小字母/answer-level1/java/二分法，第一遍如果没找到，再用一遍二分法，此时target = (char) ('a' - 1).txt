### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        //Arrays.sort(letters);
        int ans = binarySearch(letters, target);
        if (ans == letters.length) {
            ans = binarySearch(letters, (char) ('a' - 1));
        }
        return letters[ans];
    }

    private int binarySearch(char[] letters, char target) {
        int lo = 0;
        int hi = letters.length;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (letters[mid] > target) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
}
```