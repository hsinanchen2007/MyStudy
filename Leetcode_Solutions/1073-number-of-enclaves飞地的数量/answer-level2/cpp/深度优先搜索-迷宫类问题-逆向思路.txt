### 解题思路
此处撰写解题思路
典型的迷宫问题，把思路稍微调过来一下，从边缘的点值为1的点出发，把所有能到达的点标记为2.之后再循环一遍，剩下的为1的总数就是答案。
### 代码

```cpp
class Solution {
public:
    int mv[4][4]={{1,0},{-1,0},{0,1},{0,-1}};
    int numEnclaves(vector<vector<int>>& A) {
        int count=0;
        for(int i=0;i<A.size();i++)//标记掉所有能跑出去的点
            for(int j=0;j<A[i].size();j++){
                if(i==0||i==A.size()-1||j==0||j==A[i].size()-1){
                    if(A[i][j]==1){
                        A[i][j]=2;
                        search(A,i,j);
                    }
                }
            }
        for(int i=0;i<A.size();i++)
            for(int j=0;j<A[i].size();j++){
                if(A[i][j]==1) count++;//还是1，没跑出去
            }
        return count;
    }
    void search(vector<vector<int>>& A,int x,int y){
        for(int i=0;i<4;i++){
            int xx=x+mv[i][0];
            int yy=y+mv[i][1];
            if(xx>=0&&xx<A.size()&&yy>=0&&yy<A[xx].size()&&A[xx][yy]==1){
                A[xx][yy]=2;
                search(A,xx,yy);
            }
        }
    }
};
```