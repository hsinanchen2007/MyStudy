### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxDistance(int[][] grid) {
  int M = grid.length;
    int N = grid[0].length;
    int[][]dr = {{1,0},{0,1},{0,-1},{-1,0}};
    int [][]flag = new int[M][N];
    Queue<Integer> Queue = new LinkedList<>();
for(int i =0;i<M;i++){
for(int j=0;j<N;j++)
{
if(grid[i][j] == 1) Queue.add(new Integer(i *N + j));
}
}

 int count = 0;
 if( Queue.size() == 0 ||  Queue.size() == N*M)
 {
return -1;
 }
    while( !Queue.isEmpty())
    {
         int size = Queue.size();

         for(int i=0;i< size;i++)
         {
int cur = Queue.poll();
int curx = cur/N;
int cury = cur%N;
for(int j=0;j<4;j++)
{
    int x = curx +dr[j][0];
    int y = cury +dr[j][1];

  if(x>=0 && y>=0 && x<M && y< N && flag[x][y] == 0 && grid[x][y]==0)
{
flag[x][y] =1;
Queue.offer(new Integer(x *N + y));
}  
}
 

         }
     
    count++;
        }
        return count-1;
    }

}
```