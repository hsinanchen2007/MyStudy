 ```c++  
 class Solution {
    public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> res;
        for(int i=0;i<A.size();i++)
        {   vector<int> temp;
            res.push_back(temp);
            for(int j=A[i].size()-1;j>=0;j--)
            {
                res[i].push_back(A[i][j]);    
            }
        }
        
        for(int i=0;i<res.size();i++)
        {
            for(int j=0;j<res[i].size();j++)
            {
                if(res[i][j]==0)
                {
                    res[i][j]=1;
                }
                else
                {
                    res[i][j]=0;
                }
            }
        }
        
        return res;
      }
      };