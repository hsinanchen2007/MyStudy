首先利用hashmap快速找到两个word的所有位置，然后问题转变为“求两个数组中元素之差的最小值”，此时利用双指针求解。
```
class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        unordered_map<string, vector<int>> m;
        for(size_t i = 0; i < words.size(); i++) {
            m[words[i]].push_back(i);
        }

        sort(m[word1].begin(), m[word1].end());
        sort(m[word2].begin(), m[word2].end());
        int res = INT_MAX;
        for(int i = 0, j = 0; i < m[word1].size() && j < m[word2].size();) {
            res = min(res, abs(m[word1][i] - m[word2][j]));
            if(m[word1][i] > m[word2][j]) {
                j++;
            } else {
                i++;
            }
        }
        return res;
    }
};
```
