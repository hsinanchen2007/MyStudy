### 解题思路
这题参照大佬，并且做了完善的解释

### 代码

```c
#include<malloc.h>

void gameOfLife(int **board, int boardSize, int* boardColSize)
{
	//这里的参数int **board是二重指针
	//boardSize是行数
	//int* boardColSize是列数的指针，不知道怎么要这样写，可能吃多了没事干
	int numOne;//每个数子周围1的个数
    int m = boardSize + 2;
    int n = *boardColSize + 2;
    //把原来的数组扩展来解决边界问题
	
    /**
	//本来用C语言原则上是不能够这样声明变量de的
	//但是看到很多程序都是这样，而且我自己试过了是可以通过的
	//经过百度，发现这是C89和C99标准的区别
	//所以两种方式均可以
	int ret[m][n];
    //创建一个数组来储存改变后的值
	*/
	
	//用动态分配内存的方法来申请一个二维数组
	int **ret = (int **)malloc(m * sizeof(int *));//分配m行
     // 为每行分配n列
    for(int i = 0; i < m; i++)
    {
        ret[i] = (int *)malloc(n * sizeof(int));
    }
	
	//下面把原来的内容copy过去
    for(int i = 1; i < (m - 1); i++)
    {
        for(int j = 1;j < (n - 1); j++)
        {
            ret[i][j] = board[i - 1][j - 1];
        }
    }
	//把多余的位置填上2，或者填上3，4，5......
	//不过不要填0，1，会有影响的
    for(int i = 0; i < n; i++)
        ret[0][i] = 2;
    for(int i = 0; i < n; i++)
        ret[m - 1][i] = 2;
    for(int i = 0; i < m; i++)
        ret[i][0] = 2;
    for(int i = 0; i < m; i++)
        ret[i][n - 1] = 2;
    for(int i = 1; i < (m - 1); i++)
    {
        for(int j = 1;j < (n - 1); j++)
        {
			//找出附近的八个有多少个1
            numOne = (ret[i - 1][j - 1] == 1) + (ret[i - 1][j] == 1) + 
                     (ret[i - 1][j + 1] == 1) + (ret[i][j - 1] == 1) +
                     (ret[i][j + 1] == 1) + (ret[i + 1][j - 1] == 1) +
                     (ret[i + 1][j] == 1) + (ret[i + 1][j + 1] == 1);
			 //按照题目给定的条件来判断，改变原来数组的值
            if(numOne < 2 && ret[i][j] == 1)
                board[i - 1][j - 1] = 0;
                else if((numOne == 2 || numOne == 3) && ret[i][j] == 1)
                    board[i - 1][j - 1] = 1;
                else if(numOne > 3 && ret[i][j] == 1  && ret[i][j] == 1)
                    board[i - 1][j - 1] = 0;
                else if(numOne == 3 && ret[i][j] == 0)
                    board[i - 1][j - 1] = 1;
        }
    }
    
	// 先释放每行申请的每列的每个内存
	for(int i = 0; i < m; i++)
    free(ret[i]);
	// 再释放申请的每行的内容
	free(ret);
}
```