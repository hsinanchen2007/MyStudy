## 思路一：存储后缀
将所有单词放在set中，对于对于set中每个单词，遍历其后缀，看是否在set中，如果在就删除，比如time，那么就遍历ime, me, e，删除me。这样就保证了set中留下来的单词不可能再合并了，最后遍历set加上每个单词长度和#号。

### 代码
时间复杂度：O($\sum w_{i}^2$)，其中 $w_{i}$ 是words[i] 的长度，每个单词有 $w_{i}$ 个后缀，查询其是否在集合中需要进行O($w_{i}$)的哈希值计算。
空间复杂度：O($\sum w_{i}$)，存储单词的空间开销。
```cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int res = 0;
        unordered_set<string> ust(words.begin(), words.end());
        for (string word : ust) {
            for (int i = 1; i < word.size(); ++i) {
                ust.erase(word.substr(i));
            }            
        }
        for (string word : ust) {
            res += word.size() + 1;
        }
        return res;
    }
};
```