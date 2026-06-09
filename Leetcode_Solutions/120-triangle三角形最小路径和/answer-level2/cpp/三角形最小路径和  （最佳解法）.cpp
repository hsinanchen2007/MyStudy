class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
       vector<int> dp(triangle.size());//长度为行数也就是最后一行的数据个数，也就是可以推导出使用动态规划的思想。
       vector<int> pre(triangle.size());
       if(triangle.size()==1)  return triangle[0][0];
       for(int j=0;j<triangle.size();j++){
           for(int i=0;i<=j;i++){
               if(i==0) dp[i]=pre[i]+triangle[j][i];
               else if(i==j) dp[i]=triangle[j][i]+pre[i-1];
               else
                   dp[i]=min(pre[i],pre[i-1])+triangle[j][i];
               }
               pre.assign(dp.begin(),dp.end());
            }
          sort(dp.begin(),dp.end());
          return  dp[0];
      }
};
/*  原地更新dp数组*/
1.根据题意，对于任一，我们每次只能从左上或者右上的走到该点，所以显然对于点i来说，到点i的最短路径等于左上的最短路径和右上的最短路径的最小值加上i的值。
2.基于以上分析，我们可以分析这就是动态规划问题，我们需要一个数组来存储最后一层的最短路径即可，我们发现题目的规律来讲由于题目的特点，我们只需要新建一个行数的一样的数组大小就可以
3.我们注意到原地更新有困难，会出现数据重叠，于是，我们有另一个数组来保存之前的状态，更新dp数组的同时更新pre数组，pre数组是dp的之前的状态

UESTC 微笑