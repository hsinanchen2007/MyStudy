void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (m == 0)
		{
			for (int i = 0; i<n; i++)
				nums1[i] = nums2[i];
			return;
		}
		else if (n == 0)
			return;
		int iter = m - 1;
		int i = n - 1;
		int move_right = n - 1;
		while (iter >= 0)//从后往前遍历，看每个元素要往后移动多少个位置；
		{
			while (i >= 0 && nums2[i] >= nums1[iter])
				i--;//nums2[0]到nums2[i]比nums1[iter]小，说明比nums1[iter]小的有i+1个；
			int move = i + 1;//nums1[iter]要向右移动i+1个位置；
			nums1[iter + i + 1] = nums1[iter];
			int k = iter + i + 2;
			for (int s = i + 1; s <= move_right; s++)//这里是将nums2中i+1到move_right这之间都是比原nums1[iter]大的，且比原nums1[iter+1]小的,
			//将这一部分元素复制到nums[iter+i+1](也就是原nums[iter]的后面)；
			{
				nums1[k++] = nums2[s];
			}
			move_right = i;//然后更新move_right；
			iter--;
		}
		for (int j = 0; j <= i; j++)
			nums1[j] = nums2[j];//再将nums2中比所有nums1中的元素都小的复制到nums1的头部；
	}