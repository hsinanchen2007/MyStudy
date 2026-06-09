### 解题思路
写的太差， 废了很长时间， 不知谁有更好解法么
对s中每个字符计数， 来回遍历count数组
### 代码

```cpp
class Solution {
public:
    string sortString(string s) {
        int count[26] = {0};
        int sumcount = s.size();
        for (int i = 0; i < s.size(); ++i) {
            count[s[i]-'a'] ++;
        }
        bool flag = true;
        string result = "";
        int pre = 0;
        while (sumcount > 0) {
            if (flag) {
                int i = 0;
                for (i = 0; i < 26; ++i) {
                    if (!count[i]) continue;
                    if (i + 'a' > pre) break;
                }
                if (i < 26) {
                    result.push_back(i+'a');
                    sumcount --;
                    count[i]--;
                    pre = result.back();
                } else {
                    flag = false;
                    pre = 128;
                }
            } else {
                int i = 0;
                for (i = 25; i >= 0; --i) {
                    if (!count[i]) continue;
                    if (i + 'a' < pre) break;
                }
                if (i >= 0) {
                    result.push_back(i+'a');
                    sumcount --;
                    count[i]--;
                    pre = result.back();
                } else {
                    pre = 0;
                    flag = true;
                }
            }
        }
        return result;
    }
};
```