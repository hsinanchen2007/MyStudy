### 解题思路
从左下角往上走到左上角，再往右走到右上角
对于走过的每个位置，依次对其对角线上的所有元素取出并排序，之后将排好序的元素附回该对角线

### 代码

```cpp
class Solution {
public:
    void helper(vector<vector<int>>& mat, int pi, int pj, int n, int m) {
        int ni = pi, nj = pj;
        vector<int> tmp;
        while (ni < n && nj < m) tmp.push_back(mat[ni++][nj++]);
        sort(tmp.begin(), tmp.end());
        ni = pi, nj = pj;
        int i = 0;
        while (ni < n && nj < m) {
            mat[ni++][nj++] = tmp[i];
            i++;
        }
    }

    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int pi = n - 1, pj = 0;
        while (pi > 0) {
            helper(mat, pi--, pj, n, m);
        }
        while (pj < m) {
            helper(mat, pi, pj++, n, m);
        }
        return mat;
    }
};
```