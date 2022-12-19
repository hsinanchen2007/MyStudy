纯C 归并 时间复杂度未满足，初学练习
```
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int uIndexOfM, uIndexOfN1, uIndexOfN2;
    double dMedianNum = 0;

    int* pMergeArray = (int*)malloc(sizeof(int)*(nums1Size+nums2Size));
    memset(pMergeArray, 0, sizeof(int)*(nums1Size+nums2Size));

    /* merge sort the array */
    for(uIndexOfM = uIndexOfN1 = uIndexOfN2 = 0;                          \
       (uIndexOfN1 <= (nums1Size - 1)) & (uIndexOfN2 <= (nums2Size - 1)); \ 
        uIndexOfM++)
        if(nums1[uIndexOfN1] <= nums2[uIndexOfN2])
            *(pMergeArray + uIndexOfM) = nums1[uIndexOfN1++];
        else
            *(pMergeArray + uIndexOfM) = nums2[uIndexOfN2++];

    /* array1 is longer */
    while(uIndexOfN1 <= (nums1Size - 1))
        *(pMergeArray + (uIndexOfM++)) = nums1[uIndexOfN1++];
    /* array2 is longer */
    while(uIndexOfN2 <= (nums2Size - 1))
        *(pMergeArray + (uIndexOfM++)) = nums2[uIndexOfN2++];

    /* get the median */
    dMedianNum = ((nums1Size+nums2Size) % 2)                      ? \
                *(pMergeArray + ((nums1Size+nums2Size) >> 1))     : \
                (                                                   \
                  *(pMergeArray + ((nums1Size+nums2Size) >> 1))     \
                + *(pMergeArray + ((nums1Size+nums2Size) >> 1) -1)  \
                ) / 2.0;

    free(pMergeArray);
    
    return dMedianNum;
}
```
