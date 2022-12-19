### 解题思路
环形连续问题，　最大＋最小　＝ sum　；　　全负数例外


### 代码

```c
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

#if 0
//这种扩容，滑动求各最大值　　超时了
int maxSubarraySumCircular(int* A, int ASize){
    int *arr = malloc(2*ASize*sizeof(int));
    int i,j,sum=0,max=0;

    for(i=0;i<ASize;i++)
        arr[i] = arr[i+ASize] = A[i];
    max = arr[0];
    for(i=0;i<=ASize;i++){
        sum = 0;
        for(j=i;j<ASize+i;j++){
            if(sum <=0){
                sum = arr[j];
            }else{
                sum += arr[j];
            }
            max = MAX(max,sum);
        }
    }
    return max;
}
#endif

int maxSubarraySumCircular(int* A, int ASize){
    int *arr = malloc(2*ASize*sizeof(int));
    int i,j,sum=0,max=0,min=0,temp=0;

    max = min = A[0];
    for(i=0;i<ASize;i++){
        sum += A[i];
        if(temp<=0){
            temp = A[i];
        }else{
            temp += A[i];
        }
        max = MAX(temp,max);
    }

    temp = 0;
    for(i=0;i<ASize;i++){
        if(temp>=0){
            temp = A[i];
        }else{
            temp += A[i];
        }
        min = MIN(min,temp);
    }
    //全负数时，　sum==min
    if(sum == min)
        return max;
    else
        return MAX(max,sum-min);
}
```