```Java []
class SortArrayByParity{
	/**
	 * 1.双指针法A版：都从0开始，i指向奇数，j指向偶数，交换A[i]和A[j]
	 * 
	 * 执行用时 :3 ms, 在所有 Java 提交中击败了95.17%的用户
	 * 内存消耗 :45.2 MB, 在所有 Java 提交中击败了72.91%的用户
	 */
	public int[] sortArrayByParityA(int[] A) {
		int i = 0, j = 0;
		int len = A.length;
		while(i < len && j < len) {
			if(A[j] % 2 != 0) {	//若当前元素是奇数，则j++，
				j++;
			}else {		//若当前元素为偶数，交换A[i]和A[j]
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp;
				i++; j++;
			}
		}
		return A;
	}
	
	/**
	 * 2.双指针法B版：新数组a[len]，i指向索引0，j指向len-1。
                        若当前元素a[k++]是偶数，则存在a[i++];若是奇数，则存在a[j--]。

	 * 执行用时 :3 ms, 在所有 Java 提交中击败了95.17%的用户
	 * 内存消耗 :45.4 MB, 在所有 Java 提交中击败了72.07%的用户
	 */
	public int[] sortArrayByParityB(int[] A) {
		int len = A.length;
		int[] a = new int[len];
		int k = 0, i = 0, j = len - 1;
		while( k < len) {
			if(A[k] % 2 == 0) {
				a[i++] = A[k];
			}else {
				a[j--] = A[k];
			}
			k++;
		}
		return a;
	}
}
```
