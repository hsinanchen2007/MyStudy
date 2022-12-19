n皇后问题其实就是把n个皇后放到n行，每次放之前要看看同一行同一列以及两条对角线上有没有别的皇后，
**怎么判断在同一行同一列以及对角线上有没有别的皇后**
我是把一个皇后和一行绑定，按一次循环是找去下一行，也就是说每行的皇后肯定是不冲突的，不可能说有两个皇后在一行的，所以只用判断在列和对角线上是不是有别的皇后即可，我是维护了三个数组分别是列标记数组（n列一维数组)如果有皇后已经在该列，将col[j]改为1
主对角线数组 在主对角线上行号-列号是一个常数，
次对角线数组 在次对角线上行号+列号是一个常数
拿n=4来说
主对角线
行号-列号
列号0  1  2   3
行号
0     0  1  2   3
1    -1  0  2   3
2   -2 -1  0    1
3    -3 -2 -1  0
可以标记某一条对角线的常数有-3 -2 -1 0 1 2 3 因为有负数我采用的办法是将负数映射到正数后面 即-3-> 4 -3+(2*n-1)
次对角线
行号+列号
列号0  1  2   3
行号
0     0  1  2   3
1   1   2  3   4
2   2   3  4    5
3   3  4   5    6
次对角线标记就是 0，1，2，3，4，5，6
如果有的话就不能放到这个位置
每次递归就是帮助一个皇后寻找位置
比如第一次进到search代表的是帮助第一行的皇后找位置，因为一行有n列所以她有n个位置可以选，她从第一个位置开始看起如果第一个位置可以放，她就把自己放到这里，然后通知下一个皇后寻找自己的位置，也就是调用了一次search
代码，将index（行号）+1。如果这个皇后看自己所有的位置都不可以放自己了，就通知自己的上一层皇后，"你的位置放的不对，我都没地方放了",这时上一层这个皇后就去找下一个可以放自己的位置，当然在此之前要把自己刚刚占的位置释放掉
解释完了，下面代码就是按这个思路写的应该挺容易理解了吧（哈哈)
```
void search(char ***answer,int *returnSize,int n,char**plate,int *col,int *firstdiagonal,int *seconddiagonal,int index)
 {//answer是三维答案数组，returnSize 是有几个答案，n是n皇后，plate是棋盘
 //index是第几行，从0开始，firstdiagonal是主对角线标记数组，second diagonal是次对角线标记数组，col是列表数组
     int i=0,post=0,j=0;
      if(index==n)
      {
          answer[*returnSize]=(char**)malloc(sizeof(char*)*n);//为每一个二维答案数组申请空间
          for(i=0;i<n;i++)
              answer[*returnSize][i]=(char*)malloc(sizeof(char)*(n+1));
          for(i=0;i<n;i++)
          {
              for(j=0;j<n;j++)
                 answer[*returnSize][i][j]=plate[i][j];
              answer[*returnSize][i][j]='\0';
          }
          *returnSize+=1;
          return ;
      }
      for(i=0;i<n;i++)//寻找第一个列位置
      {
          if(index-i<0)
              post=index-i+(2*n-1);
          else
               post=index-i;
           if(firstdiagonal[post]==0 && seconddiagonal[index+i]==0 &&col[i]==0)//该位置可以放
           {
               plate[index][i]='Q';
               firstdiagonal[post]=1;
               seconddiagonal[index+i]=1;
               col[i]=1;
               search(answer,returnSize,n,plate,col,firstdiagonal,seconddiagonal,index+1);
               plate[index][i]='.';
               firstdiagonal[post]=0;
               seconddiagonal[index+i]=0;
               col[i]=0;
           }
                  
      }

 }
char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    char ***answer=NULL;
    answer=(char***)malloc(sizeof(char**)*1000);//答案数组
    int i=0,j=0,k=0;
    *returnSize=0;//结果个数
     (*returnColumnSizes) = malloc(1000 * sizeof(int));//三维结果数组中 每一个二维结果数组的列数数组
    char **plate=(char**)malloc(sizeof(char*)*n);//棋盘
    int *col=(int*)malloc(sizeof(int)*n);//当前列是否存在皇后
    int *firstdiagonal=(int*)malloc(sizeof(int)*2*n);//当前位置主对角线是否存在皇后
    int *seconddiagonal=(int*)malloc(sizeof(int)*2*n);//当前位置次对角线是否存在皇后
    for(i=0;i<n;i++)//赋初始值 表示不存在皇后
        col[i]=0;
    for(i=0;i<2*n;i++)//赋初始值 表示不存在皇后
        firstdiagonal[i]=0;
    for(i=0;i<2*n;i++)//赋初始值 表示不存在皇后
        seconddiagonal[i]=0;
    for(i=0;i<n;i++)//给棋盘数组的每一列分配空间
        plate[i]=(char*)malloc(sizeof(char)*n);
    for(i=0;i<n;i++)//生成初始棋盘
    {
        for(j=0;j<n;j++)
            plate[i][j]='.';
    }
    search(answer,returnSize,n,plate,col,firstdiagonal,seconddiagonal,0);
    *returnColumnSizes=(int*)malloc(sizeof(int)*(*returnSize));
    for (i = 0; i < *returnSize; i++) 
        (*returnColumnSizes)[i] = n;
   return answer;
}
```
