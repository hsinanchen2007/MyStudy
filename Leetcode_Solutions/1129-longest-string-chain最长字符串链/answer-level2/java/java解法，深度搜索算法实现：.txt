java解法，深度搜索算法实现：

执行用时 :12 ms, 在所有 java 提交中击败了99.50%的用户
内存消耗 :38.2 MB, 在所有 java 提交中击败了100.00%的用户


```
class Solution {
    private int Max = 1;
    public int longestStrChain(String[] words) {
        if (words.length == 0) return 0;
        int  minlen = words[0].length();
        int maxlen = minlen;
        Map<Integer, Set<String>> map = new HashMap<>();
        for (String word : words) {
            int len = word.length();
            minlen = Math.min(minlen, len);
            maxlen = Math.max(maxlen, len);
            Set<String> set = map.get(len);
            if (set == null) {
                set = new HashSet<>();
                map.put(len, set);
            }
            set.add(word);
        }

        for (int len = minlen; len <= maxlen; len++) {
             Set<String> oneSet = map.get(len);
             if (oneSet == null) break;
             if (maxlen + 1 - len <= Max) break;
             
             for (String a: oneSet) {
                 findNext(map, len, a);
             }
        }

        return Max;
    }

    private void findNext(Map<Integer, Set<String>> map, int start, String base) {
        Max = Math.max(Max, (base.length() + 1) - start);
        Set<String> set = map.get(base.length() + 1);
        if (set == null) {
            return;
        }

        Iterator<String> iterator = set.iterator();
        while (iterator.hasNext()) {
            String one = iterator.next();
            if (match(base, one)) {
                findNext(map, start, one);
                iterator.remove();
            }
        }
    }

    private boolean match(String base, String next) {
        int i = 0;
        int len = base.length();
        while (i < len && next.charAt(i) == base.charAt(i)) {
            i++;
        }
        
        if (i == len) return true;

        while (i < len && next.charAt(i + 1) == base.charAt(i)) {
            i++;
        }
        
        return i == len;
    }
}
```


