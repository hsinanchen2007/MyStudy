### 解题思路
此处撰写解题思路

思路如下：https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/solution/an-bian-jie-suo-xiao-fan-wei-by-fzbme/

### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) {
            return {};
        }

        int row = matrix.size();
        int column = matrix[0].size();

        int top = 0;
        int bottom = row - 1;
        int left = 0; 
        int right = column - 1;
        
        vector<int> res;

        while(left <= right && top <= bottom) {
            for(int i = left; i <= right; i++) {
                if(bottom < top) break;
                res.push_back(matrix[top][i]);
            }
            top++;

            for(int i = top; i <= bottom; i++){
                if(right < left) break;
                res.push_back(matrix[i][right]);
            }
            right--;

            for(int i = right; i>=left; i--) {
                if(bottom < top) break;
                res.push_back(matrix[bottom][i]);
            }
            bottom--;

            for(int i = bottom; i>= top; i--) {
                if(right < left) break;
                res.push_back(matrix[i][left]);
            }
            left++;
        }

        return res;
    }
};
```