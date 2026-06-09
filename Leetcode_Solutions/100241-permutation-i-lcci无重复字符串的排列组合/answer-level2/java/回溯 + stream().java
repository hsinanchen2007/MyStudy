# PS:
也可以不使用stream()，根据S.length()求其**阶乘**，即可得到最终要返回的String[]数组长度。
只不过懒得这样写，有兴趣可以自行尝试。
# 代码
```java
class Solution {
    private LinkedList<String> res = new LinkedList<>();
    private boolean[] selected;
    private StringBuilder sb;
    private String global_S;
    private int len;

    public String[] permutation(String S) {
        len = S.length();
        global_S = S;
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
            if (selected[i])
                continue;
            sb.append(global_S.charAt(i));
            selected[i] = true;
            dfs(order + 1);
            sb.deleteCharAt(order);
            selected[i] = false;
        }
    }
}
```
