### 解题思路
![微信图片_20200218130559.png](https://pic.leetcode-cn.com/841c9d5593ca72bd9d172edf1277b1f7870bfaf665bee7374f54195cb919a34b-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200218130559.png)

第一次对角线交换，反转每个元素的下标，第二次第N列与倒数第N列交换，交换列下标。至于为什么这么做，可以自行观察一下旋转前后矩阵的相关元素的下标变化。可以观察到，反转后 的元素的下标变成了原来的元素下标x,y下标交换后且y坐标变为length-N的形式。

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        for(int i=0;i<rows;i++){
            for(int j=i+1;j<rows;j++){//这里注意同元素不要直接^=操作，否则回不去，对角线都是0
                matrix[i][j] ^= matrix[j][i];
                matrix[j][i] ^= matrix[i][j];
                matrix[i][j] ^= matrix[j][i];
            }
        }
        for(int i=0;i<(rows/2);i++){
            for(int j=0;j<rows;j++){
                matrix[j][i] ^= matrix[j][rows - i - 1];
                matrix[j][rows - i - 1] ^= matrix[j][i];
                matrix[j][i] ^= matrix[j][rows - i - 1];
            }
        }
    }
};
```