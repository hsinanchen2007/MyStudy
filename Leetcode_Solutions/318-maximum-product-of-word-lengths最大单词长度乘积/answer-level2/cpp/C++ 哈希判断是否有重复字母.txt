### 解题思路
因为只有26个字母，我们可以用 int 的 1 个 bit 代表一个字母，对字符串进行hash映射，并且记录其长度。

然后暴力遍历找最大值

### 代码

```cpp
class Solution {
public:
    int maxProduct(vector<string>& words) {
        if (words.size() < 2) return 0;
        // 计算每个字母的hash值
        vector<int> hval(26, 0);
        for (int i = 0; i < 26; ++i) {
            hval[i] = (1 << i);
        }

        vector<vector<int>> hlmap(words.size(), vector<int>(2, 0));
        for (int i = 0; i < words.size(); ++i) {
            string w = words[i];
            int key = hashFunc(hval, w);
            int len = w.size();
            hlmap[i][0] = key;
            hlmap[i][1] = len;
        }

        int res = 0;
        for (int i = 0; i < words.size() - 1; ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                // 没有重复字母时，hash值相与为0
                if ((hlmap[i][0] & hlmap[j][0]) == 0) 
                    res = max(res, hlmap[i][1] * hlmap[j][1]);
            }
        }
        return res;
    }

    int hashFunc(vector<int>& hval, string word) {
        int res = 0;
        for (auto& c : word) {
            // 遇到一个未被记录的字母时就将对应位置1
            if ((res & hval[c-'a']) == 0) 
                res += hval[c-'a'];
        }
        return res;
    }
};
```