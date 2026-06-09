**1.遍历每一行,定义两个左右指针;
2.左指针从左向右,右指针从右向左遍历;
3.数字不同继续遍历,数字相同0→1,1→0;
4.指针指向同一位置,说明行元素为奇数个,0→1,1→0;
5.完结。**

	public int[][] flipAndInvertImage(int[][] A) {
		for (int i = 0; i < A.length; i++) {
			int start = 0, end = A[i].length - 1;
			while (start < end) {
				if (A[i][start] != A[i][end]) {
					start++;
					end--;
				} else {
					A[i][start] = A[i][start] == 1 ? 0 : 1;
					A[i][end] = A[i][end] == 1 ? 0 : 1;
					start++;
					end--;
				}
			}
			if (start == end) {
				A[i][start] = A[i][start] == 1 ? 0 : 1;
			}
		}
		return A;
	}