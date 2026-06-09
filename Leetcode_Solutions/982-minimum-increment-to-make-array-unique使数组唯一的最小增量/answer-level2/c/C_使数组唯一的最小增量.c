### 解题思路
5增到9需要增9-5=4个增量
2增到7需要增7-2=5个增量
n增到m需要增m-n个增量

排序之后，从第二个元素到末尾遍历。如果一个元素小于等于前面的元素，改成为前面元素+1。

1 1 1 1 1 1 1 1 5 5  13  13  14//1<=1 第二个数改成2
1 2 1 1 1 1 1 1 5 5  13  13  14
1 2 3 1 1 1 1 1 5 5  13  13  14
1 2 3 4 1 1 1 1 5 5  13  13  14
1 2 3 4 5 1 1 1 5 5  13  13  14
1 2 3 4 5 6 1 1 5 5  13  13  14
1 2 3 4 5 6 7 1 5 5  13  13  14
1 2 3 4 5 6 7 8 5 5  13  13  14
1 2 3 4 5 6 7 8 9 5  13  13  14
1 2 3 4 5 6 7 8 9 10 13  13  14
1 2 3 4 5 6 7 8 9 10 13  13  14 //13大于10，不改动
1 2 3 4 5 6 7 8 9 10 13  14  14
1 2 3 4 5 6 7 8 9 10 13  14  15


### 代码

```c
void sortQ(int* Num,int Low,int High)
{
    if(Low<High)
    {
        int i=Low,j=High,temp=Num[i];
        while(i!=j)
        {
            while(i<j&&Num[j]>temp)--j;
            if(i<j)Num[i++]=Num[j];
            while(i<j&&Num[i]<temp)++i;
            if(i<j)Num[j--]=Num[i];
        }
        Num[i]=temp;
        sortQ(Num,Low,i-1);
        sortQ(Num,i+1,High);
    }
}

int minIncrementForUnique(int* A, int ASize){
    //排序
    sortQ(A,0,ASize-1);
    int result=0;
    //如果当前元素A[i] 小于等于 上个元素A[i-1]，则更新当前元素为 A[i-1]+1 移动步数为 A[i-1]+1-A[i]
    for(int i=1;i<ASize;++i)
        if(A[i]<=A[i-1])
        {
            int pre=A[i];
            A[i]=A[i-1]+1;
            result+=A[i]-pre;
        }
        
    return result;
}
```