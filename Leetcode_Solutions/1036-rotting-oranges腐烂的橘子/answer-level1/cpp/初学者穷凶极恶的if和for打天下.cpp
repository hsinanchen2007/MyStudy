### 解题思路
此处撰写解题思路
核心是用位图思想，因为len最大为10,所以采用11进制分割i,j一定不会越界，由于涉及到-11会越界的操作，于是留了前11位仅供越界使用。
算法就是常规的模拟过程，先调查出会被感染的，再感染，本次没有感染的就退出循环。
### 代码

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> temp(150,0);
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        int p;
        while(1){
            p=0;
            int flag=0;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==2){
                        temp[11*i+j+11+11]=1;
                        temp[11*i+j-11+11]=1;
                        temp[11*i+j+1+11]=1;
                        temp[11*i+j-1+11]=1;
                    }
                }
            }
            //cout << temp[9] << "  ";
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==1&&temp[11*i+j+11]==1){
                        //cout<<i<<j<<endl;
                        flag=1;
                        grid[i][j]=2;
                    }
                    else if(grid[i][j]==1&&temp[11*i+j+11]!=1){
                       // cout<<i<<"  " << j<<endl;
                        p=1;
                    }
                }
            }
            if(flag==1) count++;
            else break;
        }
        if(p==1) return -1;
        return count;
    }
};
```