执行用时 :1 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :33.8 MB, 在所有 java 提交中击败了49.47%的用户

充分利用题设：`pattern 只包含小写字母`
还有后半句：`str 包含了由单个空格分隔的小写字母`，可能也有玄机。还不知道如何利用。    
  
还有，不要用`replace/replaceAll`，效率不行。

```
public boolean wordPattern(String pattern, String str) {
    // 0 先用长度做简单的判断
    String[] words = str.split(" ");
    if (words.length != pattern.length()) {
        return false;
    } else {
        // 充分利用 "pattern 只包含小写字母"的条件
        String[] alphaArr = new String[26];

        for (char c = 'a'; c <= 'z'; c++) {
            int idx = pattern.indexOf(c);
            if (-1 != idx) {
                if (Arrays.asList(alphaArr).contains(words[idx])) {
                    return false;
                }

                alphaArr[c - 'a'] = words[idx];
            }
        }

        for (char c = 'a'; c <= 'z'; c++) {
            if (null != alphaArr[c - 'a']) {
                int index = pattern.indexOf(c);
                int lastIdx = pattern.lastIndexOf(c);

                boolean isLast = false; // 是否已比对到该字母最后出现的位置

                // 将字母出现的位置，逐一和单词进行比较
                while (index <= lastIdx) {
                    if (isLast) {
                        break;
                    }

                    if (! words[index].equals(alphaArr[c - 'a'])) {
                        return  false;
                    }

                    if (index == lastIdx) {
                        isLast = true;
                    }

                    int fromIdx = Math.min(index + 1, lastIdx);
                    index = pattern.indexOf(c, fromIdx);
                }

            }
        }
        return true;
    }
}
```
