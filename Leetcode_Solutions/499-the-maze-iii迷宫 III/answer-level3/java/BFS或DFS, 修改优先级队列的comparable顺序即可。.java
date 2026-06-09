### 解题思路
思路：
1.最重要的是：BFS中visit[][]数组 和 queue队列 每个node所存的 到当前点路径代价 的关系，即visit代表到此点的最短步数
2.要注意不能找到目的地就退出，因为多路径要排序选择，同时出队列的优先级是 直线的数目， 而不是步数。
3.字典序排序使用treeset或者treemap实现。
4.使用优先级队列，count最大优先出队列，其实就变成了DFS， 而最小优先出则还是BFS，所以没有必要使用 PriorityQueue.
### 代码

```java
class Solution {
    public   String findShortestWay(int[][] maze, int[] ball, int[] hole) {
        TreeMap<String,Integer> answers = new TreeMap<>() ;
        Queue<node> queue = new LinkedList<>();
        queue.add(new node(ball[0],ball[1]));
        int dirs[][] = {{0,1},{0,-1},{1,0},{-1,0}};
        int visited[][] = new int[maze.length][maze[0].length];

        for (int[] row: visited)
            Arrays.fill(row, Integer.MAX_VALUE);

        visited[ball[0]][ball[1]] = 0;

        while (queue.size()!=0){     //易错点，.size获取数目，而不能直接判断是否为null
            node  now = queue.poll();


            for (int [] dir : dirs){
                int x = now.x;
                int y = now.y;
                int count = 0;
                int x_next = x + dir[0];
                int y_next = y + dir[1];

                while (x_next>=0 && y_next>=0 && x_next < maze.length && y_next < maze[0].length  && maze[x_next ][y_next] != 1){



                    x_next = x_next + dir[0];
                    y_next = y_next + dir[1];

                     count++;

                    if(x_next - dir[0] == hole[0] && y_next - dir[1] == hole[1])    break; //终点-break 入洞。

                }
                x  = x_next - dir[0];
                y  = y_next - dir[1];
                if(count==0) continue;
                node newone = new node(x,y);
                newone.count = now.count + count;
                if(dir[0]==1 && dir[1]==0)   newone.output = now.output + "d";
                if(dir[0]==-1 && dir[1]==0)  newone.output = now.output + "u";
                if(dir[0]==0 && dir[1]==1)   newone.output = now.output + "r";
                if(dir[0]==0 && dir[1]==-1)  newone.output = now.output + "l";


                if(newone.count < visited[x][y]){

                    visited[x][y] = newone.count;

                    if(x==6 && y==5)
                        System.out.println("test");


                    if(x == hole[0] && y == hole[1]) {
                        answers.clear();
                        answers.put(newone.output, visited[x][y]);
                        break;    //跳出四个方向的循环
                        }
                    else {
                        queue.add(newone);

                    }

                }
                else if(newone.count == visited[x][y]){

                    if( x == hole[0] && y == hole[1])          {
                        answers.put(newone.output, visited[x][y]);
                        break;    //跳出四个方向的循环

                    }
                    else           queue.add(newone);

                }

            }

        }

        return (!answers.isEmpty()) ? answers.firstKey() : "impossible";

    }
}
class node{
    int x;
    int y;
    int count = 0;

    String output = "";
    public  node (int x,int y){
        this.x = x;
        this.y = y;
    }
}

```