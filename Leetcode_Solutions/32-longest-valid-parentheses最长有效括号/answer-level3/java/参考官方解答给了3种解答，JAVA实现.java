### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {

    public int longestValidParentheses(String s) {
        int i = new Random().nextInt(3);
        if (i == 0) {
            return doubleNumSolution(s);
        } else if (i == 1) {
            return stackSolution(s);
        } else {
            return dpSolution(s);
        }
    }

    //利用left right记录左右括号出现的次数 时间复杂度O(n) 空间复杂度O(1)
    private int doubleNumSolution(String s) {
        int res = 0;
        if (s.length() < 2) {
            return res;
        }
        int left = 0;
        int right = 0;
        //从左到右遍历
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '(') {
                left++;
            } else {
                right++;
            }
            if (right == left) {
                res = Math.max(2 * right, res);
            }
            //右括号比左括号多，比如()()）....，则重新寻找最长有效括号
            if (right > left) {
                left = right = 0;
            }
        }
        left = right = 0;
        //从右到左遍历
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s.charAt(i) == '(') {
                left++;
            } else {
                right++;
            }
            if (right == left) {
                res = Math.max(2 * right, res);
            }
            //左括号比右括号多，比如....(()()，则重新寻找最长有效括号
            if (left > right) {
                left = right = 0;
            }
        }
        return res;
    }

    //利用栈  时间空间都是O(n)
    private int stackSolution(String s) {
        int res = 0;
        if (s.length() < 2) {
            return res;
        }
        Stack<Integer> stack = new Stack<>(); 
        stack.push(-1); //初始化栈，也可以不初始化，但是需要加if判断栈是否为空
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } else {
                //注意这里条件不是!stack.isEmpty()，因为初始化多push了一个-1，否则会数组越界
                if (stack.size() != 1 && s.charAt(stack.peek()) == '(') {
                    stack.pop();
                    res = Math.max(res, i - stack.peek());
                } else {
                    stack.push(i);
                }
            }
        }
        return res;
    }

    //利用dp  时间空间都是O(n)
    private int dpSolution(String s) {
        int res = 0;
        if (s.length() < 2) {
            return res;
        }
        int[] dp = new int[s.length()]; //dp[j] 表示以s.charAt(j - 1)为结尾的最长括号长度
        for (int j = 1; j < s.length(); ++j) {
            //如果s.charAt(j) == '('，则dp[j] = 0;
            if (s.charAt(j) == ')') {
                //....()....形式
                if (s.charAt(j - 1) == '(') {
                    dp[j] = (j >= 2 ? dp[j - 2] : 0) + 2; //这地方必须得括号，不然先执行+号再执行3元运算符
                } else {
                    //....))....形式
                    if (j - dp[j - 1] - 1 >= 0 && s.charAt(j - dp[j - 1] - 1) == '(') {
                        dp[j] = dp[j - 1] + 2 + (j - dp[j - 1] - 2 >= 0 ? dp[j - dp[j - 1] - 2] : 0);
                    }
                }
                res = Math.max(res, dp[j]);
            }
        }
        return res;
    }
}
```