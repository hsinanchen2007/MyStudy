```
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<bool>> used(8,vector<bool>(8,false));
        int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        bool dirused[8]={false};
        vector<vector<int>> res;
        for(int i=0;i<queens.size();i++)
        {
            used[queens[i][0]][queens[i][1]]=true;
        }
        for(int k=0;k<8;k++)
        {
            int x=king[0],y=king[1];
            while(x+dir[k][0]>=0&&x+dir[k][0]<8&&y+dir[k][1]>=0&&y+dir[k][1]<8)
            {
                x+=dir[k][0];
                y+=dir[k][1];
                if(used[x][y])
                {
                    vector<int> temp;
                    temp.push_back(x);
                    temp.push_back(y);
                    res.push_back(temp);
                    break;
                }
            }
        }
        return res;
    }
};
```
