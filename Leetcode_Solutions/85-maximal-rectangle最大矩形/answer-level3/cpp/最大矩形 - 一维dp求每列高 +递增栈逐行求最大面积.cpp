### 解题思路
１．列值的逐行累加所以适合用一维dp求每列高
２．逐行求最大面积，并与当前最大值比较，最终求出全局的最大面积。

### 代码

```cpp
class Solution {
public:
    int largestArea(const vector<int> &dp)
    {
        int max_area = 0 ;
        if(dp.empty()) return max_area ;

        stack<pair<int, int>> stk ;
        stk.push({-1 , 0}) ;

        int len = dp.size() ;
        
        for(int i=0 ; i<len ; i++)
        {
            while(stk.top().first!=-1 && stk.top().second >= dp[i])
            {
                auto val = stk.top() ;
                stk.pop();
                max_area = max(max_area , val.second * (i - stk.top().first - 1) ) ;
            }
            stk.push({i , dp[i]}) ;
        }

        while(stk.top().first!=-1)
        {           
            auto val = stk.top() ;
            stk.pop() ;
            max_area = max(max_area , val.second* (len - stk.top().first -1)) ;
        }

        return max_area ;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int max_area = 0 ;
        if(matrix.empty()) return max_area ;

        int nrows = matrix.size() ;
        int ncols = matrix[0].size() ;

        vector<int> dp(ncols , 0) ;
        for(int i=0 ; i<ncols ; i++)
            dp[i] = (matrix[0][i] - '0') ;

        max_area = largestArea(dp) ;
        for(int i=1; i<nrows ; i++)
        {
            for(int j=0; j<ncols ; j++)
            {
                int d = int(matrix[i][j]-'0');
                dp[j] = d ? dp[j] + d : d ;
            }
            
            max_area = max(max_area , largestArea(dp)) ;
        }    

        return max_area ;   
    }
};
```