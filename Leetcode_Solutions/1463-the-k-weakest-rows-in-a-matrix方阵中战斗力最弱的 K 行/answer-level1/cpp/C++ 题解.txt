### [1337. 方阵中战斗力最弱的 K 行](https://leetcode-cn.com/problems/the-k-weakest-rows-in-a-matrix/submissions/)

#### 题解

  + 统计战斗力
  + 根据战斗力和行标排序
  + 时间复杂度$O(m*n)$
  + 更多题解: [>>请点击<<](https://tawn0000.github.io/2020/02/08/leetcode-week-contest/)

#### 代码

```cpp
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res, ans;
        int* capacity = new int[mat.size()];
        for(int i = 0; i < mat.size(); i++)
        {
            res.push_back(i);
            capacity[i] = 0;
            for(int j = 0; j < mat[i].size() && mat[i][j]; j++)
                capacity[i] ++;
        }
        sort(res.begin(), res.end(), [&](int x, int y){
            if(capacity[x] == capacity[y])
                return x < y;
            return capacity[x] < capacity[y];
            });
        for(int i = 0; i < k; i++)
            ans.push_back(res[i]);
        return ans;
    }
};
```