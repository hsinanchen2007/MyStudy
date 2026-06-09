### 解题思路
1、寻找到达每个点的最短路径，一层一层向下
2、到达每个末端的最短路径里筛选出最短路径 
3、直接操作原数据

### 代码

```cpp
#include<algorithm>
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //直接在原数据上操作
        for (int i = 1 ; i< triangle.size() ; i++){
            //处理每一行头尾
            triangle[i][0]=triangle[i-1][0]+triangle[i][0];
            triangle[i][triangle[i].size()-1]=triangle[i-1][triangle[i-1].size()-1]+triangle[i][triangle[i].size()-1];
            //由前一行更新本行除去头尾的部分
            for (int j = 1 ; j < triangle[i].size()-1 ; j++){
                triangle[i][j]=min(triangle[i-1][j]+triangle[i][j],triangle[i-1][j-1]+triangle[i][j]);
            }
        }
        return *min_element(triangle[triangle.size()-1].begin(),triangle[triangle.size()-1].end());
        //min_element返回的是指针用*得到数值
    }
};




```