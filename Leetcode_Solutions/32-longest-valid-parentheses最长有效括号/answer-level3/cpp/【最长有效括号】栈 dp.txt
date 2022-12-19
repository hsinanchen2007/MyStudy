### 思路一
1. 使用栈，与常规的括号匹配思路大体一样
    11. 当输入是 `(` ，直接入栈
    12. 当输入是 `)` ，检查栈是否为空，检查栈顶是否与其匹配
    13. 匹配则弹出栈顶
    14. 不匹配返回 false
2. 这道题的题目给出的字符串包含不匹配的情况，需要求其中匹配的最长的子串的长度
3. 所以对应这些变化，要调整的内容
    31. 当匹配成功的一对括号被弹出栈时，应该在栈内相应的位置记录长度为 2
    32. 如果是 `()()` 或是 `(())` 的情况，连续的长度应该加起来，由于栈的特性，很容易实现
    33. 如果遇到了不匹配的情况，那么留下这个字符，用来区分前后的长度
4. 可能被分成好几个匹配子串，使用 max 来记录最长

### 答题一
```C++
int longestValidParentheses(string s) 
{
    pair<char, char> k = { '(',')' };
    map<char, int> dic;
    dic[k.first] = -1;
    dic[k.second] = -2;

    int ans = 0;
    stack<int> st;
    for (auto& c : s)
    {
        if (c == k.first)
        {
            st.push(dic[c]);
            continue;
        }

        int temp = 0;
        while (!st.empty() && st.top() != dic[k.first] && st.top() != dic[k.second])
        {
            temp += st.top();
            st.pop();
        }
        if (st.empty() || st.top() != dic[k.first])
        {
            st.push(temp);
            st.push(dic[c]);
            continue;
        }

        st.pop();
        temp += 2;
        while (!st.empty() && st.top() != dic[k.first] && st.top() != dic[k.second])
        {
            temp += st.top();
            st.pop();
        }
        ans = max(ans, temp);
        st.push(temp);
    }
    return ans;
}
```

### 思路二
1. 动态规划，定义 `dp[i]` 为到第 i 个格子为止，匹配的子串长度
2. 当 `s[i]` == `(` 肯定为 0
3. 当 `s[i]` == `)` 
    31. 如果 `s[i - 1]` == `(` ，刚好组成一对，本身长度为 2 ，考虑是否与上一个子串相连
        * 所以为 `dp[i]` = `dp[i - 2]` + `2`
        * 即 上一个子串长度 + 本身长度
    32. 如果 `s[i - 1]` == `)` ，无法与其成为匹配的子串
        * 需要进一步考虑这个子串之前是否有 `(` ，如果能够匹配成新的子串，那么
        * 当 `s[i - 1]` == `)` && `s[i - dp[i - 1] - 1]` == `(` 时，匹配成新的子串
        * 长度为 `dp[i - dp[i - 1] - 2]` + `2` + `dp[i - 1]`
        * 即 上上个子串长度 + 本身长度 + 上一个子串长度
4. 因为有 `i - 2` 所以插入两个 `)` 再 dp 比较方便

### 答题二
```C++
int longestValidParentheses(string s)
{
    pair<char, char> k = { '(',')' };
    s.insert(s.begin(), k.second);
    s.insert(s.begin(), k.second);
    vector<int> dp(s.size(), 0);
    int ans = 0;
    for (int i = 2; i < s.size(); i++)
    {
        if (s[i] == k.first)
        {
            dp[i] = 0;
        }
        else
        {
            if (s[i - 1] == k.first)
            {
                dp[i] = dp[i - 2] + 2;
            }
            else if (s[i - dp[i - 1] - 1] == k.first)
            {
                dp[i] = dp[i - dp[i - 1] - 2] + 2 + dp[i - 1];
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

