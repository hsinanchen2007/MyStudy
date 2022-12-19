### 解题思路
把每一行都看成一层直方图，高度为从这里向上所能连通的1的数量
从第二行开始，如果矩阵等于1，那么柱状图的高度等于上一层的高度+1，否则等于0
对每一层都求直方图的最大面积即可。

### 代码

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int> a) {
        vector<int>heights=a;
        heights.push_back(0);
        int i,k,m=0,n=heights.size();
        stack<int>s;
        for(i=0;i<n;i++){
            while(!s.empty()&&heights[i]<heights[s.top()]){
                k=s.top();s.pop();
                m=max(m,heights[k]*(s.empty()?i:(i-s.top()-1)));
            }
            s.push(i);
        }
        return m;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0||matrix[0].size()==0)return 0;
        int i,j,s=0,m=matrix.size(),n=matrix[0].size();
        vector<int>a(n);
        for(i=0;i<n;i++){
            if(matrix[0][i]=='0')a[i]=0;
            else a[i]=1;
        }
        s=max(s,largestRectangleArea(a));
        for(i=1;i<m;i++){
            for(j=0;j<n;j++){
                if(matrix[i][j]=='1')a[j]++;
                else a[j]=0;
            }
            s=max(s,largestRectangleArea(a));
        }
        return s;
    }
};
```