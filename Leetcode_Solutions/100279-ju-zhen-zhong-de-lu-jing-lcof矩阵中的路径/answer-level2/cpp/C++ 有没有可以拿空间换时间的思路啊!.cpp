执行用时：224 ms       38.82%
内存消耗：146.9 MB     100%
```
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[i].size();++j)
                if(board[i][j]==word[0]){               // 两个循环寻找首字母匹配的坐标,存入pair
                    vector<pair<int,int>> path{make_pair(i,j)};
                    if(path_expand(board,path,word,1))  // 探索所有路径
                        return 1;
                }
        }
        return 0;   // 只有当所有路径都不存在时才能返回0
    }
    bool path_expand(vector<vector<char>>& board,vector<pair<int,int>>& path,string word,int index){
        if(index==word.size())
            return 1;
        int x=path[path.size()-1].first,y=path[path.size()-1].second;
        if(x>0 && board[x-1][y]==word[index] && path_judge(path,{x-1,y})){  // 左移
            vector<pair<int,int>> auxil=path;
            auxil.push_back({x-1,y});
            if(path_expand(board,auxil,word,index+1))   // 递归探索
                return 1;
        }
        if(y>0 && board[x][y-1]==word[index] && path_judge(path,{x,y-1})){  // 下移
            vector<pair<int,int>> auxil=path;
            auxil.push_back({x,y-1});
            if(path_expand(board,auxil,word,index+1))
                return 1;
        }
        if(x<board.size()-1 && board[x+1][y]==word[index] && path_judge(path,{x+1,y})){ // 右移
            vector<pair<int,int>> auxil=path;
            auxil.push_back({x+1,y});
            if(path_expand(board,auxil,word,index+1))
                return 1;
        }
        if(y<board[x].size()-1 && board[x][y+1]==word[index] && path_judge(path,{x,y+1})){  // 上移
            vector<pair<int,int>> auxil=path;
            auxil.push_back({x,y+1});
            if(path_expand(board,auxil,word,index+1))
                return 1;
        }
        return 0;   // 只有当所有移动都不符合时才能return 0
    }
    bool path_judge(vector<pair<int,int>>& path,pair<int,int> s){   // 贪吃蛇不能撞到自己的身体
        for(int i=0;i<path.size();++i)
            if(s.first==path[i].first && s.second==path[i].second)
                return 0;
        return 1;
    }
```
