![image.png](https://pic.leetcode-cn.com/5223d2f4a23811370af5de0534efdd30a75969ff02a00d4d9c716780996b61ca-image.png)

关键点：右括号个数 = 当前字符长度 - 左括号个数
```java
public List<String> generateParenthesis(int n) {
    if (n < 1) return Collections.emptyList();
    if (n == 1) return Collections.singletonList("()");

    List<String> res = new ArrayList<>();
    // recursion
    this._generate(1, n, res, "("); // 必是'('
    return res;
}

private void _generate(int leftCnt, int max, List<String> res, String curr) {
    // terminator
    if (curr.length() >= max * 2) { // 总长已满，已到状态树最底层(叶子结点)
        res.add(curr);
        return;
    }

    // process
    // drill down
    if (leftCnt < max) { // 左括号个数受限
        this._generate(leftCnt + 1, max, res, curr + "(");
    }

    // 右括号个数 = 当前字符长度 - 左括号个数 
    // rightCnt = curr.length() - leftCnt
    // rightCnt < leftCnt
    if (curr.length() < leftCnt * 2) { // 右比左少，必在受限max之内
        this._generate(leftCnt, max, res, curr + ")");
    }
    // reverse state
}
```