# 代码
```java
class Solution {
    private LinkedList<String> res = new LinkedList<>();
    private boolean[] selected;
    private StringBuilder sb;
    private char[] ch_array;
    private int len;

    public String[] permutation(String S) {
        ch_array = S.toCharArray();
        Arrays.sort(ch_array);
        len = ch_array.length;
        sb = new StringBuilder(len);
        selected = new boolean[len];
        dfs(0);
        return res.stream().toArray(String[]::new);
    }

    private void dfs(int order) {
        if (order == len) {
            res.addLast(sb.toString());
            return;
        }
        for (int i = 0; i < len; ++i) {
            if (selected[i] ||
                    (i > 0 && !selected[i - 1] && ch_array[i - 1] == ch_array[i]))
                continue;
            sb.append(ch_array[i]);
            selected[i] = true;
            dfs(order + 1);
            sb.deleteCharAt(order);
            selected[i] = false;
        }
    }
}
```
