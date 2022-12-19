### 解题思路
此题的计算思路是容易想到的，在不增加额外存储空间下通过每个矩阵正方形边的逐个替换来实现旋转，但难点在于swap代码的实现，不断将第一行与要替换的其他三行（列）做交换，做完交换则得到了旋转后的正方形边，另外注意下标问题，很多地方需要-1处理。下面的代码采用的是
![1.png](https://pic.leetcode-cn.com/bf3c7b419df593195a9ad0ec2f9bc26f6514e3fb6b71ae327ba11d6d742b108c-1.png)
但是第一开始的想法是
![2.png](https://pic.leetcode-cn.com/87b8bf11a6cac6b4a66372ad98cd9ad9fc9c46148ccc6d6fe15a196a374fb38a-2.png)
就是逐渐内缩的正方形边进行遍历，1234对应着第一层次需要旋转的部分，按照图片所示依次进行旋转就行，56对应第二层次，7就可以不旋转了因为只有他自己。而每个元素旋转的代码同上，只是在i,j遍历时不太一样，注意千万不要把行或列最后一个元素作为每一层次的最后元素（比如对灰底白字1和灰底黑字1做了交换），不然旋转时会不断地覆盖交换，产生严重错误。



### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return;
        int m_size = matrix.size();
        int cols = 0,rows= m_size/2-1;
        if(m_size%2){
            cols = m_size/2;
        }
        else{
            cols = m_size/2-1;
        }
        for(int i=0;i<=rows;i++){
            for(int j=0;j<=cols;j++){
                swap(matrix[i][j],matrix[j][m_size-1-i]);
                swap(matrix[i][j],matrix[m_size-1-i][m_size-1-j]);
                swap(matrix[i][j],matrix[m_size-1-j][i]);
            }
        }
    }
};
```