```
static int comp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int* buf = (int*)calloc(sizeof(int), nums1Size + nums2Size);

	memcpy((void*)buf, (void*)nums1, nums1Size * sizeof(int));
	memcpy((char*)buf + nums1Size * sizeof(int), (void*)nums2, nums2Size * sizeof(int));

	qsort(buf, nums1Size + nums2Size, sizeof(int), comp);

	int mid = nums1Size + nums2Size;
	if ((nums1Size + nums2Size)%2 == 0){
        return (double)(buf[(nums1Size + nums2Size)/2] + buf[((nums1Size + nums2Size)/2) - 1])/2;
	}else{
        return buf[(nums1Size + nums2Size)/2];
    }

	return 0;
}
```
