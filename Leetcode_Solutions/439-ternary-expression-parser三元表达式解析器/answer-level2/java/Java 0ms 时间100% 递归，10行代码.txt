![02809913ff769a6d35337cffe63cfbf.png](https://pic.leetcode-cn.com/65c3e5509e336dc1e7a33b9302e9820fbc62920c8a4db3c8f06d4eb93e94f450-02809913ff769a6d35337cffe63cfbf.png)
```
    public String parseTernary(String expression) {
        int n = expression.length();
        int checkLevel = 0;
        for (int j = 1; j < n; j++) {
            if (expression.charAt(j) == '?') checkLevel++;
            if (expression.charAt(j) == ':') checkLevel--;
            if (checkLevel == 0) return (expression.charAt(0) == 'T') ? parseTernary(expression.substring(2, j)) : parseTernary(expression.substring(j+1, n));
        }
        return expression;
    }
```
