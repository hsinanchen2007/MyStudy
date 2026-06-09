void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int end1 =nums1Size  - 1, end2 = nums2Size - 1;
	for (int i = end1; i >= nums1Size - nums2Size; --i)
	{
		nums1[i] = nums2[end2];
        --end2;
	}

		for (int i = 0; i < nums1Size - 1; ++i)
	{
		for (int j = 0; j < nums1Size - 1- i; ++j)
		{
			if (nums1[j] >nums1[j + 1])
			{
				int tmp = nums1[j + 1];
				nums1[j + 1] = nums1[j];
				nums1[j] = tmp;
			}
		}
	}
}