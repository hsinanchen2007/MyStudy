1. 每次只对比一个字符的字典序，若不满足则增加删除计数；
2. 若当次扫描满足字典序，并且不存在相邻相等的情况，则可以结束算法；若存在相邻相等的情况，下次扫描则只需要检查上次相邻不等的位置。

![image.png](https://pic.leetcode-cn.com/da64cf43ab71dc3b9f2b0663ecd84d9ee407fca2dcb80ba6f9e8cb47bc56c3a6-image.png)


```
    int minDeletionSize(vector<string>& A) {
        if (A.size() == 0)
            return 0;

        int strLen = A[0].size();
        int N = A.size();
        vector<bool> gap(strLen, false);
        int delCnt = 0;
        for (int i = 0; i < strLen; ++i) {
            bool unOrder = false;
            for (int j = 1; j < N; ++j) {
                if (!gap[j] && (A[j - 1][i] > A[j][i])) {
                    ++delCnt;
                    unOrder = true;
                    break;
                }
            }
            if (unOrder)  // 此列要删除，不要计算gap
                continue;
            int gapCnt(0);
            for (int j = 1; j < N; ++j) {
                if (A[j - 1][i] < A[j][i]) {
                    gap[j] = true;  // 当前这两个字符已满足字典序（且不相等），则做记录，当前位置下面的字符无需再比较
                    ++gapCnt;
                }
            }
            if (gapCnt == N - 1)  // 已经全部满足字典序，不用再继续
                break;
        }

        return delCnt;
    }
```
