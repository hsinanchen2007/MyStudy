1、基于下标进行判断奇偶
2、取偶数位while循环赋值
3、一开始就开辟数组空间，最后COPYOF截取返回

```
class Solution {
    public int[] decompressRLElist(int[] nums) {
    int[] results = new int[5000];
		int idx = 0;
		for (int i = 1; i < nums.length + 1; i++) {
			// 奇数判断
			if ((i & 1) == 1) {
				int k = nums[i - 1];
				while (k > 0) {
					results[idx] = nums[i];
					k--;
					idx++;
				}
			}
		}
		return Arrays.copyOf(results, idx);
    }
}
```
