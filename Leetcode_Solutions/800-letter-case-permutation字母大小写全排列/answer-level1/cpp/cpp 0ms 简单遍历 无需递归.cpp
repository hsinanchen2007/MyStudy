![image.png](https://pic.leetcode-cn.com/3814f665667c2792e369c2ec03f445c1537579f11fc19902cdbb7b54977ee73b-image.png)

思路：
1.遍历S
2.如果碰到字母，对于当前保存的所有可能字符串，全部切换当前位大小写，插入字符串集合

```
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> result{S};
        for (int i = 0; i < S.size(); i++) {
            if (isupper(S[i])) {
                int size = result.size();
                for (int j = 0; j < size; j++) {
                    string temp = result[j];
                    temp[i] = tolower(temp[i]);
                    result.emplace_back(move(temp));
                }
            } else if (islower(S[i])) {
                int size = result.size();
                for (int j = 0; j < size; j++) {
                    string temp = result[j];
                    temp[i] = toupper(temp[i]);
                    result.emplace_back(move(temp));
                }
            }
        }
        return result;
    }
};
```

