### 解题思路
每次拿一个数字，获得新一次的字符串vector，和存量字符串vector做full join，结果作为存量字符串。

### 代码

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        for (int i = 0; i < digits.size(); ++i) {
            vector<string> current = base(digits[i]);

            if (i == 0) {
                res.swap(current);
                continue;
            }

            vector<string> holder;

            for (int j = 0; j < res.size(); ++j) {
                const string& old = res[j];
                for (int k = 0; k < current.size(); ++k) {
                    const string& now = current[k];
                    holder.push_back(old + now);
                }
            }
            res.swap(holder);
        }
        return res;
    }
    vector<string> base(char c) {
        int rank = c - '2';
        vector<string> one;
        if (rank >= 0 && rank <= 4) {
            one.push_back(string(1, 'a' + 3 * rank));
            one.push_back(string(1, 'b' + 3 * rank));
            one.push_back(string(1, 'c' + 3 * rank));
        } else if (c == '7') {
            one.push_back("p");
            one.push_back("q");
            one.push_back("r");
            one.push_back("s");
        } else if (c == '8') {
            one.push_back("t");
            one.push_back("u");
            one.push_back("v");
        } else {
            one.push_back("w");
            one.push_back("x");
            one.push_back("y");
            one.push_back("z");
        }

        return one;
    }
};
```