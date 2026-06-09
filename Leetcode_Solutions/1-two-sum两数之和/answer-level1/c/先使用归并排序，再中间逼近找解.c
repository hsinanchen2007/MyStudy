### 解题思路
1、建立一个表，保存原始数组的下标和值
2、根据数组的值对表排序
3、使用中间值逼近的办法找到目标解，由于之前已经将下标保存，即可获取到对于数字的原始下标

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int res[2] = {0, 0};
struct listNode
{
    int value;
    int index;
};

int merge(struct listNode *arr, int left, int mid, int right, struct listNode *tmp)
{
    int i = left;
    int j = mid + 1;
    int k = left;

    while((i <= mid)&&(j <= right))
    {
        if(arr[i].value < arr[j].value)
        {
            tmp[k++] = arr[i++];
        }
        else
        {
            tmp[k++] = arr[j++];
        }
    }

    while(i <= mid)
    {
        tmp[k++] = arr[i++];
    }

    while(j <= right)
    {
        tmp[k++] = arr[j++];
    }

    memcpy(arr + left, tmp + left, sizeof(struct listNode)*(right - left + 1));

    return 0;
}

int mergeSort(struct listNode *arr, int left, int right, struct listNode *tmp)
{
    int mid = 0;
    if(left < right)
    {
        mid = left + (right - left)/2;
        mergeSort(arr, left, mid, tmp);
        mergeSort(arr, mid + 1, right, tmp);
        merge(arr, left, mid, right, tmp);
    }
    return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i = 0;
    int j = numsSize - 1;
    int k = 0;

    struct listNode *list = (struct listNode *)malloc(sizeof(struct listNode) * numsSize);
    struct listNode *tmp = (struct listNode *)malloc(sizeof(struct listNode) * numsSize);
    
    for(k = 0; k < numsSize; k++)
    {
        list[k].value = nums[k];
        list[k].index = k;
    }
    
    mergeSort(list, 0, (numsSize - 1), tmp);

    while(i < j)
    {
        if(target == (list[i].value + list[j].value))
        {
            res[0] = list[i].index;
            res[1] = list[j].index;
            *returnSize = 2;
            break;
        }
        else if(target > (list[i].value + list[j].value))
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return res;
}


```