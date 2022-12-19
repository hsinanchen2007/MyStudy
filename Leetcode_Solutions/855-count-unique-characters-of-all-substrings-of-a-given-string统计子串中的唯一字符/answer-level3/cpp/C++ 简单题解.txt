记录每一个字符最后出现的两次对应的位置即可
```cpp
class Solution {
public:
    int uniqueLetterString(string S) {
        vector<vector<int> > ends(128, {-1, -1});
        int res = 0;
        int prev = 0;
        for (int i = 0; i < S.size(); ++i) {
            prev += i - ends[S[i]][1] - (ends[S[i]][1] - ends[S[i]][0]);
            ends[S[i]][0] = ends[S[i]][1];
            ends[S[i]][1] = i;
            res += prev;
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/e8f3a71b707190c4c631b95b102ceeb7b93ccc1f2254ccd41d630e8c1bb06a1d-image.png)
