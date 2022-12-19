### 解题思路
    实测冒泡排序超出时间限制
    改用快排

### 代码

```c
void Swap(int *p, int *q);
void QuickSort(int *a, int low, int high);
int arrayPairSum(int* nums, int numsSize){
    // for(int i=0;i<numsSize;i++)
    // {
    //     for(int j=0;j<numsSize-1-i;j++)
    //     {
    //         if(nums[j]>nums[j+1])
    //         {
    //             int temp=nums[j];
    //             nums[j]=nums[j+1];
    //             nums[j+1]=temp;
    //         }
    //     }
    // }
    QuickSort(nums,0,numsSize-1);
    int sum=0;
    for(int i=0;i<numsSize;i=i+2)
    {
        sum+=nums[i];
    }
    return sum;
}

void Swap(int *p, int *q)
{
    int buf;
    buf = *p;
    *p = *q;
    *q = buf;
    return;
}

void QuickSort(int *a, int low, int high)
{
    int i = low;
    int j = high;
    int key = a[low];
    if (low >= high) //如果low >= high说明排序结束了
    {
        return ;
    }
    
    while (low < high) //该while循环结束一次表示比较了一轮
    {
        while (low < high && key <= a[high])
        {
            --high; //向前寻找
        }
        if (key > a[high])
        {
            Swap(&a[low], &a[high]);
            ++low;
        }
        while (low < high && key >= a[low])
        {
            ++low; //向后寻找
        }
        if (key < a[low])
        {
            Swap(&a[low], &a[high]);
            --high;
        }
    }
    QuickSort(a, i, low-1); //用同样的方式对分出来的左边的部分进行同上的做法
    QuickSort(a, low+1, j); //用同样的方式对分出来的右边的部分进行同上的做法
}

```