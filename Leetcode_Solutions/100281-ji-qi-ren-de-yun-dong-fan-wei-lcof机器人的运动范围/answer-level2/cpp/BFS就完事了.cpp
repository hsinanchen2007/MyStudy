### 解题思路
BFS就完事了

### 代码

```cpp
class Solution {
public:
    struct node{
        int x;
        int y;
    };
    
    int x_step[4]={0,0,1,-1};
    int y_step[4]={1,-1,0,0};
    
    bool bool_maze[100][100]={false};
    
    bool judge(int x,int y,int k,int m,int n){
        if(x<0||x>=m||y<0||y>=n||bool_maze[x][y]==true)
            return false;
        int k_=sum_fun(x)+sum_fun(y);
        if(k_>k)
            return false;
        
        return true;
    }
    

    int sum_fun(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    
    
    int  BFS(int ini_x,int ini_y,int k,int m,int n){
        int res=1;
        bool_maze[ini_x][ini_y]=true;
        node nn;
        nn.x=ini_x;
        nn.y=ini_y;
        queue<node> Q;
        Q.push(nn);
        while(!Q.empty()){
            node temp=Q.front();
            Q.pop();
            for(int i=0;i<4;i++){
                int new_x=temp.x+x_step[i];
                int new_y=temp.y+y_step[i];
                if(judge(new_x,new_y,k,m,n)){
                    node new_node;
                    new_node.x=new_x;
                    new_node.y=new_y;
                    Q.push(new_node);
                    bool_maze[new_x][new_y]=true;
                    res++;
                }
            }
        }
        return res;
        
    }
    int movingCount(int m, int n, int k) {
        return BFS(0,0,k,m,n);
        
    }
};
```