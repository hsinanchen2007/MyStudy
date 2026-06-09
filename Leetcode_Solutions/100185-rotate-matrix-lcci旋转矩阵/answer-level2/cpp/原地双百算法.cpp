### 解题思路
此处撰写解题思路
对一个矩阵，
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],
先对主对角线交换,即1-9连线，为
[
  [1,4,7],
  [2,5,8],
  [3,6,9]
],
再对每一行反转，为
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
刚好为旋转90度的效果
用这个思路可以写原地代码。
对两个int x,y;交换其值可以用中间变量temp
也可以借助加法
```
x = x + y;
y = x - y;
x = x - y;
```
或者异或运算
```
x = x ^ y;
y = x ^ y;
x = x ^ y;
```
都可以实现两个数的交换

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m=matrix.size();
        for(int i=0;i<m;i++)
            for(int j=i+1;j<m;j++){
                matrix[i][j]^=matrix[j][i];
                matrix[j][i]^=matrix[i][j];
                matrix[i][j]^=matrix[j][i];
            }
        int left,right;
        for(int i=0;i<m;i++){
            left=0,right=m-1;
            while(left<right){
                matrix[i][left]^=matrix[i][right];
                matrix[i][right]^=matrix[i][left];
                matrix[i][left]^=matrix[i][right];
                left++;
                right--;
            }
        }
    }
};
```