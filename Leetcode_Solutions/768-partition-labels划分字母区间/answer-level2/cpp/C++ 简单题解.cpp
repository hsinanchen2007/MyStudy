随着遍历，每次都更新最右端的位置
具体见代码：
```
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int N = S.size();
        vector<int> ends(26, -1);
        for (int i = 0; i < N; ++i) {
            ends[S[i] - 'a'] = i;
        }
        vector<int> res;
        int i = 0;
        while (i < N) {
            int r = ends[S[i] - 'a'];
            for (int j = i + 1; j <= r; ++j) {
                r = max(r, ends[S[j] - 'a']);
            }
            res.push_back(r - i + 1);
            i = r + 1;
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/ab1815a9da507baedf310a8f8362fdbfc9a1414949199ba28ab4cc2ccc8f1f74-image.png)


