### 解题思路
此处撰写解题思路
这个方法可以同时去掉行和列，但是跑下来时间差不多。
估计是：
1、之前的方法在去掉了matrix[i][0] > target的数组基础上 又去掉了剩下数组中的matrix[i][matrix[i].size()-1] < target的数组
2、在剩下的数组中又可以使用二分查找法。
这种方法虽然可以同时去掉行和列但是也就无法使用二分查找等算法，所以最终执行时间差不多。
m行n列列的矩阵中：
上一个解法时间复杂度是m*lg(n)
这个解法时间复杂度现在还没有思路该怎么算 不过应该差不多 以后补上 

### 代码

```cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
       // 上次提交的方法只是去掉了matrix[i][0]比target大的数组 看到一个方法可以同时去掉行和列这里重写一下
       // 例子中使用左下角来做哨兵 这里使用右上角来做哨兵 原理一样
       if(matrix.size() == 0 ) return false;
       if(matrix[0].size() == 0 ) return false;

       int i = 0,j=matrix[0].size()-1;
       int SentinelI = matrix.size()-1,SentinelJ = 0;
       while(i <= SentinelI && j >= SentinelJ)
       {
           if(matrix[i][j] == target)
           {
               return true;
           }else if(matrix[i][j] > target)
           {
               j --;
           }else if(matrix[i][j] < target)
           {
               i ++;
           }
       }

        return false;
    }
};
```