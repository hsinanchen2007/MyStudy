### 解题思路
此处撰写解题思路
1.统计每一个数字的个数
2.如当前的个数大于1，则将大于1的个数加到下一个数字中，move_cnt增加相应的次数；
3.依次执行步骤2，知道将剩余的个数累加到了最大值处，由于数值范围的限制，后边的数值个数都是0，move_cnt增加相应的次数；
### 代码

```c
#define A_MAX 40000
int minIncrementForUnique(int* A, int ASize){
    int i = 0 ;
    int move_cnt =0;
    int A_array[A_MAX]={0};
    int move_num = 0;
    for(i=0;i<ASize;i++)
    {
        A_array[A[i]]++;
    }
    for(i=0;i<A_MAX-1;i++)
    {
        if(A_array[i]>=2)
        {
            move_num = A_array[i]-1;
            move_cnt+= move_num;
            A_array[i+1]+=move_num;
            A_array[i]=1;
        }
    }
    if(A_array[i]>=2)
    {
         move_num = A_array[i]-1;
         for(i=1;i<=move_num;i++)
         {
             move_cnt+= i;
         }
    }
    return move_cnt;
}



```