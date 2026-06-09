- 借助一维数组，记录到达当前位置路径的最小和
- 当前位置的路径最小和为当前值加上minOfThree(up,leftUp,rightUp);
- 状态方程为：**temp[j]=temp[j]+minOfThree(up,leftUp,rightUp)**

``` C++
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        if(A.empty()) return 0;
        int up=INT_MAX,leftUp=INT_MAX,rightUp=INT_MAX;
        vector<int> res=A[0];
        for(int i=1;i<A.size();i++)
        {
            vector<int> temp=A[i];
            for(int j=0;j<temp.size();j++)
            {
                //记录up,leftUp,rightUp
                up=res[j];
                leftUp=j-1>=0?res[j-1]:INT_MAX;
                rightUp=j+1<res.size()?res[j+1]:INT_MAX;
                temp[j]+=minOfThree(up,leftUp,rightUp);
            }
            res=temp;
        }
        int minValue=res[0];
        for(int i=0;i<res.size();i++)
        {
            if(minValue>res[i])
                minValue=res[i];
        }
        return minValue;
    }
    int minOfThree(int a,int b,int c)
    {
        int res=a;
        if(res>b) res=b;
        if(res>c) res=c;
        return res;
    }
};
```