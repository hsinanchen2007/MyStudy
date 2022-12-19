```
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
            return {};
        int R = matrix.size(), C = matrix[0].size();
        vector<int> ret;
        int nums = R*C;
        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};
        int r = 0, c = -1;
        int di = 0, len=0, cnt = 0;
        while(cnt < nums){
            if(di % 2 == 0)
                len = C;
            else
                len = R;
            for(int i=0;i<len;i++){
                r = r + dr[di];
                c = c + dc[di];
                ret.push_back(matrix[r][c]);
                cnt ++;
                if(cnt == nums)
                    return ret;
            }
            if(di % 2 == 0)
                R --;   // 输出完一行
            else
                C --;   // 输出完一列
            di = (di + 1) % 4;
        }
        return ret;
    }
};
```
