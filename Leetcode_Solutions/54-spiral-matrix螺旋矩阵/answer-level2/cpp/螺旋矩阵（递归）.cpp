递归，但是中间有一个修修补补。
class Solution {
public:
    void spiralOrderCore(int startx,int starty,int endx,int endy,vector<int> &res,vector<vector<int>> matrix){
        for(int j=starty;j<=endy;j++){
            res.push_back(matrix[startx][j]);
        }
        for(int i=startx+1;i<=endx;i++){
            res.push_back(matrix[i][endy]);
        }
        for(int j=endy-1;j>=starty;j--){
            if(endx!=startx){
                res.push_back(matrix[endx][j]);
            }
            
        }
        for(int i=endx-1;i>=startx+1;i--){
            if(endy!=starty){
                res.push_back(matrix[i][starty]);
            }
        }
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> res;
        int startx=0;
        int starty=0;
        int endx=row-1;
        int endy=col-1;
        while(startx<=endx&&starty<=endy){
            spiralOrderCore(startx,starty,endx,endy,res,matrix);
            startx++;
            starty++;
            endx--;
            endy--;
        }
        return res;
    }
};