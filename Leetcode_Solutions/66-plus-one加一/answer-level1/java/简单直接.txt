### 解题思路
思路 要求既然是给数组最后一位加一  有进位则进位 那么直接按照这个来
### 代码
```java
class Solution {
    public static int[] plusOne(int[] digits) {
		//将最后一位+1 如果有进位则重新开始确定下标
		int point = digits.length-1;
		while (true) {
			if (digits[point] == 9) {
				//判断数组长度
				if (point == 0) {
					int[] temp = digits;
					digits = new int[temp.length+1];
					System.arraycopy(temp, 0, digits,1,temp.length);
					point++;
				}
				digits[point] = 0;
				point--;
			} else {
				digits[point] += 1;
				break;
			}
		}
		return digits;
	}
}
```