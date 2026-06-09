
![image.png](https://pic.leetcode-cn.com/f541a3b009192a82fb0a47b8f4a02b601a19cb06bb4c8ae2fd088ea6c1432e67-image.png)

```
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        for(int i(0);i<A.size();i++)
        {
            if(A[i][0]==0)
            {
                for(int j(0);j<A[i].size();j++)
                {
                    if(A[i][j]==0)
                    {
                        A[i][j]=1;
                    }
                    else
                    {
                        A[i][j]=0;
                    }
                }
            }
        }
        for(int i(0);i<A[0].size();i++)
        {
            int zero_count(0);
            int one_count(0);
            for(int j(0);j<A.size();j++)
            {
                if(A[j][i]==0)
                    zero_count++;
                else
                    one_count++;
            }
            if(zero_count>one_count)
            {
                for(int j(0);j<A.size();j++)
                {
                    if(A[j][i]==0)
                        A[j][i]=1;
                    else
                        A[j][i]=0;
                }
            }
        }
        int result(0);
        for(int i(0);i<A.size();i++)
        {
            int flag=1;
            for(int j(A[i].size()-1);j>=0;j--)
            {
                result+=flag*A[i][j];
                flag=flag*2;
            }
        }
        return result;
    }
};
```
