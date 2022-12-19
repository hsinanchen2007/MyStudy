### 解题思路
此处撰写解题思路
三角形特点:排序数组a<b<c,如果a+b>c,那么a,b,c就能组成三角形
从最后开始遍历i(c), L(a)，R(b),

1.初始i=len-1, L=0，R=i-1;如果L+R>i,则L,R,i能组成三角型，因为数组是生序排列的，L+R都大于I，
那么L到R之间的这些值加R也恒大于i，所以有R-L个三角形，这时是只需要R--，不需要L++，因为L++恒成立
2.如果L+R<I,这个好理解，需要L++
### 代码

```java
class Solution {
    public int triangleNumber(int[] nums) {
		if (nums.length < 3) {
			return 0;
		}
		int res = 0;
		Arrays.sort(nums);
		int len = nums.length;
		for (int i = len - 1; i >= 0; i--) {
			int L = 0;
			int R = i - 1;
			while (L < R) {
				int calc1 = nums[L] + nums[R] - nums[i];
				if (calc1 > 0) {
					res = res + (R - L);
					R--;
				} else {
					L++;
				}
			}
		}
		return res;
	}
}
```