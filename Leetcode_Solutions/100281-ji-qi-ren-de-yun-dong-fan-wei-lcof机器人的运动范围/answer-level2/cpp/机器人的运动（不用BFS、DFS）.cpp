
```
class Solution {
public:
    int positionSum(int num){
        int res = 0;
        while(num){
            res += num % 10;
            num /= 10;
        }
        return res;
    }

    int movingCount(int m, int n, int k) {
        int res = 0;
        int row = m;
        int column = n;
        int used[m][n];
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                used[i][j] = 1;
            }
        }
        for(int i = 0; i < row; i++){
            int row_position_sum = positionSum(i);
            if(row_position_sum > k){
                row = i;
                break;
            }
            for(int j = 0; j < column; j++){
                int column_position_sum = positionSum(j);
                if(column_position_sum > k){
                    column = j;
                    continue;
                }
                if(row_position_sum + column_position_sum <= k){
                    if((i - 1 >=0 && used[i - 1][j] == 0)
                    ||(j - 1 >=0 && used[i][j - 1] == 0)
                    || (i == 0 && j == 0)){
                        res++;
                        used[i][j] = 0;
                    }
                }
            }
        }
        return res;
    }
};
```
