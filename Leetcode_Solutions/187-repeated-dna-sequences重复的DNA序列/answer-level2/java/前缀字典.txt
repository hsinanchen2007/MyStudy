### 解题思路
前缀字典，优化不够
![图片.png](https://pic.leetcode-cn.com/387ce0b250415836ec9493c3398119d91937a10b6d64062450905e04241f32b9-%E5%9B%BE%E7%89%87.png)

### 代码

```java
class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        List<String> result = new ArrayList<>();
        DnaDict dnaDict = new DnaDict();
        for (int i = 0; i < s.length() - 10 + 1; i++) {
            String match = handleDnaDict(dnaDict, s, i, i + 10);
            if (match != null) {
                result.add(match);
            }
        }
        return result;
    }

    class DnaDict {
        DnaDict[] next = new DnaDict[4];
        int count = 0;
    }

    private String handleDnaDict(DnaDict dict, String s, int start, int end) {
        for (int i = start; i < end; i++) {
            int idx = getDnaIndex(s.charAt(i));
            if (dict.next[idx] == null) {
                dict.next[idx] = new DnaDict();
            }
            dict = dict.next[idx];
        }
        dict.count ++;
        if (dict.count == 2) {
            return s.substring(start, end);
        }
        return null;
    }

    private int getDnaIndex(char c) {
        switch (c) {
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
            default: return -1;
        }
    }
}
```