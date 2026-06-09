### 解题思路
1. 优先使用左括号 (
2. 使用右括号 ) 的条件是：
    1. **当前必须要有左括号的出现**
    2. **当前左括号的个数大于右括号个数**

### 代码

```java
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        if (n == 0) {
            return res;
        }
        dfs(0,0, "", n, res);
        return res;
    }

    private void dfs(int currentLeft, int currentRight, String currentValue, int n, List<String> res) {
        if (currentValue.length() == n * 2) {
            res.add(currentValue);
            return;
        }
        if (currentLeft < n) {
            dfs(currentLeft + 1, currentRight, currentValue + "(", n, res);
        }
        if (currentLeft > 0 && currentRight < currentLeft) {
            dfs(currentLeft, currentRight + 1, currentValue + ")", n, res);
        }
    }
}
```