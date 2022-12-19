![D4124BB0-76F3-49D5-953A-3A669A375E5A.jpeg](https://pic.leetcode-cn.com/ab9e3513a1c52e0433b918d19daa5be67d8dbf93315f6114368e3d1dd4808f95-D4124BB0-76F3-49D5-953A-3A669A375E5A.jpeg)

```
int Cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{    
    int i;
    double returnVal = 0.0;
    int *numsFinal = (int *)malloc((nums1Size + nums2Size) * sizeof(int));
    memcpy(numsFinal, nums1, nums1Size * sizeof(int));
    memcpy(&(numsFinal[nums1Size]), nums2, nums2Size * sizeof(int));
    qsort(numsFinal, (nums1Size + nums2Size), sizeof(numsFinal[0]), Cmp);
    if (((nums1Size + nums2Size) % 2) != 0) {
        return numsFinal[(nums1Size + nums2Size) / 2] / 1.0;
    } else {
        return (numsFinal[(nums1Size + nums2Size) / 2] +numsFinal[(nums1Size + nums2Size) / 2 - 1]) / 2.0;
    }
}
```
