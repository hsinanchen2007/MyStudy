### 解题思路
- 先合并两个有序数组
- 再找中位数

### 代码

```c
typedef struct 
{
    int * arr;
    int length;
}list , *plist;

plist createArr(int length)
{
    plist temp = NULL;

    temp = malloc(sizeof(list));
    temp -> length = length;
    temp -> arr = malloc(length*sizeof(int));

    return temp;
}

void merge(int* list1 ,int* list2 ,plist list3,int length1,int length2,int length3)
{
    int i , j , k;

    if(length1 == 0)
    {
        for(i=0;i<length3;i++)
        {
            list3->arr[i] = list2[i];
        }
        return;
    }
    if(length2 == 0)
    {
        for(i=0;i<length3;i++)
        {
            list3->arr[i] = list1[i];
        }
        return;
    }

    i=0 ; j=0 ; k=0;
    while(i<length1 && j<length2)
    {
        if(list1[i] >= list2[j])
        {
            list3->arr[k] = list2[j];
            k++ ; j++;
        }
        else 
        {
            list3->arr[k] = list1[i];
            k++ ; i++;
        }
    }
    
    while(i<length1)
    {
        list3->arr[k] = list1[i] ;
        k++ ; i++;
    }
    while(j<length2)
    {
        list3->arr[k] = list2[j] ;
        k++ ; j++;
    }

}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int length = nums1Size + nums2Size;
    double temp = 0 ;

    plist arr = createArr(length);

    merge(nums1,nums2,arr,nums1Size,nums2Size,length);

    if((length%2) == 0)
    {
        temp = (arr->arr[length/2]+arr->arr[length/2-1])/2.0;
        return temp ;     
    }

    temp = (double)arr->arr[length/2];
    return temp;
}
```