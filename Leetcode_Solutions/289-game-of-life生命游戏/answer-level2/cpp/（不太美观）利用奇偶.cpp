### 解题思路
思路很简单，遇到单数四周加二，之后通过该位置的数字决定该位置细胞的死活

比较偷巧，但中间有一段要写八种情况，心态炸了，写的代码比较难看（改成循环大大减少代码量😭）

### 代码

```cpp
class Solution {
public:
    void add2(vector<vector<int>>& grip,int i,int j){
        if(i<0||i>=grip.size()||j<0||j>=grip[0].size())return;
        grip[i][j]+=2;
    }
    void gameOfLife(vector<vector<int>>& grid) {
        int len=grid.size();
        if(!len)return;
        int col=grid[0].size();
        for(int i=0;i<len;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]%2==1){
                    for(int i1=i-1;i1<=i+1;i1++){
                        for(int j1=j-1;j1<=j+1;j1++){
                            if(i==i1&&j==j1)continue;
                            add2(grid,i1,j1);
                        }
                    }
                }
                
            }
        }
        int tmp;
        for(int i=0;i<len;i++){
            for(int j=0;j<col;j++){
                switch (grid[i][j]){
                    case 5:grid[i][j]=1;
                    case 6:grid[i][j]=1;
                    case 7:grid[i][j]=1;break;
                    default:grid[i][j]=0;
                }                
            }
        }
        
    }
};
```