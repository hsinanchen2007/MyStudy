# 解题思路
使用队列保存方向数组，若当前方向未遍历，遍历当前方向；若已遍历，将当前方向置于队尾，通过vector<vector<bool>>保存遍历信息。
```
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
        if(!row) return {};
        int col=matrix[0].size();

        vector<int> ans;
        vector<vector<bool>> flag(row,vector<bool>(col,false));

        queue<pair<int,int>> _queue;
        _queue.push({0,1});
        _queue.push({1,0});
        _queue.push({0,-1});
        _queue.push({-1,0});
        
        int sc=0,sr=0,count=0;
        while(flag[sr][sc]==false && count<4)
        {
            count=0;
            ans.push_back(matrix[sr][sc]);
            flag[sr][sc]=true;
            
            while(count<4)
            {
                count++;
                pair<int,int> mp=_queue.front();
                int r=sr+mp.first,c=sc+mp.second;
                if(r>=0 && r<row && c>=0 && c<col && flag[r][c]==false)
                {
                    sr=r;sc=c;break;
                }
                else
                {
                    _queue.pop();_queue.push(mp);
                }
            }
        }
        return ans;
    }
```
