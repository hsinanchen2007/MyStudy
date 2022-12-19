### 解题思路
就拿
1 2 3   7 4 1
4 5 6   8 5 2
7 8 9   9 6 3
举例，
我们发现1到3的位置，3到9的位置，9到7的位置，7到1的位置。
同样，2到6的位置，6到8的位置，8到4的位置，4到2的位置。
所以，只要每次将x*x大小的正方形边上的数换到四个边上的对应位置就可以。然后再去处理(x-1)*(x-1)的正方形。
每次用三次swap()：
swap(matrix[0][0], matrix[0][2]);
swap(matrix[0][0], matrix[2][2]);
swap(matrix[0][0], matrix[2][0]);
就能达到1，3，9，7四个数字旋转的目的。
具体代码如下。

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.empty()) return;
        int index1=0, index2=matrix.size()-1;
        while(index1<index2){
            int k=index2-index1;
            for(int i=0; i<k; i++){
                swap(matrix[index1][index1+i], matrix[index1+i][index2]);
                swap(matrix[index1][index1+i], matrix[index2][index2-i]);
                swap(matrix[index1][index1+i], matrix[index2-i][index1]);
            }
            index1++;
            index2--;
        }
    }
};
```