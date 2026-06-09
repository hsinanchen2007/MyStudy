# 题解：
### 因为题目要求原地旋转，那么我们就希望找到类似一维数组平移操作的对应关系，通过观察，如果把矩阵看作洋葱，我们依次旋转好每层的元素位置对其它层没有影响，然后观察每一层的元素对应关系，我们会发现问题可以转化为个二维的数组平移。以2 * 2的矩阵为例，见下图的位置关系：
![940CB31AB3559A62E972DD179662CAB5.png](https://pic.leetcode-cn.com/a6793e169300f7d58f7d3895787c302110ac7730ab0ac6fbac0be72595552ea3-940CB31AB3559A62E972DD179662CAB5.png)
### 对于箭头指向的每组元素都和一维数组的平移操作类似,只需一个临时变量即可完成原地旋转，对于元素matrix[i][j]，它的位置变换关系是：
### (n-1-j,i) -> (i,j) -> (j,n-1-i) -> ...(n-1-j,i)
### 按照这种对应关系对每一层进行平移即可完成原地旋转。
# Source Code(C++):

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n/2;i++){//n*n的矩形有n/2层正方形，依次对每层进行旋转
            for(int j=i;j<(n-i-1);j++){//第i层的正方形上边起点为i,长度为n-2*i,注意只需旋转前(n-2*i-1)个元素
                //类似一维数组的平移操作
                int tmp = matrix[i][j];//
                int i1=i,j1=j;//起点
                int end_i = j1,end_j = n-1-i1;//终点  
                while(i1!=end_i||j1!=end_j){//旋转一个周期
                    matrix[i1][j1] = matrix[n-1-j1][i1];//得到下一个位置的值
                    int t = i1;//(i,j)->(j,n-1-i)
                    i1 = n-1-j1;
                    j1 = t;//旋转到下一个位置
                }
                matrix[i1][j1] = tmp;//
            }
        }
    }
};
```
# 复杂度分析
### Time Complexity: 我们只需要访问每个元素一次，故时间复杂度为O(n^2)
### Space Complexity: O(1)