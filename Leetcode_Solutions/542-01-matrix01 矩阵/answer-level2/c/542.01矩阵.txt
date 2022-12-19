### 解题思路
有点暴力破解，和扫雷的玩法类似，不断从已知的位置向相邻位置扩散去求解未知的地方。
先将矩阵中为0的位置标记出来，之后只更新矩阵中与0距离为1的所有位置并标记，再更新与0距离为2的所有位置并标记，依次进行，直至所有位置都已被标记。
用递归会快点，但是不是很习惯用。
### 代码

```cpp
class Solution {
public:
    vector<vector<int> > updateMatrix(vector<vector<int> >& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        bool flag[10001]={false};
        int num=0,d=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {   
                    flag[i*m+j]=true;
                    num++;
               }
            }
        }
        while(num<n*m)
	    {
		    for(int i=0;i<n;i++)
		    {
			    for(int j=0;j<m;j++)
                {
                    if(flag[i*m+j]&&matrix[i][j]==d-1)
                    {
                        if(j>0&&flag[i*m+j-1]==false)
                        {
                            matrix[i][j-1]=d;
                            flag[i*m+j-1]=true;
                            num++;
                        }
                        if(j<m-1&&flag[i*m+j+1]==false)
                        {
                            matrix[i][j+1]=d;
                            flag[i*m+j+1]=true;
                            num++;
                        }
                        if(i>0&&flag[(i-1)*m+j]==false)
                        {
                            matrix[i-1][j]=d;
                            flag[(i-1)*m+j]=true;
                            num++;
                        }
                        if(i<n-1&&flag[(i+1)*m+j]==false)
                        {
                            matrix[i+1][j]=d;
                            flag[(i+1)*m+j]=true;
                            num++;
                        }
                    }
                    if(num==n*m)
                    {   break;  }
                }
		    }
            d++;
	    }
        return matrix;
    }
};
```