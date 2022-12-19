```
 void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	
	int i = m - 1, j = n - 1, k = m + n - 1; 
	
	while( i >= 0 && j >= 0)
	{
		if(nums1[i] >= nums2[j])
		{
			nums1[k--] = nums1[i--];
		}
		else
		{
			nums1[k--] = nums2[j--];
		}
	}
	
	if( i < 0) //如果num2先结束，此时num1剩余数据无须改动。 按理来说这里的判断可以省略，但是我省略之后时间从4ms 增加至8ms，疑惑
	{
		while( j >= 0)
		{
			nums1[j] = nums2[j];
			j--;
		}
	}
	
    return;
}
```
