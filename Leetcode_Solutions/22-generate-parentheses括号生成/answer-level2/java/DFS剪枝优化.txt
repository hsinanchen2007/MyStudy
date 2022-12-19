### 解题思路
在进行深搜遍历时，不是遍历所有的可能结果，用两个变量计数左括号的数量以及左括号与右括号抵消后的数量（此计数值用来判断能否继续添加右括号）。当左括号的数量小于n时，可添加左括号；当左括号抵消后的数量大于0时，可添加右括号，得出的括号自负床一定是有效的，不必再进行有效性判断。

### 代码

```java
class Solution {

    private List<String> result = new ArrayList<>();
    private StringBuilder sb = new StringBuilder();
    private int n;
    private int leftCount = 0, count = 0;

    public List<String> generateParenthesis(int n) {
        this.n = n;
        dfs(0);
        return result;
    }

    private void dfs(int idx) {
        if (idx == n * 2) {
            result.add(sb.toString());
            return;
        }
        if (leftCount < n) {
            sb.append('(');
            count ++;
            leftCount ++;
            dfs(idx + 1);
            leftCount --;
            count --;
            sb.deleteCharAt(sb.length() - 1); 
        }
        if (count > 0) {
            sb.append(')');
            count --;
            dfs(idx + 1);
            count ++;
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}
```