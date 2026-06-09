> 思路描述：这个可以定义dx和dy作为移动方向，初始时dx = 0，dy  =1，向右移动，然后dx = 1，dy = 0，向下移动，以此类推其中需要注意需要改变边界条件。

```C++
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dx = 0, dy = 1;
        int i = 0, j = -1;
        //初始j设为-1是因为后面有加一操作
        if(matrix.size() == 0)
            return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> nums;
        while(m != 0 && n != 0){
            //左右移动
            if(dx == 0){
                for(int k = 0; k < n; k ++){
                    j += dy;
                    nums.push_back(matrix[i][j]);
                }   
                dx = dy; dy = 0;
                m --;
            }
            //上下移动
            else if(dy == 0){
                for(int k = 0; k < m; k ++){
                    i += dx;
                    nums.push_back(matrix[i][j]);
                } 
                //反向
                dy = -1*dx; dx = 0;  
                n --;
            }
        }
        return nums;
    }
};
```

![image.png](https://pic.leetcode-cn.com/f15fb9e901618deede538a615c50dbf6047a034538e4c4d4c4a95bc6b59e651f-image.png)
