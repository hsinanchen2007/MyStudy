### 解题思路
此处撰写解题思路

### 代码

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	int i,j;
	int len,temp;
	
	if(nums1 == NULL || nums2 == NULL || nums1Size == 0 || nums2Size == 0 || nums1Size < m+n)
		return;
	if(m == 0)
	{
		for(i=0;i<n;i++)
			nums1[i]=nums2[i];
		return;
	}
	if(nums1[m-1] <= nums2[0])
	{
		for(i=0;i<n;i++)
			nums1[m+i] = nums2[i];	
	}else if(nums1[0] >= nums2[n-1])
	{
		for(i=0;i<m;i++)
			nums1[i+n] = nums1[i]; 
		for(i=0;i<n;i++)
			nums1[i]=nums2[i];
	}else
	{
		for(i=0;i<n;i++)
		{
			nums1[m+i] = nums2[i];
		}
		len = m+n;
		for(i=m;i<len;i++)
		{
			temp = nums1[i];
			for(j=i-1;j>=0 && nums1[j]>temp;j--)
			{
				nums1[j+1] = nums1[j];
			}
			nums1[j+1] = temp;
		}	
	}
}
```