### 解题思路
写两个辅助函数，一个用来求数字二进制数1的个数，另外一个定义排序规则
再利用qsort()函数
### 代码

```c


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct num{
    int count;          //arr[i]二进制1的个数
    int data;           //arr[i]
}num;

int cmp(const void *x,const void *y){
    if(((num*)x)->count==((num*)y)->count)  //1的个数相同，按数值排序
        return ((num*)x)->data-((num*)y)->data;
    return ((num*)x)->count-((num*)y)->count;
}

int getnum(int n){      //求数的二进制中1的个数
    int count=0;
    for(int i=0;i<32;i++){
        if(n&1==1)
            count++;
        n=n>>1;
    }
    return count;
}

int* sortByBits(int* arr, int arrSize, int* returnSize){
    int i;
    num *val=(num*)malloc(sizeof(num)*arrSize);
    for(i=0;i<arrSize;i++){
        val[i].data=arr[i];
        val[i].count=getnum(arr[i]);
    }
    qsort(val,arrSize,sizeof(num),cmp);
    for(i=0;i<arrSize;i++){
        arr[i]=val[i].data;
    }
    *returnSize=arrSize;
    return arr;
}


```