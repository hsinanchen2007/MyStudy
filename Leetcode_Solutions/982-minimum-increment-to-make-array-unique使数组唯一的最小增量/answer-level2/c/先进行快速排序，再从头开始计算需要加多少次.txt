### 解题思路
此处撰写解题思路

### 代码

```c
//先进行快排，再从最小的开始逐个加1 
int partition(int *arr, int left, int right)
{
    int tmp = arr[left];
    while(left < right)
    {
        while(left < right && tmp <= arr[right])
        {
            right--;
        }
        if(left < right)
        {
            arr[left] = arr[right];
            left++;
        }
        while(left < right && tmp > arr[left])
        {
            left++;
        }
        if(left < right)
        {
            arr[right] = arr[left];
            right--;
        }
    }
    arr[left] = tmp;
    return left;
}

void print(int *arr, int num)
{
    int i;
    for(i = 0; i < num; i++)
    {
        printf("A[%d] = %d  ", i, arr[i]);
    }
    printf("\n");
}

void quickSort(int *arr, int left, int right)
{
    int tmp;
    if(left < right)
    {
        tmp = partition(arr, left, right);
        quickSort(arr, left, tmp - 1);
        quickSort(arr, tmp + 1, right);
    }
}


int minIncrementForUnique(int* A, int ASize)
{
    if(ASize == 0)
    {
        return 0;
    }
    quickSort(A, 0, ASize - 1);
    //print(A, ASize);

    int i, tmp = 0, flag = 0, j;
    tmp = A[0];
    for(i = 0, j = 0; i < ASize; i++, j++)
    {
        if(A[i] > tmp +j)   //判断是不是中间有跳跃的情况
        {
            tmp = A[i];
            j = 0;
        }
        if(A[i] < tmp+j)
        {
            flag = flag + (tmp+j-A[i]);
            //printf("flag = %d, tmp = %d, j = %d, A[%d] = %d\n", flag, tmp, j, i, A[i]);
        }
    }
    return flag;
}
```