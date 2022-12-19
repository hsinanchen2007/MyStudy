### 解题思路
此处撰写解题思路
## 方法一：使用辅助数组
若直接在原数组上进行旋转，则会出现数据被覆盖的问题；所以简单解决，使用辅助数组；
## 方法二：原数组进行旋转，只取第一象限
题目中要求能否在原数组操作，当然在原数组操作相比使用辅助数组更节约空间；
而在原数组操作则不能遍历全部，否则很容易发现覆盖。
数据转移过程:
1. (i,j)->(j,n-i-1);
2. (j,n-i-1)->(n-i-1,n-j-1)
3. (n-i-1,n-j-1)->(n-j-1,i)
4. (n-j-1,i)->(i,j)
发现旋转过程中，四个元素组成一个旋转轮回。
- 将数组分为四个部分，即分为四个象限，只取第一象限的值来进行旋转即可
1. 当n维数组为奇数，取一条象限边线
2. n维数组是偶数，则不存在两个象限相交的变线


### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        for(int i=0;i<N/2+1;i++){
            for(int j=0;j<N/2+1;j++){
                if(N%2&&j==N/2) continue;   //如果是奇数，只取一条边界
                if(N%2==0&&i==N/2||N%2==0&&j==N/2) continue;//偶数则会多一层把边界全去掉
                int temp = matrix[i][j];
                matrix[i][j] = matrix[N-j-1][i];
                matrix[N-j-1][i]=matrix[N-i-1][N-j-1];
                matrix[N-i-1][N-j-1]=matrix[j][N-i-1];
                matrix[j][N-i-1] = temp;
            }
        }
    }
};
```