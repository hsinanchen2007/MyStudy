### 解题思路
1. 结果最长为： 两个string长度最大值加1
2. 当前位： “a， b， 进位”的异或 （不同为1）
3. 进位: “a， b， 进位” 同时存在两个1
4. 最后管理下首位即可

### 代码

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        int idx_a = a.size();
        int idx_b = b.size();
        int idx_ans = max(idx_a, idx_b) + 1;
        string ans(idx_ans, '0');
        while (--idx_ans >=0) {
            int val_a = --idx_a >= 0 ? a[idx_a] - '0' : 0;
            int val_b = --idx_b >= 0 ? b[idx_b] - '0' : 0;
            int val_ans = ans[idx_ans] - '0';
            ans[idx_ans] = (val_a^val_b^val_ans) + '0';  // 个位通过异或得到
            if (idx_ans) ans[idx_ans - 1] = (val_a&val_b || val_a&val_ans || val_b&val_ans) + '0'; // 有两个1就进位
        }
        if (ans[0] == '0') ans.erase(0, 1); 
        return ans;
    }
};
```