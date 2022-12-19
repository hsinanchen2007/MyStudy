
错误信息：
    AddressSanitizer: stack-overflow on address 0x7ffe5e5ddff8 (pc 0x00000038ed28 bp 0x7ffe5e5de010 sp 0x7ffe5e5de000 T0)

```
class Solution {
public:
    //int inf = pow(2,31) - 1;
    void dfs(vector<vector<int>>& rooms,int i,int j,int rows,int cols,int ans){
        if(i >= 0 && i < rows && j >=0 && j <cols){
            if(rooms[i][j] == -1 || rooms[i][j] == 0){
                 return;
            }
            if(rooms[i][j] > ans){
                rooms[i][j] = ans;
            }
            dfs(rooms,i-1,j,rows,cols,ans+1);
            dfs(rooms,i+1,j,rows,cols,ans+1);
            dfs(rooms,i,j-1,rows,cols,ans+1);
            dfs(rooms,i,j+1,rows,cols,ans+1);
        }
    }
    void wallsAndGates(vector<vector<int>>& rooms) {
        int rows = rooms.size();
        if(rows < 1) return;
        int cols = rooms[0].size();
        if(cols < 1) return;
        for(int i = 0;i < rows;i++){
            for(int j = 0;j < cols;j++){
                if(rooms[i][j] == 0){
                    dfs(rooms,i-1,j,rows,cols,1);
                    dfs(rooms,i+1,j,rows,cols,1);
                    dfs(rooms,i,j-1,rows,cols,1);
                    dfs(rooms,i,j+1,rows,cols,1);
                }
            }
        }
        return;
    }
};
```
