```
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {

        vector<vector<int>> res;
        set<vector<int>> q_set;
        for(auto i = queens.begin();i!=queens.end();i++){
            q_set.insert(*i);
        }
        vector<vector<int>> conf = {
            {1,0,1,0},
            {0,1,0,1},
            {-1,0,-1,0},
            {0,-1,0,-1},
            {1,1,1,1},
            {-1,-1,-1,-1},
            {1,-1,1,-1},
            {-1,1,-1,1}
        };
        for(int k=0;k<8;k++){
            for(int i=king[0]+conf[k][0],j=king[1]+conf[k][1]; i>=0&&i<8&&j>=0&&j<8; 
                i+=conf[k][2], j+=conf[k][3] ){
            vector<int> temp = {i,j};
            if(q_set.count(temp)==1){res.push_back(temp);break;}
        }
        }        
          
        return res;
        
    }
};
```