### 解题思路
// 思路：暴力做法，先将原始字符串加入数组中，对s中的每个字符判断其是否为字母，
// 如果是字母，则对数组中的每个元素 转变大小写后 添加到数组中

### 代码

```cpp
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        // 思路：暴力做法，对s中的每个字符判断其是否为字母，
        vector<string> res = {S};

        for (int i=0; i<S.size(); i++) {
            if (isalpha(S[i])) {
                int N = res.size();
                for (int j=0; j<N; j++) {
                    string s = res[j];
                    s[i] = toggle(s[i]);
                    res.push_back(s);
                }
            }
        }
        return res;
    }

    char toggle(const char ch) {
        if (ch >= 'a' && ch <= 'z')
		    return ch - 'a' + 'A';
        return ch - 'A' + 'a';
    }
};
```