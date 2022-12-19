
 ```
//模拟顺时针， 用上下左右记录边界值，走完一面，那一面的位置移动。

vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //为空直接返回
        if(matrix.size()==0 ||matrix[0].size()==0)  return {};
        vector<int> ans;
        //分别记录上下左右的边界。
        int up = 0, down = matrix.size()-1, left = 0, right = matrix[0].size()-1;
        //当 上大于下，或者左大于右跳出循环
        while(up <= down && left<=right)    {
            //上边横   记录上边
            for(int i = left; i<=right; i++) {
                ans.push_back(matrix[up][i]);
            }
            up++;
            if(up >down)    return ans;             //如果出现上大于下 则表明已经走完
            //右边竖   记录右边
            for(int i = up;i<=down; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(left>right)  return ans;             //如果出现左大于右 则表明已经走完
            //最下边   记录最下边
            for(int i = right; i>=left; i--) {
                ans.push_back(matrix[down][i]);
            }
            down--;
            if(down < up)   return ans;
            //左边竖   记录最左边
            for(int i = down; i>=up; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
            if(left>right)  return ans;
        }
        return ans;
    }
```