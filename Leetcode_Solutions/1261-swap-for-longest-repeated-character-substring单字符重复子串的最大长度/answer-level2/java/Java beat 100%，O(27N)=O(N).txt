优化后

```
class Solution {
    public int maxRepOpt1(String text) {
        if (null == text || text.length() == 0) return 0;
        int[] nums = new int[26];
        for (int i = 0; i < text.length(); i++) {
            nums[text.charAt(i) - 'a']++;
        }
        
        int res = 0;
        for (int j = 0; j < text.length() - 1; j++) {
            int curCount = 1;
            int recoverJ = j;
            boolean firstDiffer = true;
            char ch = text.charAt(j);
            // 要么第一次遇到不同字符，要么跟自己一样的字符
            while (j < text.length() - 1 && (firstDiffer || ch == text.charAt(j + 1))) {
                if (ch != text.charAt(j + 1)) {
                    firstDiffer = false; 
                    recoverJ = j;
                }
                j++;
                curCount++;
            }
            j = recoverJ;
            // 不能比字符串中该字符的次数更大
            curCount = Math.min(nums[ch - 'a'], curCount);
            res = Math.max(curCount, res);
        }
        
        return res;
    }
}
```

还有优化的空间。现在这样设计的实现很快。
优化前。
```
class Solution {
    public int maxRepOpt1(String text) {
        if (null == text || text.length() == 0) return 0;
        int[] nums = new int[26];
        for (int i = 0; i < text.length(); i++) {
            nums[text.charAt(i) - 'a']++;
        }
        
        int res = 0;
        for (int i = 0; i < 26; i++) {
            char ch = (char)('a' + i);
            for (int j = 0; j < text.length() ; j++) {
                int curCount = 0;
                boolean firstDiffer = true;
                // 要么第一次遇到不同字符，要么跟自己一样的字符
                while (j < text.length() && (firstDiffer || text.charAt(j) == ch)) {
                    if (text.charAt(j) != ch) {
                        firstDiffer = false; 
                    }
                    j++;
                    curCount++;
                }
                // 不能比字符串中该字符的次数更大
                curCount = Math.min(nums[ch - 'a'], curCount);
                res = Math.max(curCount, res);
            }
        }
        return res;
    }
}
```

