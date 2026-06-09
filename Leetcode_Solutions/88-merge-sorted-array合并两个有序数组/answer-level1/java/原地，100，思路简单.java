```

			/**
	 * 还真是简单
	 * 
	 * @param nums1
	 * @param m
	 * @param nums2
	 * @param n
	 */
	public void merge(int[] nums1, int m, int[] nums2, int n) {

		for (int i = m-1; i >=0; i--) {
			nums1[nums1.length - m + i] = nums1[i];
		}
		int cursor1 = nums1.length - m;
		int cursor2 = 0;
		int cursor = 0;
		while (cursor2 < nums2.length && cursor1 < nums1.length) {
			if (nums1[cursor1] >= nums2[cursor2]) {
				nums1[cursor] = nums2[cursor2];
				cursor2++;
			} else {
				nums1[cursor] = nums1[cursor1];
				cursor1++;
			}
			cursor++;
		}
		while (cursor2 < nums2.length) {
			nums1[cursor] = nums2[cursor2];
			cursor2++;
			cursor++;
		}
		while (cursor1 < nums1.length) {
			nums1[cursor] = nums1[cursor1];
			cursor1++;
			cursor++;
		}

	}
```
