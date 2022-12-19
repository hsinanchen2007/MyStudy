采用广度优先算法框架：可以将每个[i][j]视为一个节点，上下左右陆地相连视为这些节点间有链接，所以整个就成了一个n*m个节点的无向图；而找有多少个岛屿实际上就变成找有多少个非连同子图，这样可以采用广度优先框架解题。1）申请一个与输入数组同维数的数组visit，初始化为0，作为该节点未被访问的标记，被访问就标记为1；2）申请一个队列Q元素为pair类型数据，first为横坐标，second为纵坐标；3）申请一个count变量，用于记录岛屿数量，初始化为1；4）对整个二维数组进行遍历（for语句的嵌套循环）：（1）如果Q为空，且[i][j]元素未被访问，且为‘1’，则将其push到Q中；（2）用while 循环下面的循环体：如果Q非空，取出队头元素给临时变量temp，然后pop出去，这时对temp元素所在位置的上下左右位置进行判断，如果位置不越界且为1且未被访问，则将其位置push进Q，同时visit相应位置标记为1(再次强调这里需注意不要越界)。最后返回count。

复杂度分析：时间复杂度为O(M*N),空间复杂度小于2M*N，实际上可以用原数组作为标记数组的，这样空间复杂度会z减小至少一半。
代码如下：
```
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0){//如果为空，返回0；
            return 0;
        }
        //cout<<"haha~"<<endl;
        int n=grid.size();
        int m=grid[0].size();
        int visit[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                visit[i][j]=0;
            }
        }
        //cout<<n<<m<<visit[0][0]<<visit[n-1][m-1]<<endl;
        
        queue<pair<int,int>>Q;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(Q.size()==0 && grid[i][j]=='1' && visit[i][j]==0){
                    Q.push({i,j});
                    visit[i][j]=1;
                    count++;
                    //cout<<"haha~"<<endl;
                }
                while(!Q.empty()){
                    pair<int,int>temp=Q.front();
                    Q.pop();
                    int k=temp.first;
                    int l=temp.second;
                    if(k!=0&&grid[k-1][l]=='1'&&visit[k-1][l]==0){
                        Q.push({k-1,l});
                        visit[k-1][l]=1;
                    }
                    if(k!=n-1&&grid[k+1][l]=='1'&&visit[k+1][l]==0){
                        Q.push({k+1,l});
                        visit[k+1][l]=1;
                    }
                    if(l!=0&&grid[k][l-1]=='1'&&visit[k][l-1]==0){
                        Q.push({k,l-1});
                        visit[k][l-1]=1;
                    }
                    if(l!=m-1&&grid[k][l+1]=='1'&&visit[k][l+1]==0){
                        Q.push({k,l+1});
                        visit[k][l+1]=1;
                    }
                }
            }
        }
        return count;
    }
};
```
运行结果：12ms,96.63%;11.1MB,53.21%.