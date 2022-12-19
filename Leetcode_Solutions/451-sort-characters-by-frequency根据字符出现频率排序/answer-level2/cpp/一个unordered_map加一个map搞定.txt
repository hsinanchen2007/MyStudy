### 解题思路
尽可能避免嵌套遍历导致但On^2时间复杂度（写到一半赶紧推翻了套娃遍历）。
我这个解法最坏遍历3n次，也比一开始想到的n^2好多了......

### 代码

```cpp
class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char, int> CharsCnt;
        map<int, vector<char>, greater<int> > CntsChars;
        for (int i = 0; i < s.size(); ++i) ++CharsCnt[s[i]];
        for (auto it = CharsCnt.begin(); it != CharsCnt.end(); ++it) CntsChars[it->second].emplace_back(it->first);
        for (auto it = CntsChars.begin(); it != CntsChars.end(); ++it) { // 虽然是三层循环 但只会执行On次
            auto& v = it->second; // 起个别名
            for (int i = 0; i < v.size(); ++i) {
                for (int j = 0; j < it->first; ++j) ans += v[i];
            }
        }
        return ans;
    }
};
```