### 依次考虑每一个字符留下来/不留(删去)

*比较朴素的做法, 不过应该比较好理解.*

```java
/**
 * 回溯法, (搜索, dfs), 依次考虑每一个字符:
 * - 如果是左括号, 那么枚举留下来/不留下来
 * - 如果是右括号, 可以不留下来, 在合法的情况可以留下来
 * - 如果是非括号, 那么必须留下来
 * 不要忘了在回溯的时候 delete 字符
 */
class Solution {
    private int maxLength;

    public List<String> removeInvalidParentheses(String s) {
        maxLength = 0;
        char[] str = s.toCharArray();
        Set<String> set = new HashSet<>();
        StringBuilder cur = new StringBuilder();
        dfs(cur, 0, 0, 0, str, set);
        return new ArrayList<>(set);
    }

    /**
     * @param cur   当前字符串
     * @param left  cur 中左括号的数量
     * @param right cur 中右括号的数量
     * @param i     下一个字符的下标 (str数组)
     * @param str   原始字符串
     * @param set   合法字符串集合 (留下不同位置的字符可能得到相同的字符串, 所以使用集合)
     */
    private void dfs(StringBuilder cur, int left, int right, int i, char[] str, Set<String> set) {
        if (i == str.length) {
            // 无论是左括号还是右括号, 都优先考虑留下来, 所以第一次达到的合法情况一定是最长的
            if (left == right && (cur.length() == maxLength || maxLength == 0)) {
                maxLength = cur.length();
                set.add(cur.toString());
            }
            return;
        }
        char c = str[i];
        if (c != '(' && c != ')') {     // 非括号字符, 必须留下来
            cur.append(c);
            dfs(cur, left, right, i + 1, str, set);
            cur.deleteCharAt(cur.length() - 1);
            return;
        }
        if (c == '(') {                 // 左括号, 留下来
            cur.append(c);
            dfs(cur, left + 1, right, i + 1, str, set);
            cur.deleteCharAt(cur.length() - 1);
        } else if (left > right) {      // 右括号, 在 left > right 时才可以留下来
            cur.append(c);
            dfs(cur, left, right + 1, i + 1, str, set);
            cur.deleteCharAt(cur.length() - 1);
        }
        dfs(cur, left, right, i + 1, str, set);  // 不留下来当前字符
    }
}
```