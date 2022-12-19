**主要思路：**
对于每一行计算前缀和，对于每一列计算行累加和，然后这个问题就变成和目标和子数组相同了。

**算法步骤：**
1）排除特殊情况，初始化行、列、存放结果的值
2）然后我们计算每一行的前缀和
3）接下来就是利用滑动窗口来进行扫描了,固定i，然后移动j，来寻找target值。注：把这里的i和j想成两个竖着的线，也就是列。
```cpp
class Solution {
private:
    unordered_map<int,int> mp;
public:
    //对于每一行计算前缀和，对于每一列计算行累加和，然后这个问题就变成和目标和子数组相同了
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        //特殊情况直接排除
        if(matrix.size()==0||matrix[0].size()==0)return 0;
        
        //矩阵的长宽以及结果值
        int m=matrix.size(),n=matrix[0].size();
        int result=0;
        
        //对于每一行计算前缀和，对于每一列计算行累加的数组
        vector<vector<int>> sum(m,vector<int>(n,0));
        
        //计算每一行的前缀和
        for(int i=0;i<m;i++)
        {
            sum[i][0]=matrix[i][0];
            for(int j=1;j<n;j++)
            {
                sum[i][j]=sum[i][j-1]+matrix[i][j];
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                mp.clear();
                int temp=0;
                
                //滑动窗口寻找目标值
                for(int k=0;k<m;k++)
                {
                    //代码中最关键的部分，计算扫描线i和j之间的矩阵值
                    temp+=(sum[k][j]-sum[k][i]+matrix[k][i]);  
                    
                    //此矩阵值为target，增加result
                    if(temp==target) result++;
                    
                    //每次是一个矩阵值，mp里面保存着子矩阵值
                    if(mp.find(temp-target)!=mp.end())
                        result+= mp[temp-target];
                    mp[temp]++;
                }    
            }
        }
        return result;
    }
};
```
