1、遍历一维数组，数组定义左右两个指针，依次向中间遍历。
2、两个元素相等则xor 1（两个元素不相等在翻转和反转后不会变化）。
3、如果是数组长度为奇数，则中间元素xor 1。
```
class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
		for (int[] is : A) {
			int left, right;
			for (left = 0; left < is.length / 2; ++left) {
                right = is.length - left - 1;
                if (is[left] == is[right]) {
                    is[left] = is[right] = is[left] ^ 1;
                }
			}
			if ((is.length & 1) == 1) {
				is[(int) is.length / 2] ^= 1;
			}
		}
		return A;
    }
}
```
