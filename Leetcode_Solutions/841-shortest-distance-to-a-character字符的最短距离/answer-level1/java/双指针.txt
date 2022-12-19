### 解题思路
对于每个字符，如果自身为C则为0，否则设置双指针从中间向两边找，结果为两者距离的较小值.

### 代码

```java
class Solution {
    public int[] shortestToChar(String S, char C) {
        int len = S.length();
        int[] ans = new int[len];
        char[] arr = S.toCharArray();
        for (int i = 0; i < len; i++) {
            if (arr[i] == C) {
                ans[i] = 0;
                continue;
            }
            int left = i - 1, right = i + 1, l = Integer.MAX_VALUE, r = Integer.MAX_VALUE;
            while (left - 1 >= 0 && arr[left] != C) left--;
            while (right + 1 < len && arr[right] != C) right++;
            if (left >= 0 && arr[left] == C) l = i - left;
            if (right < len && arr[right] == C) r = right - i;
            ans[i] = Math.min(l, r);
        }
        return ans;
    }
}
```