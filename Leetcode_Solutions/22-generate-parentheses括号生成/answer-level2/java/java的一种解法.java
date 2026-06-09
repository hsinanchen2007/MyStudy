### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private List<String> lst;
    public List<String> generateParenthesis(int n) {
        if (n <= 0)
            return new ArrayList<>();

        lst = new ArrayList<>();
        helper(n, n, new StringBuilder());
        return lst;
    }

    private void helper(int left, int right, StringBuilder sb) {

        if (left <0 || right <0)
            return;
        if (left == 0 && right ==0) {
            lst.add(sb.toString());
            return;
        }

        if (left > 0) {
            helper(left - 1, right, sb.append("("));
            sb.deleteCharAt(sb.length()-1);
        }
        if (right > left) {
            helper(left, right - 1, sb.append(")"));
            sb.deleteCharAt(sb.length()-1);
        }
    }
}
```