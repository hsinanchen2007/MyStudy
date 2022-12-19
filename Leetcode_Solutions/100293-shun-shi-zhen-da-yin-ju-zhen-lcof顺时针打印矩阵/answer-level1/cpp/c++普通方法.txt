### 解题思路
普通方法
95.61%  100%
### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>  print;
        if(matrix.empty())return print;
        int x=0,y=0,last=0;//last=0表示上一个状态是往上，1时为往右，2往下，3往左
        while(1)
        {
            if(last==0)
            {
                print.push_back(matrix[x][y]);
                matrix[x][y]=-100;
                if(x-1<0||matrix[x-1][y]==-100)//边界情况
                {
                    if(y+1<matrix[0].size()&&matrix[x][y+1]!=-100)//尽头
                    {
                        last=1;
                        y+=1;
                        continue;
                    }
                    else if(x+1<matrix.size()&&matrix[x+1][y]!=-100)
                    {
                        last=2;
                        x+=1;
                        continue;
                    }
                    else break;
                        
                }
                else x-=1;
            }
            if(last==1)
            {
                print.push_back(matrix[x][y]);
                matrix[x][y]=-100;
                if(y+1>=matrix[0].size()||matrix[x][y+1]==-100)//边界情况
                {
                    if(x+1<matrix.size()&&matrix[x+1][y]!=-100)//尽头
                    {
                        last=2;
                        x+=1;
                        continue;
                    }
                    else if(y-1>0&&matrix[x][y-1]!=-100)
                    {
                        last=3;
                        y-=1;
                        continue;
                    }
                    else break;
                    
                }
                else y+=1;
            }
            if(last==2)
            {
                print.push_back(matrix[x][y]);
                matrix[x][y]=-100;
                if(x+1>=matrix.size()||matrix[x+1][y]==-100)//边界情况
                {
                    if(y-1>=0&&matrix[x][y-1]!=-100)//尽头
                    {
                        last=3;
                        y-=1;
                        continue;
                    }
                    else if(x-1>=0&&matrix[x-1][y]!=-100)
                    {
                        last=0;
                        x-=1;
                        continue;
                    }
                    else    break;
                    
                }
                else x+=1;
            }
            if(last==3)
            {
                print.push_back(matrix[x][y]);
                matrix[x][y]=-100;
                if(y-1<0||matrix[x][y-1]==-100)//边界情况
                {
                    if(x-1>=0&&matrix[x-1][y]!=-100)//尽头
                    {
                        last=0;
                        x-=1;
                        continue;
                    }
                    else if(y+1<matrix[0].size()&&matrix[x][y+1]!=-100)
                    {
                        last=1;
                        y+=1;
                        continue;
                    }
                    else    break;
                    
                }
                else y-=1;
            }
        }
        return print;
    }
};
```