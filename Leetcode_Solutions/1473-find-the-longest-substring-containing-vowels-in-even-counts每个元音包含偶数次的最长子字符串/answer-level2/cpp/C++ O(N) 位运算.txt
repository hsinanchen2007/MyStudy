## 代码
```cpp
class Solution {
public:
    int findTheLongestSubstring(string s) {
        auto size = s.size();
        // 使用五个bit位分别表示a i e o u的奇偶性
        for (auto &c : s) {
            switch (c) {
                case 'a':
                    c = 1;
                    break;
                case 'i':
                    c = 2;
                    break;
                case 'e':
                    c = 4;
                    break;
                case 'o':
                    c = 8;
                    break;
                case 'u':
                    c = 16;
                    break;
                default:
                    c = 0;
                    break;
            }
        }
        vector<int> aa(32, -1); // aa记录每个组合从前往后第一次出现的位置
        vector<int> bb(32, -1); // bb记录每个组合从后往前第一次出现的位置
        int ret = 0;
        int flag = 0;
        for (int i = 0; i < size; i++) {
            flag ^= s[i];
            if (!flag) {
                ret = i + 1;
            }
            if (aa[flag] == -1) {
                aa[flag] = i;
            }
        }
        flag = 0;
        for (int i = size - 1; i >= 0; i--) {
            flag ^= s[i];
            if (!flag && size - i > ret) {
                ret = size - i;
            }
            if (bb[flag] == -1)
                bb[flag] = i;
        }
        // 两头
        short sum = flag; // 整个原始字符串的aeiou奇偶性
        for (short tt = 1; tt < 32; tt++) {
            auto tmp = bb[tt ^ sum] - aa[tt] - 1; // 两头出现相同的奇情况 中间符合结果要求
            if (tmp > ret)
                ret = tmp;
        }
        return ret;
    }
};
```