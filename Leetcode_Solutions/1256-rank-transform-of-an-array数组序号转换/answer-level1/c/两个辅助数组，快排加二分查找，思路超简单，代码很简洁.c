```
//写了个快排，先用个数组存值排序，再用一个数组来存数字对应的序号，最后遍历原数组找到排序后的值，然后把序号赋给原数组，用到了二分查找法
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void sort(int a[], long l, long r)
{
    if(l >= r)
        return;
    long i = l, j = r;
    int t = a[l];
    //printf("1");
    while(i < j)
    {
        while(i < j && a[j] >= t)
        {
            j--;
        }
        a[i] = a[j];
        while(i < j && a[i] <= t)
        {
            i++;
        }
        a[j] = a[i];
    }
    a[i] = t;
    sort(a, l, i - 1);
    sort(a, i + 1, r);
}
int* arrayRankTransform(int* arr, int arrSize, int* returnSize){
    if(arrSize == 0||arr == NULL)
    {
        *returnSize = 0;
        return arr;
    }
    if(arrSize == 1)
    {
        arr[0] = 1;
        *returnSize = 1;
        return arr;
    }
    int *a = (int *)malloc(sizeof(int)*arrSize );
    int i, j, count;
    for(i = 0;i < arrSize;i++)
    {
        a[i] = arr[i];
    }
    sort(a, 0, arrSize - 1);
    
    int * seq = (int *)malloc(sizeof(int) * arrSize);
    seq[0] = 1;
    for(i = 1;i < arrSize;i++)
    {
        if(a[i] == a[i - 1])
        {
            seq[i] = seq[i - 1];
        }
        else
        {
            seq[i] = seq[i - 1] + 1;
        }
    }

    for(i = 0;i < arrSize;i++)
    {
        int l = 0, r = arrSize - 1;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(arr[i] == a[mid])
            {
                arr[i] = seq[mid];
                break;
            }
            else if(arr[i] > a[mid])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
            
        }
    }
    *returnSize = arrSize;
    return arr;
}
```
