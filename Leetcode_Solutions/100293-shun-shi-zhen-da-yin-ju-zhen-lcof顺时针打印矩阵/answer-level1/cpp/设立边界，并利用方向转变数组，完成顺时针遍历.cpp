```
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        int k=0;
        vector<int> res;
        int r=matrix.size();
        if(r==0) return res;
        int c=matrix[0].size();
        vector<vector<int>> visit(r+2,vector<int>(c+2,0));
        for(int i=0;i<r+2;i++){
            visit[i][0]=1;
            visit[i][c+1]=1;
        }
        for(int j=0;j<c+2;j++){
            visit[0][j]=1;
            visit[r+1][j]=1;
        }
        int count=0;
        
        res.push_back(matrix[0][0]);
        visit[1][1]=1;
        count++;
        if(count==r*c) return res;
        int i=0,j=0;
        while(1){
            i+=dx[k];
            j+=dy[k];
            if(visit[i+1][j+1]==1){
                i-=dx[k];
                j-=dy[k];
                k++;
                if(k==4) k=0;
                i+=dx[k];
                j+=dy[k];
            }
            res.push_back(matrix[i][j]);
            visit[i+1][j+1]=1;
            count++;
            if(count==r*c) break;
                
        }
        return res;

    }
};

```

