
```c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if(arg1 < arg2)
        return -1;
    if(arg1 > arg2)
        return 1;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    int  i   = 0;
    int  j   = 0;
    int  idx = 0;
    int  min = (nums1Size > nums2Size) ? nums2Size : nums1Size;
    int* res = malloc(sizeof(int) * min);

    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);

    while(i < nums1Size && j < nums2Size)
    {
        if(nums1[i] < nums2[j])
        {
            i++;
        }
        else if(nums1[i] > nums2[j])
        {
            j++;
        }
        else
        {
            res[idx] = nums1[i];
            idx++;
            i++, j++;
        }
    }
    *returnSize = idx;
    return res;
}

int main(void)
{
    int  a[] = {4, 9, 5};
    int  b[] = {9, 4, 9, 8, 4};
    int* res;
    int  len;
    res = intersect(a, sizeof(a) / 4, b, sizeof(b) / 4, &len);
    for(int i = 0; i < len; i++)
    {
        printf("%d\t", res[i]);
    }
    return 0;
}
```