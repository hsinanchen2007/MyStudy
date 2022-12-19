### 解题思路
此处撰写解题思路
新手第一次分享一些自己的思路（希望大佬斧正！）：
	对于{9,9,9}这样多出来一位的，直接new 一个新的数组 然后index 0 位替换位0，后期加个判断，如果0位为零，那就
	删去他，不是0就可以直接返回
	对于计算，我一开始是吧nums 转成int，long然后计算。发现out of range 问题，于是打算还是一个个计算。
	进位的思路：从最后一个元素开始加，如果最后一个为9(preInt[i-1] i 为preInt.length)，则 =0 然后preInt[i - 2]
	的值增1，如果不是9，那么直接增1，然后！！！break！！！
	就OK啦
	记得最后检验preIndex[0] 是否为0哦，为0则删一位

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
		// 先在0 位加一个0，最后判断是否为1
		int[] preInt = new int[digits.length + 1];
		preInt[0] = 0;
		for (int i = 1; i < preInt.length; i++) {
			preInt[i] = digits[i - 1];
		}
		// 从最后一位开始加
		for (int i = preInt.length; i > 0; i--) {
			if (preInt[i - 1] == 9) {
				preInt[i - 1] = 0;
			} else {
				preInt[i - 1] = preInt[i - 1] + 1;
				break;
			}
		}
		// 判断0号位是否为0，为0则删去；
		if (preInt[0] == 0) {
			for (int i = digits.length - 1; i >= 0; i--) {
				digits[i] = preInt[i + 1];
			}
			return digits;
		}else {
			return preInt;
		}
	}
}
```