```
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int up = 0;
        int down = n-1;
        int left = 0;
        int right = n-1;
        int max = n*n;
        n = 1;
        while(n<=max){
            if(up <= down){
                for(int i=left; i<=right; i++){
                    res[up][i] = n++;
                }
                up++;
            }
            if(left <= right){
                for(int i=up; i<=down; i++){
                    res[i][right] = n++;
                }
                right--;
            }
            if(down >= up){
                for(int i=right; i>=left; i--){
                    res[down][i] = n++;
                }
                down--;
            }
            if(right >= left){
                for(int i=down; i>=up; i--){
                    res[i][left] = n++;
                }
                left++;
            }
        }
        return res;
    }
};
```
