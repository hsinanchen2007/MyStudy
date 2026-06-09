超时了，不知道该怎么优化 - -
思路是从最底下行开始计算每个位置期待的值。。。
```
class Solution {
public:
    
    void help(vector<int>& row, vector<map<int, int>> &expect, vector<map<int, int>> &cur) {
        int n = row.size();
        for (int j = 0; j < n; ++j) {
            for (auto ii : expect[j]) {
                cur[0][ii.first - row[0]] += ii.second;
            }
        }
        
        for (int i = 1; i < n; ++i) {
            for (auto ii : cur[0]) {
                cur[i][ii.first - (row[i] - row[0])] = ii.second;
            }
        }
    }
    
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int result = 0;
        
        int n = A.size();
        // i, <expect, times>
        vector<map<int, int>> allA(n, map<int, int>());
        vector<map<int, int>> allB(n, map<int, int>());
        vector<map<int, int>> allC(n, map<int, int>());
        vector<map<int, int>> allD(n, map<int, int>());
        
        for (int i = 0; i < n; ++i) {
            allD[i][0 - D[i]] = 1;
        }

        help(C, allD, allC);
        help(B, allC, allB);
        help(A, allB, allA);

        for (int i = 0; i < n; ++i) {
            result += allA[i][0];
        }
        
        return result;
    }
};
```
