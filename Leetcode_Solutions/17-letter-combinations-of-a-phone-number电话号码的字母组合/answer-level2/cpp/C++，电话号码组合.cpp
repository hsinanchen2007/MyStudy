### 解题思路
![image.png](https://pic.leetcode-cn.com/a8e6c10d9bc78cac36b98246c8c2bb7a3a6ba817d9ed5fd5e547a26ed9801014-image.png)

### 代码

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        vector<string> ss = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int nums = 1;
        for (int i = 0; i < digits.size(); i++) {
            nums *= ss[digits[i]-'2'].size();
        }
        vector<string> res(nums);
        int nn = 1;
        for (int i = 0; i < digits.size(); i++) {
            int idx = 0;
            nums /= ss[digits[i]-'2'].size();
            cout << nums << endl;
            for (int kk = 0; kk < nn; kk++) {
                for (int j = 0; j < ss[digits[i]-'2'].size(); j++) {
                    for (int nums_i = 0; nums_i < nums; nums_i++) {
                        res[idx++] += ss[digits[i]-'2'][j];
                    }
                }
            }
            nn *= ss[digits[i]-'2'].size();
        }
        return res;
    }
};
```