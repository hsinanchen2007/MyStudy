### 解题思路
此处撰写解题思路

### 代码

```c
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
	if((nums1 == NULL && nums2 == NULL) || (nums1Size <= 0 && nums2Size <= 0))
		return 0;

	int i,j,temp;
	double return_num;
	int len = nums1Size + nums2Size;
	int *pnew = malloc(len*sizeof(int));
	if(pnew == NULL)
		return 0;
	for(i=0;i<nums1Size;i++)
	{
		pnew[i] = nums1[i];
	}

	for(i=nums1Size;i<len;i++)
    {
        pnew[i] = nums2[i-nums1Size];
    }

	for(i=nums1Size;i<len;i++)
	{
		temp = pnew[i];
		j=i-1;
		while(j>=0 && pnew[j]>temp)
		{
			pnew[j+1] = pnew[j];
			j--;
		}
		pnew[j+1]=temp;
	}

	if(len%2 == 0)
		return_num = (pnew[len/2]+pnew[len/2 - 1])/2.0;
    else
	    return_num = pnew[(len-1)/2];
	free(pnew);
	return return_num;
}
```