核心思路：如果括号有效，任意位置的左括号是要大于等于右括号的，即如果左括号等于右括号数量，那么接下来的操作一定是 加入左括号；如果左括号大于右括号，有两种选择，出左括号或右括号。如果做括号数量已经为最大值，只需要将剩下的右括号补齐即可。

另：js 某些情况下有毒，还是 java 吧😭

```java
class Solution {
  private List<String> result = new ArrayList<>();
  public List<String> generateParenthesis(int n) {
    handler(n, n, "");
    return result;
  }
  private void handler(int l, int r, String s) {
    if (l == 0) {
      while (r-- > 0)
        s += ")";
      result.add(s);
      return;
    }
  
    if (l == r) {
      handler(l - 1, r, s + "(");
    } else if (l < r) {
      handler(l - 1, r, s + "(");
      handler(l, r - 1, s + ")");
    }
  }
}
```