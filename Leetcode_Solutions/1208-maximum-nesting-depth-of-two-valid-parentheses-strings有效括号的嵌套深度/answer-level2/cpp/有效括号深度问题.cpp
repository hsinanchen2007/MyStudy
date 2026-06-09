### 解题思路
题目写的解释是真的恶心= =简而言之就是找到括号尽量使其不嵌套，而是连接可以保证最小，而有效括号
的识别即是通过栈来识别的，遇到一个左括号加入栈，遇到右括号弹出。让有效括号深度最小实际就是让栈的深度最小，当栈要接受的数据量一定时，让数据量除以2分别插入弹出肯定是最小的，所以就干脆通过括号在栈中所对应的奇偶来获得A、B的子序列，注意代码首先是由于栈的存储只有括号，所以可以用数组来模拟，还有就是--d要后置。

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int d = 0;
        vector<int> ans;
        for (const char& c : seq)
            if (c == '(') {
                ++d;
                ans.push_back(d % 2);
            }
            else {
                ans.push_back(d % 2);
                --d;
            }
        return ans;
    }
};
```