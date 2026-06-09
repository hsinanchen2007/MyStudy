### 解题思路

 
### 代码

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        if(m==0) return 0;
        int n=grid[0].size(); 
        int min=0;
        int num_0=0,num_1=0,num_2=0;
        queue<pair<int,int>> my_queue;
        int queue_number=0;
        int queue_number_next=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){ ++num_0;}
                else if(grid[i][j]==1) ++num_1;
                else {
                    ++num_2;
                    my_queue.push(pair<int,int>(i,j));
                    ++queue_number;
                }
            }
        }
        if(num_1+num_2==0) return 0; //没有桔子
        if(num_1==0&&num_2>0) return 0;  //全是烂的
        if(num_1>0&&num_2==0) return -1;  //全是好的
        
        while(!my_queue.empty()){
            pair<int,int> p;
            p=my_queue.front();
            my_queue.pop();
            --queue_number;
//
            if(p.first-1>=0){
                if(grid[p.first-1][p.second]==1){
                    grid[p.first-1][p.second]=2;
                    my_queue.push(pair<int,int>(p.first-1,p.second));
                    ++num_2;--num_1;
                    ++queue_number_next;
                }
            }
            if(p.first+1<m){
                 if(grid[p.first+1][p.second]==1){
                    grid[p.first+1][p.second]=2;
                    my_queue.push(pair<int,int>(p.first+1,p.second));
                    ++num_2;--num_1;
                    ++queue_number_next;
                }
            }
            if(p.second-1>=0){
                if(grid[p.first][p.second-1]==1){
                    grid[p.first][p.second-1]=2;
                    my_queue.push(pair<int,int>(p.first,p.second-1));
                    ++num_2;--num_1;
                    ++queue_number_next;
                }          
            }
            if(p.second+1<n){
                if(grid[p.first][p.second+1]==1){
                    grid[p.first][p.second+1]=2;
                    my_queue.push(pair<int,int>(p.first,p.second+1));
                    ++num_2;--num_1;
                    ++queue_number_next;
                }   
            }
            if(queue_number==0){
                ++min;
                queue_number=queue_number_next;
                queue_number_next=0;
                if(num_1==0) return min;
            }

        }
         return -1;
 




        
    }

};
```