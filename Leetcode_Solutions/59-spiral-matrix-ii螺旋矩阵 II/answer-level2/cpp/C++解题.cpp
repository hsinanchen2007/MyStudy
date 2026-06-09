class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        int left=0,right=n-1;
        int up=0,down=n-1;
        int k=1;
        while(true){
            if(left<=right){
                for(int i=left;i<=right;++i){
                    res[up][i]=k;
                    k++;
                }
            }
            else
                break;
            up++;
            if(up<=down){
                for(int i=up;i<=down;++i){
                    res[i][right]=k;
                    k++;
                }
                    
            }
            else
                break;
            
            
            right--;
            if(right>=left){
                for(int i=right;i>=left;--i)
                    res[down][i]=k++;
            }
            else
                break;
            down--;
            if(down>=up){
                for(int i=down;i>=up;--i)
                    res[i][left]=k++;
            }
            else
                break;
            left++;
        }
        return res;
    }
};