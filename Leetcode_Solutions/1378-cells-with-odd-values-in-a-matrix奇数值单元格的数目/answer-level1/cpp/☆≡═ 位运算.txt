用false代表偶数，true代表奇数，偶数增加1变为奇数，奇数增加1变为偶数，可以表示为逻辑取反。
当某一行(列)增加偶数次时奇偶不变，增加奇数次时奇偶相反，
记录各行(列)增加的效果，每个单元格由所在行和列的异或决定奇数次还是偶数次。
```
class Solution {
public:
    int oddCells(const int n, const int m, const vector<vector<int>>& indices) {
        vector<bool> row(n, false);
        vector<bool> col(m, false);
        for (const auto& indice : indices) {
            row[indice[0]] = !row[indice[0]];
            col[indice[1]] = !col[indice[1]];
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                row[i]^col[j] ? ans++ : ans;
        return ans;
    }
};
```
