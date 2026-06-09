### 解题思路
A、思路：将问题拆分为：1、寻找到达每个点的最短路径2、到达每个末端的最短路径里筛选出最短路径。

B、理解：对于程序来说，本方法是一个自顶向下的方法，最新的到达本处的最短路径由以前的路径更新出来并在最后从这些路径中选最优的，而不是从上往下让程序直接“选择”（走左/右）出一条最优路径，因为局部最优不一定导致全局最优）

C、注意：1、每一行的点由前一行相邻两点更新，对于首位两个点要特殊处理（下标越界）
        2、用临时变量复制路径从出发到前一行的结果，以防遍历时后一行需要利用前一行某结果时，此结果已经被更新了。

D：自底向上的方法也是由一行更新到达本处的最短路径，好处是越往顶点走端点越少，最后直接得到到达顶点（走穿三角形）的路径。

### 代码

```cpp
#include<algorithm>
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int r[triangle.size()];
        int temp[triangle.size()];
        r[0]= triangle[0][0];
        for (int i = 1 ; i< triangle.size() ; i++){
            //用temp复制路径从出发到前一行的结果，以防遍历时后一行需要用前一行某结果是，此结果已经被更新了。
            for(int k = 0 ; k < triangle[i-1].size() ; k++ )temp[k]=r[k];
            //处理每一行头尾
            r[0]=temp[0]+triangle[i][0];
            r[triangle[i].size()-1]=temp[triangle[i-1].size()-1]+triangle[i][triangle[i].size()-1];
            //由前一行更新本行除去头尾的部分
            for (int j = 1 ; j < triangle[i].size()-1 ; j++){
                r[j]=min(temp[j]+triangle[i][j],temp[j-1]+triangle[i][j]);
            }
        }
        return *min_element(r,r+triangle.size());
        //min_element返回的是指针用*得到数值
    }
};
```