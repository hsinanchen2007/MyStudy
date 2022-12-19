```Java []
class Solution{
	/**
	* 方法一：对数组的每一行元素进行翻转和反转： 
	* 	1. 翻转：left和right交换
	* 	2. 反转：异或1(^1)  即 1^1=0 0^1=1 
	* 	其中，a 数组的当前行；left 需要交换的开始端；right 需要交换的结束端。
	* 执行用时: 1 ms,在所有 Java 提交中击败了99.35%的用户
	* 内存消耗: 38.8 MB, 在所有 Java 提交中击败了82.41%的用户
	*/ 
	public int[][] flipAndInvertImage(int[][] A){
		int m = A.length;
		int n = A[0].length;
		for (int i = 0; i < m; i++) {
			int[] a = A[i];
			flipAndInvert(a, 0, n-1);
		}
		return A;
	}
	// 翻转和反转
	private void flipAndInvert(int[] a, int left, int right) {
		while(left <= right) {
			int temp = a[left] ^ 1;
			a[left] = a[right] ^ 1;
			a[right] = temp;
			left++; right--;
		}
	}
}
```
