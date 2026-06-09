### 解题思路
括号类问题一般都是用栈解，主要是要看怎么用栈
详见代码注释思路

16ms 10.8M
--- wangtao HW-2020/2/28

### 代码

```cpp
class Solution {
public:
    /*
    思路：
    1、括号匹配类的问题一般情况下都用栈来解，主要是要看怎么用这个栈
    2、本题求最长有效括号，其实每一对有效括号总是能准确出栈的，那么，要求最长有效字串，可以利用括号所在下标，也就是栈内数据可以用一个pair来存储
    3、在出栈时记录当前")"索引和出栈"("的索引，排序，问题转换为求最长连续数字的个数
    */
    int longestValidParentheses(string s) {
        stack<pair<char, int>> st;
        vector<int> nums;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push({'(', i});
            }
            if (s[i] == ')' && !st.empty()) {
                pair<char, int> top = st.top();
                nums.push_back(top.second);
                nums.push_back(i);
                st.pop();
            }
        }
        sort(nums.begin(), nums.end());
        if (nums.size() == 0) return 0;
        int ans = 0;
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == (nums[i - 1] + 1)) {
                count++;
            } else {
                ans = max(ans, count);
                count = 1;
            }
        }
        ans = max(ans, count);
        return ans;
    }
};
```