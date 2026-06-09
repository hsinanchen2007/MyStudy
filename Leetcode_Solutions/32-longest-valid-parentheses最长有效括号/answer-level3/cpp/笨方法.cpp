### 解题思路

第一步：将所有括号的匹配关系找出来保存起来
第二步：将上面匹配好的括号下标值升序排序，再计算出最长的连续的序列即可

### 代码

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        // 第一步：将所有括号的匹配关系找出来保存起来     
        stack<pair<int, char>> leftParentheses;
        vector<int> pairParentheses;
        int i = 0;
        while (s[i] != '\0') {
            while (s[i] == '(') {
                // 先把左括号存起来
                leftParentheses.push(make_pair(i, s[i]));
                i ++;
            }
            while (s[i] == ')') {
                if (!leftParentheses.empty()) {
                    // 和最后进栈的左括号匹配上
                    pairParentheses.push_back(leftParentheses.top().first);
                    pairParentheses.push_back(i);
                    leftParentheses.pop();
                    // 继续看是否还可以匹配到左括号，直到左括号匹配完
                    i ++;
                } else {
                    // 没有可匹配的左括号时, 右括号是多余的，继续即可
                    i ++;
                }
            }
        }
        // 第二步：将上面匹配好的括号下标值升序排序，再计算出最长的连续的序列即可
        int len = 0;
        int maxLen = 0;
        // printf("pairParentheses.size()=%d\n", pairParentheses.size());
        if (pairParentheses.size() > 0) {
            len = 1;
            sort(pairParentheses.begin(), pairParentheses.end());
        }
        for (int j = 1; j < pairParentheses.size(); j++) {
            // printf("first=%d, second=%d\n", pairParentheses[j-1], pairParentheses[j]);            
            if (pairParentheses[j-1] + 1 == pairParentheses[j]) {
                len++;
            } else {
                // printf("len=%d, maxLen=%d\n", len, maxLen);
                if (maxLen < len) {
                    maxLen = len;
                }
                len = 1;
            }
        }
        // printf("len=%d, maxLen=%d\n", len, maxLen);
        if (maxLen < len) {
            maxLen = len;
        }
        
        return maxLen;
    }
};
```