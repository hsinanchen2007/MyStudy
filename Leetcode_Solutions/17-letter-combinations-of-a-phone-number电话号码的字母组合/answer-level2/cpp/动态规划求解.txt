### 解题思路
每从digits中读取一个字符，就将ans复制3或4次，然后将读取字符对应的按键字母追加到ans的每个元素中
如输入"23",已经读过2，此时ans = {"a", "b", "c"},接着读取3，ans复制自身，此时ans = {"a", "b", "c"， "a", "b", "c"，"a", "b", "c"}。现在读取3，对应字符为"def",将d、e、f分别追加到ans[0..2]，ans[3..5],ans[6..8]，即可得到结果。

### 代码

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0) return ans;
        vector<vector<string>> v = {{"a", "b", "c"}, {"d" ,"e", "f"}, {"g", "h", "i"}, {"j", "k", "l"},
                            {"m", "n", "o"}, {"p", "q", "r", "s"}, {"t", "u", "v"}, {"w", "x", "y", "z"}};
        vector<int> len = {3, 3, 3, 3, 3, 4, 3, 4};
        ans = v[digits[0] - '2'];
        int size = digits.size();
        for(int i = 1; i < size; ++i){
            int pre_len = ans.size();
            vector<string> t = ans;
            int num = digits[i] - '2';
            for(int j = 0; j < len[num] - 1; ++j)
                ans.insert(ans.end(), t.begin(), t.end());
            int ans_len = ans.size();
            for(int j = 0; j < ans_len; ++j){
                ans[j] += v[num][j/pre_len];
            }
        } 
        return ans;
    }
};
```