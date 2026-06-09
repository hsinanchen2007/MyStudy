### 解题思路
代码重复率太高了，一旦重复修改的代价也变高
挂上耻辱墙 激励自己

### 代码

```cpp
class Solution {
public:
int dao[7][4] = {{},{0,0,1,1},{1,1,0,0},{0,1,1,0},{0,1,0,1},{1,0,1,0},{1,0,0,1}};
        int trans[4] = {1,0,3,2};
    bool hasValidPath(vector<vector<int>>& grid) {
        if(grid.size()==1&&grid[0].size()==1)
            return true;
        bool q=false,w=false,e=false,r=false;
        int n = grid.size(),m = grid[0].size();
        int i=0,j=0,fx = 0;
        
        if(dao[grid[i][j]][0]){
                int a = i,b = j;
                for(int k=0;k<4;k++){
                if(dao[grid[i][j]][k]&&k!=0)
                { fx = trans[k];
                 if(k==0)
                     a--;
                 else if(k==1)
                     a++;
                 else if(k==2)
                     b--;
                 else
                     b++;
                 break;
                }
            }
             if(a<0||a>=n||b<0||b>=m)
                    q = false;
                else
              q =  h(a,b,fx,grid);
            }
              if(dao[grid[i][j]][1]){
                int a = i,b = j;
                for(int k=0;k<4;k++){
                if(dao[grid[i][j]][k]&&k!=1)
                { fx = trans[k];
                 if(k==0)
                     a--;
                 else if(k==1)
                     a++;
                 else if(k==2)
                     b--;
                 else
                     b++;
                 break;
                }
            }
             if(a<0||a>=n||b<0||b>=m)
                    w = false;
                else
              w =  h(a,b,fx,grid);
            }
           if(dao[grid[i][j]][2]){
                int a = i,b = j;
                for(int k=0;k<4;k++){
                if(dao[grid[i][j]][k]&&k!=2)
                { fx = trans[k];
                 if(k==0)
                     a--;
                 else if(k==1)
                     a++;
                 else if(k==2)
                     b--;
                 else
                     b++;
                 break;
                }
            }
             if(a<0||a>=n||b<0||b>=m)
                    e = false;
                else
              e=  h(a,b,fx,grid);
            }
            if(dao[grid[i][j]][3]){
                int a = i,b = j;
                for(int k=0;k<4;k++){
                if(dao[grid[i][j]][k]&&k!=3)
                { fx = trans[k];
                 if(k==0)
                     a--;
                 else if(k==1)
                     a++;
                 else if(k==2)
                     b--;
                 else
                     b++;
                 break;
                }
            }
             if(a<0||a>=n||b<0||b>=m)
                    r = false;
                else
              r =  h(a,b,fx,grid);
            }
           
          return q||w||e||r;

    }
    bool h(int i,int j ,int fx ,vector<vector<int>>& grid){
       // cout<<"a";
        int n = grid.size(),m = grid[0].size();
     int vi = 1;
        while(vi){
            if(i==n-1&&j==m-1)
                vi = 0;
             if(i<0||i>=n||j<0||j>=m)
                    return false;
            if(dao[grid[i][j]][0]&& fx==0){
                
                for(int k=0;k<4;k++){
                if(dao[grid[i][j]][k]&&k!=0)
                { fx = trans[k];
                 if(k==0)
                     i--;
                 else if(k==1)
                     i++;
                 else if(k==2)
                     j--;
                 else
                     j++;
                 break;
                }
            }
            }
            else if(dao[grid[i][j]][2]&&fx==2){
               
              for(int k=0;k<4;k++){
                if(dao[grid[i][j]][k]&&k!=2)
                { fx = trans[k];
                if(k==0)
                     i--;
                 else if(k==1)
                     i++;
                 else if(k==2)
                     j--;
                 else
                     j++;
                 break;
                }
            }
            }
            else if(dao[grid[i][j]][1]&&fx==1){
               
              for(int k=0;k<4;k++){
                if(dao[grid[i][j]][k]&&k!=fx)
                { fx = trans[k];
                 if(k==0)
                     i--;
                 else if(k==1)
                     i++;
                 else if(k==2)
                     j--;
                 else
                     j++;
                 break;
                }
            }
            }
            else if(dao[grid[i][j]][3]&&fx==3){
                
               for(int k=0;k<4;k++){
                if(dao[grid[i][j]][k]&&k!=fx)
                { fx = trans[k];
                 if(k==0)
                     i--;
                 else if(k==1)
                     i++;
                 else if(k==2)
                     j--;
                 else
                     j++;
                 break;
                }
            }
            }
            
            else
                return false;
          //  cout<<i<<","<<j;
            
        }
        return true;
    }
};
```