### 解题思路
遍历
counter统计了左括号的个数
遇到左括号，counter自增
遇到右括号，判断counter是否为０，如果是，则没有左括号与之匹配，忽略，如果不是，则入到res, counter--;
小写字符正常加入到res
最后的counter统计了多余的左括号
不能从前往后删除，　考虑一种情况　"()(()(", 这种情况下多了两个左括号，如果从前往后删除，导致最后结果为")("
不符合要求

### 代码

```cpp
class Solution {
public:
    void reverse(string& s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            char tmp = move(s[i]);
            s[i] = move(s[j]);
            s[j] = move(tmp);
            i++;
            j--;
        }
    }
    string minRemoveToMakeValid(string s) {
        vector<char> res;
        int counter = 0;
        
        int size = s.size();
        for (int i = 0; i < size; i++) {
            if (s[i] == '(') {
                res.push_back(s[i]);
                counter++;
            } else if (s[i] >= 'a' && s[i] <= 'z') {
                res.push_back(s[i]);
            } else if (s[i] == ')' && counter > 0) {
                res.push_back(s[i]);
                counter--;
            } else if (s[i] == ')' && counter <= 0) {
                continue;
            }
        }
        // counter 记录了多余的'('
        // 从后往前删除counter个‘(’
        string ans = "";
        for (int i = res.size() - 1; i >= 0; i--) {
            if (counter > 0 && res[i] == '(') {
                counter--;
            } else {
                ans += res[i];
            }
        }
        reverse(ans);
        return ans;
    }
};
```