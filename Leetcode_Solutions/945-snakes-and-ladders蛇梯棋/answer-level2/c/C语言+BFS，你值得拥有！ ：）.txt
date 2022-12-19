### 解题思路
![截屏2020-02-05下午9.19.52.png](https://pic.leetcode-cn.com/25b7a0e6e0058ed3254db6f17bcb78387d7d1be1e4e1ee60b054fd75851a5497-%E6%88%AA%E5%B1%8F2020-02-05%E4%B8%8B%E5%8D%889.19.52.png)

   这道题给了一个 NxN 大小的二维数组，从左下角从1开始，蛇形游走，到左上角或者右上角到数字为 NxN，中间某些位置会有梯子，就如同传送门一样，直接可以到达另外一个位置。现在就如同玩大富翁 Big Rich Man 一样，有一个骰子，可以走1到6内的任意一个数字，现在奢侈一把，有无限个遥控骰子，每次都可以走1到6以内指定的步数，问最小能用几步快速到达终点 NxN 位置。开始做这道题的时候，看是求极值，以为是一道动态规划 Dynamic Programming 的题，结果发现木有办法重现子问题，没法写出状态转移方程，只得作罢。但其实忽略了一点，**求最小值还有一大神器，广度优先搜索 BFS**，最直接的应用就是在迷宫遍历的问题中，求从起点到终点的最少步数，也可以用在更通用的场景，只要是存在确定的状态转移的方式，可能也可以使用。这道题基本就是类似迷宫遍历的问题，可以走的1到6步可以当作六个方向，这样就可以看作是一个迷宫了，唯一要特殊处理的就是遇见梯子的情况，要跳到另一个位置。这道题还有另一个难点，就是数字标号和数组的二维坐标的转换，这里起始点是在二维数组的左下角，且是1，而代码中定义的二维数组的 (0, 0) 点是在左上角，需要转换一下，还有就是这道题的数字是蛇形环绕的，即当行号是奇数的时候，是从右往左遍历的，转换的时候要注意一下。
   
   难点基本都提到了，现在开始写代码吧，既然是 BFS，就需要用队列 queue 来辅助，初始时将数字1放入，然后还需要一个 visited 数组，大小为 nxn+1。在 while 循环中进行层序遍历，取出队首数字，判断若等于 nxn 直接返回结果 minStep。否则就要遍历1到6内的所有数字i，则 num+i 就是下一步要走的距离，需要将其转为数组的二维坐标位置，这个操作放到一个单独的子函数中，后边再讲。有了数组的坐标，就可以看该位置上是否有梯子，有的话，需要换成梯子能到达的位置，没有的话还是用 num+i。有了下一个位置，再看 visited 中的值，若已经访问过了直接跳过，否则标记为 true，并且加入队列 queue 中即可，若 while 循环退出了，表示无法到达终点，返回 -1。将数字标号转为二维坐标位置的子函数也不算难，首先应将数字标号减1，因为这里是从1开始的，而代码中的二维坐标是从0开始的，然后除以n得到横坐标，对n取余得到纵坐标。但这里得到的横纵坐标都还不是正确的，因为前面说了数字标记是蛇形环绕的，当行号是奇数的时候，列数需要翻转一下，即用 n-1 减去当前列数。又因为代码中的二维数组起点位置在左上角，同样需要翻转一样，这样得到的才是正确的横纵坐标，返回即可，

### 代码

```c


/*
    将棋盘数字标号(1,2,3,...,N*N)转为二维坐标位置:
    (1)首先应将数字标号减1，因为棋盘是从1开始的，而代码中的二维坐标是从0开始的，
    (2)然后除以n得到横坐标，对n取余得到纵坐标。
    (3)但这里得到的横纵坐标都还不是正确的，因为前面说了数字标记是蛇形环绕的，
       当行号是奇数的时候，列数需要翻转一下，即用 n-1 减去当前列数
*/
int  getNextBoardValue(int **board,int boardSize,int num)
{
    if(board == NULL)
    {
        return -1;
    }

    int n = boardSize;

    int x = (num - 1)/n;
    int y = (num - 1)%n;

    if(x % 2 != 0)// if x is odd number
    {
        y = (n - 1) - y;//只有x位于奇行数(从下往上数),y走向是从右向左，所以y要翻转
    }

    x = (n - 1) - x;//x是从下往上走的，所以要一直翻转

    return board[x][y];
}

int snakesAndLadders(int** board, int boardSize, int* boardColSize){
    if(board == NULL || boardSize == 0 || boardColSize == NULL)
    {
        return -1;
    }

    int n = boardSize;
    int c = boardColSize[0];
    int minStep = 0;
    int q[n*n];//create a queue
    int visited[n*n+1];

    memset(q,0,sizeof(q));
    memset(visited,0,sizeof(visited));
    int cur = 0;
    int next = 0;

    int front = 0;
    int rear  = 0;

    /*begin with the left lower corner of the chessboard*/
    q[rear++] = 1;//enqueue
    //visited[n - 1][0] = true;//
    int layerNum = 0;

    while(rear != front)
    { 
        //printf("cur = %d\n",cur);


        layerNum = rear - front;

        for(int l = 0;l<layerNum;l++)
        {
            cur = q[front++];//dequeue 
            if(cur == n*n)
            {
                return minStep;
            }    
            for(int i = 1;i <= 6 && cur + i <= n*n ;i++)
            {
                next = getNextBoardValue(board,boardSize,cur+i);
                if(next == -1)
                {
                    next = cur + i;
                }

                if(visited[next])
                {
                    continue;
                }
                visited[next] = true;
                q[rear++] = next;
            }
        }
        minStep++;

    }
    return -1;
}