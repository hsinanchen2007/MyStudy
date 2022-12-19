思路:
就是判断从后往前遍历最后一位是不是9,如果是9的话,那加1就需要进位
情况1:当前位置是9,前一位不是9,那么把当前为设为0,前一位加1
情况2:全部都为9,那么下标就是-1了,如果下标小于0,那么就new一个数组,数组长度为原长度+1,因为需要进位
,再把第一位元素设为1,其余元素默认为0

```
public static int[] plusOne(int[] digits) {
		int len = digits.length;
		int end = len - 1;
		while (end >= 0 && digits[end] == 9) {
			digits[end] = 0;
			end--;
		}
		if (end < 0) {
			digits = new int[len + 1];
			digits[0] = 1;
		} else {
			digits[end] ++;   
		}
		return digits;
	}
```