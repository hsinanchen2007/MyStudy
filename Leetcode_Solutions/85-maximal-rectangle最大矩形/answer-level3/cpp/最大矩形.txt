### 解题思路


### 代码

```cpp
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()<1){
            return 0;
        }

        int row = matrix.size();
        int col = matrix[0].size();
        cout << row << endl;
        cout << col << endl;
        int maxArea = 0;
        vector<int> height(col);
        vector<int> left(col);
        vector<int> right(col,col);

        for(int i=0;i<row;i++){

            int curL = 0;
            int curR = col;
            for(int j=0;j<col;j++){
                if(matrix[i][j] == '1'){
                    height[j] = height[j] + 1;
                }else{
                    height[j] = 0;
                }
            }

            for(int j=0;j<col;j++){
                if(matrix[i][j] == '1'){
                    left[j] = max(curL,left[j]);
                }else{
                    left[j] = 0;
                    curL = j+1;
                }
            }

            for(int j=col-1;j>=0;j--){
                if(matrix[i][j] == '1'){
                    right[j] = min(right[j],curR);
                }else{
                    curR = j;
                    right[j] = col;
                }
            }

            for(int j=0;j<col;j++){
                maxArea = max(maxArea,height[j]*(right[j] - left[j]));
            }

        }
        return maxArea;
    }
};
```