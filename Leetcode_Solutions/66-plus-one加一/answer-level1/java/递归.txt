思路：单独写一个方法，传入数组和下标，如果该下标对应的元素不等于9，则加一，如果等于9，则赋值为0，并将下标减一，并调用自己。
在plusOne()方法中还要判断数组中所有的数是不是都等于9，如果都等于9，新new一个长度加一的数组，并将第一个元素赋值为1.

```
class Solution {
    public int[] plusOne(int[] digits) {

        int len = digits.length;
		boolean flag = false;
		for(int i = 0;i < len;) {
			if(digits[i] == 9) {
				i ++;
			} else {
				flag = true;
				break;
			}
		}
		
		if(flag) {
			digits = recursion(digits,len - 1);
		} else {
			digits = new int[len + 1];
			digits[0] = 1;
		}
		
		return digits;

	}
	
	public int[] recursion(int[] nums,int len) {
		
		if(nums[len] != 9) {
			nums[len] = nums[len] + 1;
		} else {
			nums[len] = 0;
			recursion(nums, len - 1);
		}
		return nums;
    }
}
```
