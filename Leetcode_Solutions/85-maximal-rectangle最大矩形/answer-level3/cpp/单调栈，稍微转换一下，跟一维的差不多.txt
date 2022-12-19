### 解题思路
对于二维矩阵，可以从第一行遍历到最后一行，对每一行而言，计算每一列以该行该列为起点的连续1的数量作为高度，这个高度很好求，即当前该行该列为1,高度++，为0则直接置0。

然后对每一行来说，知道了高度，就变成了我们熟悉的单调栈的裸题了，求L，R数组，求法如我上一题的题解，[上题的链接](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/dan-diao-zhan-luo-ti-by-whut_hj/?editing=dan-diao-zhan-luo-ti-by-whut_hj)最后返回最大值就OK了，会做上一题，这题一分钟就能AC。

### 代码

```cpp
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        if(n == 0) return 0;
        int m=matrix[0].size();
        if(m == 0) return 0;        //判断是否是空矩阵

        vector <int> heights(m,0);
        int ans=0;
        for(int j=0;j<n;j++){       //j为每一行
            for(int i=0;i<m;i++){   //求该行的高度
                if(matrix[j][i] == '0') heights[i]=0;
                else heights[i]+=1;
            }
            int len = m,top;        //跟上题一摸一样的代码，单调栈求最大面积
            vector <int> l(len,-1),r(len,-1);
            stack <int> sta;
            for(int i=0;i<len;i++){ //求L数组
                while(!sta.empty()&&heights[i]<=heights[sta.top()]) sta.pop();
                if(sta.empty()) l[i]=0;
                else l[i] = sta.top()+1;
                sta.push(i);
            }
            while(!sta.empty()) sta.pop();

            for(int i=len-1;i>=0;i--){  //求R数组
                while(!sta.empty()&&heights[i]<=heights[sta.top()]) sta.pop();
                if(sta.empty()) r[i]=len-1;
                else r[i] = sta.top()-1;
                sta.push(i);
            }
            for(int i=0;i<len;i++){     //求当前行的最大面积
                ans = max(ans,(r[i]-l[i]+1)*heights[i]);
            }
        }
        return ans;
    }
};
```