### 解题思路
此处撰写解题思路
思路：判断数组是否全部由9组成，如果是，那么数组长度则需要+1.
否则，进入循环，从末位判断起，若为9，则置为0，
### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
		if (this.isAllNine(digits)) {
			int[] ans = new int[digits.length+1];
			ans[0] = 1;
			return ans;
		}
		int len = digits.length;
		int[] ans = digits;
		int i = len-1;
		while (digits[i]==9) {
			ans[i] = 0;
			--i;
		}
		ans[i] += 1;
		return ans;
	}
	
	public boolean isAllNine(int[] digits) {
		for (int i=0; i<digits.length; ++i) {
			if (digits[i] != 9) return false;
 		}
		return true;
	}
    
}
```