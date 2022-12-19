```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
//        return this->longestValidParenthesesDP(s);
//        return this->longestValidParenthesesStack(s);
        return this->longestValidParentheses2Times(s);
    }

    int longestValidParentheses2Times(string s) {
        //
        int left = 0, right = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i += 1) {
            if (s[i] == '(') {
                left += 1;
            } else {
                right += 1;
            }
            if (left == right) {
                ans = max(ans, 2 * right);
            } else if (right > left) {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int j = s.size() - 1; j >= 0; j -= 1) {
            if (s[j] == '(') {
                left += 1;
            } else {
                right += 1;
            }
            if (left == right) {
                ans = max(ans, 2 * left);
            } else if (left > right) {
                left = right = 0;
            }
        }
        return ans;
    }

    int longestValidParenthesesStack(string s) {
        int ans = 0;
        vector<int> stack;
        stack.push_back(-1);
        for (int i = 0; i < s.size(); i += 1) {
            if (s[i] == '(') {
                stack.push_back(i);
            } else {
                stack.pop_back();
                if (stack.empty()) {
                    // 只是为了 后面的 i - stack.back() 能保持是最终的长度
                    stack.push_back(i);
                } else {
                    ans = max(ans, i - stack.back());
                }
            }
        }
        return ans;
    }

    int longestValidParenthesesDP(string s) {
        if (s.empty() || s.size() == 1) {
            return 0;
        }
        int ans = 0;
        vector<int> dp(s.size(), 0);
        if (s[0] == '(' && s[1] == ')') {
            dp[1] = 2;
            ans = 2;
        } else {
            dp[1] = 0;
            ans = 0;
        }
        for (int i = 2; i < s.size(); i++) {
            if (s[i] == ')' && i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(' && i - dp[i - 1] - 2 >= 0) {
                int part1 = 0;
//                if (i - dp[i - 1] - 2 >= 0) {
                part1 = dp[i - dp[i - 1] - 2];
//                }
                int part2 = dp[i - 1];
                dp[i] = part1 + part2 + 2;
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};
```

# DP算法
在了解了如何去做之后, 主要是那几个判断比较费劲, 尤其是`i - dp[i - 1] - 1 >= 0` 的判断很容易忽略, 并且, 在本地调试的时候和题答案的时候同样的例子, 本地通过, 线上通不过.

最简单的`())`, 这个判断没有的话, 到i=2的时候, 上述的值就是-1了, 不同的编译器可能对于-1的index反应不一样. 总之需要做判断. 

有时间, 再加上其他的做法吧.

# stack做法

最困难的是理解第一次的`stack.push_back(-1);` 和 判断empty, 这是因为为了后面的 `i - stack.back()`, 保持是上一次的`(`的上一个位置

# 两次遍历

最困难的是: 

1. 这个想法是怎么想出来的?
2. 为啥遍历两次? 
