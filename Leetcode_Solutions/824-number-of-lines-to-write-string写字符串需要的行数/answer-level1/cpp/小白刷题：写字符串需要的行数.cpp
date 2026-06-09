遍历字符串即可

代码：
```
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int> ans(2);
        ans[0] = 1;
        ans[1] = 0;
        int len = S.length();
        for (int i = 0; i < len; i++) {
            ans[1] = ans[1] + widths[(int)S[i] - 97];
            if (ans[1] > 100) {
                ans[0]++;
                ans[1] = widths[(int)S[i] - 97];
            }
        }
        return ans;
    }
};
```
