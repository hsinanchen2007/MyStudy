### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        int maxt;
       vector<int> height(matrix.size()+2,0); 
       for(int k=0;k<matrix.size();k++)
        {
            if(matrix[k][0]=='1') height[k+1]=1;
            else   height[k+1]=0;
        }/*初始化第一行*/
        maxt=Monotonousstack(height); 

        for(int j=1;j<matrix[0].size();j++)
        {
            for(int i=0;i<matrix.size();i++)
            {
               if(matrix[i][j]=='1')
                   height[i+1]=height[i+1]+1;
                else
                   height[i+1]=0;
            }/*对heignt进行动态规划*/
            maxt=max(maxt,Monotonousstack(height));
        }
     return maxt;
    }

    int Monotonousstack(vector<int> height)
    {
         int maxs=0;
         stack<int> sta;
         sta.push(0);
         for(int i=1;i<height.size();i++)
         {
            while(height[i]<height[sta.top()])
            {
               int temp=height[sta.top()];
               sta.pop();
               maxs=max(maxs,temp*(i-sta.top()-1));
            }
            sta.push(i);
         }
      return maxs;
    }

};
```