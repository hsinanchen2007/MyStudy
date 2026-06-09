### 分析
这是一个典型的栈的应用类问题
我们用一个栈来存储坐标。为了方便计算，在最开始的时候，我们将栈里面放入一个-1.
当遇到的是'('的时候，我们将其坐标入栈，
当遇到的是'）'的时候，弹出栈顶元素。此时需要分两种情况。
此时如果栈空了，其实相当于前面已经正好匹配了，然后再进来了一个'）',此时无需更新最大值max，
只需将当期坐标入栈。其作用和上面栈初始化的时候放入一个-1相同。
如果此时栈非空，说明又多了一对匹配。需要更新max的值。
以)()())为例。如下所示。
![11](https://pic.leetcode-cn.com/d7dbad30315d1ca2d5e74209b4907487c86fecf0de73ecd47ae6c4ef1a32e1e0.png "11")
因此max输出4
### 代码
```
public int longestValidParentheses(String s) {
        assert s != null;
        if (s.length() < 2) {
            return 0;
        }
        Stack<Integer> stack = new Stack<>();
        int max = 0;

        stack.add(-1);

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.isEmpty()) {
                    stack.push(i);
                } else {
                    max = max > (i - stack.peek()) ? max : (i - stack.peek());
                }

            }

        }
        return max;

    }
```
### 动态规划写法
```
用 dp[i] 表示以 i 结尾的最长有效括号；

    当 s.charAt(i) 为 '('时,不可能组成有效的括号，因此dp[i]= 0；

    当 s.charAt(i) 为 '）'时分两种情况

    当 s.charAt(i) 为 '('，那么 dp[i] = dp[i-2] + 2；

    当 s.charAt(i) 为 '）' 并且 s.charAt(i-dp[i-1] - 1) 为 (，那么 dp[i] = dp[i-1] + 2 + dp[i-dp[i-1]-2]；
```
### 代码
```
public int longestValidParentheses1(String s) {

        assert s != null;
        int res = 0;
        if (s.length() < 2) {
            return 0;
        }
        int[] dp = new int[s.length()];

        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == ')') {
                if (s.charAt(i - 1) == '(') {
                    dp[i] = i > 1 ? (dp[i - 2] + 2) : 2;
                } else {
                    if (i - dp[i - 1] - 1 >= 0 && s.charAt(i - dp[i - 1] - 1) == '(') {
                        dp[i] = dp[i - 1] + 2 + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0);
                    }
                }
                res = res > dp[i] ? res : dp[i];

            }

        }
        return res;
    }
```

本人建了个公众号用于刷题交流，欢迎关注：
![qrcode_for_gh_8eedbc428c9a_258(1).jpg](https://pic.leetcode-cn.com/e5f794b173fbe256a541447fc7ff8e6eb031774890bdfdb48ca3c7866dc81dc2-qrcode_for_gh_8eedbc428c9a_258\(1\).jpg)

