利用KMP算法的next数组的思想，求最后一个的next值即可。

```
    public String longestPrefix(String s) {
        int[] next = calNext(s + " ");
        return s.substring(0, next[s.length()]);
    }
    
     public int[] calNext(String pattern) {
        int[] next = new int[pattern.length()];
        next[0] = -1;
        int k = -1; // 前缀索引
        int j = 0; // 后缀索引
        while (j < pattern.length() - 1) {
            if (k == -1 || pattern.charAt(k) == pattern.charAt(j)) {
                k++;
                j++;
                next[j] = k; 
            } else {
                k = next[k];
            }
        }
        return next;
    }
```
