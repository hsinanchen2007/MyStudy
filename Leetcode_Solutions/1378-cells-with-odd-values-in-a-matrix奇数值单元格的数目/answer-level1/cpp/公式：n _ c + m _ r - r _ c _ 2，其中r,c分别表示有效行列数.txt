```
/**
*   题目变形：同一行或列出现的次数对2取余，作为这一行或列出现的真实次数
*/
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        map<int,int> rows,cols;
        // 行或列偶数抵消，只保留奇数
        for(int i=0;i<indices.size();i++)
        {
            rows[indices[i][0]] ^= 1;
            cols[indices[i][1]] ^= 1;
            if(rows[indices[i][0]] == 0) rows.erase(indices[i][0]);
            if(cols[indices[i][1]] == 0) cols.erase(indices[i][1]);
        }
        int r = rows.size(), c = cols.size();
        // 公式：整行：n * c，整列：m * r，重复：r * c * 2
        return n * c + m * r - r * c * 2;
    }
};
```