### 解题思路
1. 先对B数组中所有的出现字符进行综合计数，需注意如"oo", "ooo"这种情况，需要去B中每个单词出现频率与汇总hash表之间的最大值
2. 将数组A中的每个单词，生成类似的字符计数hash表，比对该hash表与B中所有元素的汇总hash表
### 代码

```cpp
class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        if (B.empty() || A.empty()) {
            return A;
        }

        int b[26] = {0};
        int tmp[26] = {0};
        for (auto& w : B) {
            memset(tmp, 0, sizeof(tmp));
            for (auto ch : w) {
                ++tmp[ch - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                b[i] = max(b[i], tmp[i]);
            }
        }

        vector<string> res;
        int a[26] = {0};
        for (auto& w : A) {
            memset(a, 0, sizeof(a));
            for (auto ch : w) {
                ++a[ch - 'a'];
            }

            bool flag = true;
            for (int i = 0; i < 26; ++i) {
                if (a[i] < b[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res.push_back(w);
            }
        }
        return res;
    }
};
```