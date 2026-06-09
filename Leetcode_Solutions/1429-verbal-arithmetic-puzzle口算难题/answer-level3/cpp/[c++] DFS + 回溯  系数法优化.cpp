这道题可以将 **"ABC" + "CDC" = "EFA"** 转化为 
100A + 10B + C + 100C + 10D + C = 100E + 10F + A 
=> **99A + 10B + 102C + 10D - 100E - 10F = 0**
直接将系数与对应字母的数字映射相乘即可, 相当于暴力算法优化
```
class Solution {
public:
    int wordMapping[26] = {0};   // 字母对应的数字映射
    int isFirst[26] = {0};       // 是否是第一个字母(不允许前导0)
    int weight[26] = {0};        // 字母总共的系数
    int isNumUsed[10] = {0};     // 记录数字是否被用过

    bool isSolvable(vector<string> &words, string result) {

        string str = ""; // 出现过的全部字母(无重复)
        int k = 1;       // 系数

        /**
         * 记录系数 + 判断是否是第一个字母
         */
        for (string s : words) {
            for (int i = s.size() - 1; i >= 0; i--) {
                weight[s[i] - 'A'] += k;
                k *= 10;
                if (i == 0) {
                    isFirst[s[i] - 'A'] = 1;
                }
            }
            k = 1;
        }
        for (int i = result.size() - 1; i >= 0; i--) {
            weight[result[i] - 'A'] -= k;
            k *= 10;
            if (i == 0) {
                isFirst[result[i] - 'A'] = 1;
            }
        }

        bool res = false;
        string word = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for (int i = 0; i < 26; i++) {
            if (weight[i] != 0) {
                str.push_back(word[i]);
            }
        }

        for (int num = 0; num < 10; num++) {
            // 若前导为0 或 已经有正确结果, 则不用向下计算
            if ((num == 0 && isFirst[str[0] - 'A'] == 1) || res) {
                continue;
            } else {
                wordMapping[str[0] - 'A'] = num;
                // 和 = 字母的数字映射 * 字母的系数
                int sum = wordMapping[str[0] - 'A'] * weight[str[0] - 'A'];

                //回溯
                isNumUsed[num] = 1;
                res = DFS(str, 1, sum);
                isNumUsed[num] = 0;
            }
        }
        return res;
    }

    bool DFS(string str, int index, int sum) {
        // 字母全分配完数字映射, 判断sum是否等于零
        if (index == str.size()) {
            return sum == 0;
        }
        char c = str[index];
        bool res = false;
        for (int num = 0; num < 10; num++) {
            // 若前导为0 或 数字已经被用过 或 已经有正确结果, 则不用向下计算
            if ((num == 0 && isFirst[c - 'A'] == 1) || isNumUsed[num] == 1 || res) {
                continue;
            } else {
                wordMapping[c - 'A'] = num;
                int add = wordMapping[c - 'A'] * weight[c - 'A'];

                //回溯
                isNumUsed[num] = 1;
                res = DFS(str, index + 1, sum + add);
                isNumUsed[num] = 0;
            }
        }
        return res;
    }
};

```
