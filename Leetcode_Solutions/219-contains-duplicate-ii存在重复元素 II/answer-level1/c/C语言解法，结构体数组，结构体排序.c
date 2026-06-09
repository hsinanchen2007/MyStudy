结构体数组将数组的值和位置记录下来，之后对数组按照先值再位置排序的方法排序后，依次比较值和位置即可


```
typedef struct tag_arr{
   int value;
   int pos; 
}arr;

int compare (const void * a, const void * b)
{
    if((* (arr * )a).value != ( * (arr * )b).value)
       return ( * (arr * )a).value > ( * (arr * )b).value ? 1 : -1;
    else return (* (arr * )a).pos -( * (arr * )b).pos;

}



bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    arr *tmp;
    tmp = (arr *)malloc(sizeof(arr)*numsSize);
    for(int i=0;i<numsSize;i++)
    {
        tmp[i].value = nums[i];
        tmp[i].pos = i;
    }
    qsort(tmp,numsSize,sizeof(arr),compare);
    for(int i=0;i<numsSize-1;i++)
    {
        if(tmp[i].value!=tmp[i+1].value)
            continue;
        else
        {
            int index = tmp[i+1].pos - tmp[i].pos;
            if(index <= k)
                return true;
        }
    }
    return false;
}