### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int Cmp(const void *a, const void *b)
{
    //if the value of a is bigger than the value of b
    if( *( int * )a > *( int * )b ){

        return 1;

    //if the value of a equal to the value of b
    } else if( *( int * )a == *( int * )b ){

        return 0;

    }

    //if the value of b is bigger than the value of a
    return -1;

}
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    int *returnArr = (int *)malloc(sizeof(int) * (nums1Size + nums2Size));
    *returnSize = 0;
    if (!nums1Size || !nums2Size) {
        return NULL;
    }
    qsort(nums1, nums1Size, sizeof(int), Cmp);
    qsort(nums2, nums2Size, sizeof(int), Cmp);
    for (int i = 0, j = 0; i < nums1Size && j < nums2Size;) {
        if (nums1[i] < nums2[j]) {
            i++;
            continue;
        } else if (nums1[i] > nums2[j]) {
            j++;
            continue;
        } else {
            returnArr[*returnSize] = nums1[i];
            i++;
            j++;
            (*returnSize)++;
        }
    }
    return returnArr;
}
```