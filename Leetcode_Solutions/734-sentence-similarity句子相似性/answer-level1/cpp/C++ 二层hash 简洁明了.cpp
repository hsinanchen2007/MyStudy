### 解题思路
对长度相同的句子逐次判断每个词是否相似。为了加快计算速度，我们用hashmap把pairs里的相似关系记录下来，两个方向都记一遍。但由于每个词相似的词可能不止一个，所以我们用一个二重的hash记录相似性是否存在。

具体参考代码即可。

真诚欢迎大家关注我的github和leetcode仓库～
[我的github](https://www.github.com/wfnuser)
[我的题解](https://www.github.com/wfnuser/leetcode)
最近沉迷刷题 同时也在学习和实现lua，欢迎交流



### 代码

```cpp
class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        unordered_map<string, unordered_map<string, int>> m;

        for (auto p: pairs) {
            m[p[0]][p[1]] = 1;
            m[p[1]][p[0]] = 1;
        }

        if (words1.size() != words2.size()) return false;

        for (int i = 0; i < words1.size(); i++) {
            if (words1[i] != words2[i] && m[words1[i]][words2[i]] != 1) return false;
        }

        return true;
    }
};
```