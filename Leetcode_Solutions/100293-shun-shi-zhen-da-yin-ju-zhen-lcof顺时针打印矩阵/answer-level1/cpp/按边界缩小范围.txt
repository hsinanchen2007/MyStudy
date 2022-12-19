### 解题思路
思路其实比较简单，但调试的时候有些费劲。top bottom, left right 其实就是不断往中心缩进的四条边，每一次的循环都是依靠这些条边展开，同时又要满足对应的条件：

- 索引应该在top 与bottom 之间
- 索引应该在left 和 right之间


自然，以下异常情况就要被跳过：
- 当buttom < top 时，就说明从下往上的过程走过了；
- 当right < left时，就说明从右往左的过程穿透了；


### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) {
            return {};
        }
        vector<int> res;
        int column = matrix[0].size();
        int row = matrix.size();
        int top = 0; // 左右开始的索引
        int bottom = row - 1; // 上到下开始的索引
        int left = 0; // 从下到上开始的索引
        int right = column - 1 ; // 从右往左开始的索引
        
        while(top <= bottom && left <= right) {
            // 从左往右
            for(int i = left; i <= right; i++) {
                if(bottom < top) break;
                res.push_back(matrix[top][i]);
            }
            top++;
            // 从上到下
            for(int i = top; i <= bottom; i++) {
                if(right < left) break;
                res.push_back(matrix[i][right]);
            }
            right--;
            // 从右到左 
            for(int i = right; i >= left; i--) {
                if(bottom < top) break;
                res.push_back(matrix[bottom][i]);
            }
            bottom--;
            // 从下到上
            for(int i = bottom; i >= top; i--){
                if(right < left) break;
                res.push_back(matrix[i][left]);
            }
            left++;
        }

        return res;

    }
};
```
## 分析
- 时间复杂度 等于循环N，所以时间复杂度应该是`O(N))`
- 空间复杂度 