### 解题思路
此处撰写解题思路
首先想到旋转是从最中间的部分开始，逐渐向四周推导。
于是先从2x2矩阵的开始推导。
1. 1,2
2. 3,4
观察交换前后的数组可知，可以先将数组的上下位置进行交换
1. 3,4
2. 1,2
此时3,2已经符合解答的位置，只需要交换“/”方向对角线的数字即可。
1. 3,1
2. 4,2
同理我们推3x3（奇数N），4x4（偶数N）
很容易发现能得出同样的结论（先交换上下的相对位置，再交换“/”斜对角线的相对位置）
由此所有的NxN矩阵都可以如此变换

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int _size=matrix.size();
        int h_size=_size/2;
        if(_size<=1)
        {
            return;
        }
        for(int i=0;i<h_size;i++)
        {
            for(int j=0;j<_size;j++)
            {           
                swap(matrix[i][j],matrix[_size-1-i][j]);  //上下交换
            }
        }
        for(int i=0;i<_size;i++)
        {
            for(int j=i+1;j<_size;j++)
            {
                swap(matrix[i][j],matrix[j][i]);      //对角线交换
            }
        }
    }
};
```