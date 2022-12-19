1.考察双指针;
2.一个指针指向0,从左向右遍历,一个指针指向A.length - 1,从右向左遍历;
3.left遇到奇数,right遇到偶数就停下来,交换两个数值,循环终止条件left = right;
4.完结。

        public int[] sortArrayByParity(int[] A) {
		int left = 0, right = A.length - 1;
		while (left < right) {
			while (left < right && A[left] % 2 == 0)
				left++;
			while (left < right && A[right] % 2 != 0)
				right--;
			int temp = A[left];
			A[left] = A[right];
			A[right] = temp;
			left++;
			right--;
		}
		return A;
	    }