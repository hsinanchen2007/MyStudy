将分子定义为 $up$，分母定义为 $down$，从这组数的最后一个开始，进行相同的计算，每一次计算由于分子分母都需要颠倒后再被上一个数字所加，所以设置中间变量 $temp$，在每一次计算后将分子分母置换，然后给需要输出的数组 $showResult$ 分配大小、空间，最后输出即可。
```
int* fraction(int* cont, int contSize, int* returnSize)
{
    int up=1,down=cont[contSize-1] ,temp=0 ;
    for(int i=contSize -1; i>=1 ;i--)
    {
        up += down*cont[i-1];
        temp =up ;
        up =down;
        down=temp;
    }
    *returnSize =2;
    int *showResult =(int*)malloc(sizeof(int)*2);
      showResult[0] =down;
      showResult[1]=up;
     return showResult;
}
```