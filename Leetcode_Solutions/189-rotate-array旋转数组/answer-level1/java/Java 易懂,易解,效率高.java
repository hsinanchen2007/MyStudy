1.k取模数组的长度;
2.反转前半段数组,反转后半段数组;
3.反转整个数组;
4.完结。

    public void rotate(int[] arr, int k) {
		if (k < 0) {
			System.out.println("k不能小于0!");
			return;
		}
		k %= arr.length;
		// 反转前半段数组
		reverse(arr, 0, arr.length - k - 1);
		// 反转后半段数组
		reverse(arr, arr.length - k, arr.length - 1);
		// 反转整个数组
		reverse(arr, 0, arr.length - 1);
	}

	public void reverse(int[] arr, int left, int right) {
		while (left < right) {
			int temp = arr[left];
			arr[left++] = arr[right];
			arr[right--] = temp;
		}
	}