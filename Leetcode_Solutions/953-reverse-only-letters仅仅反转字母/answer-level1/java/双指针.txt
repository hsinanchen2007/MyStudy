执行用时 : 1 ms, 在Reverse Only Letters的Java提交中击败了99.61% 的用户
内存消耗 : 33.8 MB, 在Reverse Only Letters的Java提交中击败了98.05% 的用户

```
public class Solution {

   public String reverseOnlyLetters(String s) {
        if (s == null || s.length() <= 1) {
            return s;
        }
        int l = 0;
        int r = s.length() - 1;
        char[] arr = s.toCharArray();
        while (l < r) {
            char lc = arr[l];
            if (lc < 'A' || (lc > 'Z' && lc < 'a') || lc > 'z') {
                l++;
                continue;
            }
            char rc = arr[r];
            if (rc < 'A' || (rc > 'Z' && rc < 'a') || rc > 'z') {
                r--;
                continue;
            }
            arr[l++] = rc;
            arr[r--] = lc;
        }
        return new String(arr);
    }

}
```