### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        if (seq == "") {
            return null;
        }
        char[] cArr = seq.toCharArray();
        int[] ans = new int[seq.length()];
        int cnt = 0;
        for (int i = 0; i < seq.length(); i++) {
            if (cArr[i] == '(') {
                ++cnt;
                ans[i] = cnt % 2;
            } else {
                ans[i] = cnt % 2;
                --cnt;
            }
        }
        return ans;
    }
}
```