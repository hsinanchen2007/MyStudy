### 解题思路
1.只有大写字母，最多26个字母，转成数字用数组mp保存字母取值情况
2.只有0-9个数字，且不重复，用数组a保存数字使用情况
3.ml保存words里面最长的长度，计算到最长长度的时候直接判断结果
4.result的长度比ml还大2时必定false
5.使用递归开始从个位第一个数字开始遍历
- 当出现前导0时直接返回false
- 在第p位计算到最后一个数字时，自动算出result第p位的值，如果重复则返回false，否则进一位继续遍历
- 当计算到ml位的时候则直接判断结果

### 代码

```cpp
class Solution {
public:
    int ml = 0;  // words最大长度
    int mp[26];  // 保存26个大写字母取值
    int a[10];   // 保存0-9数字的使用情况
    bool isSolvable(vector<string>& words, string result) {
        int len = 0, i;
        for (i = 0; i < 10; ++i) a[i] = 0;
        for (i = 0; i < 26; ++i) mp[i] = -1;
        ml = 0;
        for (i = 0; i < words.size(); ++i) {
            len = words[i].size();
            if (ml < len) ml = len;
        }
        if (result.size() > ml + 1) return false; // result的长度比words里面最长的长度还大2的时候必定false
        return dfs(words, result, 0, 0, 0);
    }
    // p:代表处理到数字的哪一位，从最低位开始
    // idx:代表处理到哪个数字，0到words.size()之前循环
    // sum:代表处理数字第p位，第idx个数字时的数字和
    bool dfs(vector<string>& words, string& result, int p, int idx, int sum) {
        int n, c, d = words.size();
        if (p >= ml) { // 所有数字都已经处理，直接判断
            if (result.size() > ml) { // 最后一位进位的情况
                c = result[0] - 'A';
                return (mp[c] < 0 && a[sum] != 1) || (mp[c] > 0 && mp[c] == sum);
            } else {
                return sum == 0; //没有进位的情况直接判断sum是否为0
            }
        }
        bool ans = false;
        for (int i = idx; i < words.size(); ++i) {
            n = words[i].size() - 1;
            if (n < p) {
                idx += 1;
                continue;
            }
            c = words[i][n - p] - 'A';
            if (mp[c] >= 0) {
                if (n == p && mp[c] == 0) return false;
                sum += mp[c];
                idx += 1;
                continue;
            }
            int j = n == p ? 1 : 0;
            for (; j <= 9; ++j) {
                if (a[j] == 1) continue;
                a[j] = 1;
                mp[c] = j;
                ans = dfs(words, result, p, idx + 1, sum + mp[c]);
                a[j] = 0;
                mp[c] = -1;
                if (ans) return ans;
            }
            break;
        }
        if (idx == d) {
            n = result.size() - 1;
            c = result[n - p] - 'A';
            if (mp[c] >= 0) {
                if (mp[c] != sum % 10) return false;
                return dfs(words, result, p + 1, 0, sum / 10);
            } else if (a[sum % 10] != 1) {
                a[sum % 10] = 1;
                mp[c] = sum % 10;
                ans = dfs(words, result, p + 1, 0, sum / 10);
                a[sum % 10] = 0;
                mp[c] = -1;
                return ans;
            } else {
                return false;
            }
        }
        return ans;
    }
};
```