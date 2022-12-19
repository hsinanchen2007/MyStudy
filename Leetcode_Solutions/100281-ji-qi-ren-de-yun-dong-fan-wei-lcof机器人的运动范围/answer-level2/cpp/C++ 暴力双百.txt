### 解题思路


### 代码

```cpp
class Solution {
    bool checkfunction(int i,int j,int k)
    {   //计算坐标是否符合要求
        int num=0;
        while(i)
        {
            num+=i%10;
            i=i/10;
        }
        while(j)
        {
            num+=j%10;
            j=j/10;
        }
        return num<=k;
    }

public:
    int movingCount(int m, int n, int k) {
        if(n==0||m==0) return 0;
        if(k==0) return 1;

        vector<vector<bool>> nums(m,vector<bool>(n,false));   //用于标记位置是否可通过
        nums[0][0]=true;    //从(0,0)出发

        int num=1;  //累加变量,(0,0)也算一个格子

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if( ((i-1>=0&&nums[i-1][j]==true) || (j-1>=0&&nums[i][j-1]==true)) && checkfunction(i,j,k))
                {
                    nums[i][j]=true;
                    num++;
                }
            }
        }
        return num;
    }
};
```