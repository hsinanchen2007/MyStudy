### 解题思路
输出数据的方法会溢出，直接用数组解决很完美

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        for (int i = digits.length - 1; i >= 0; i--) {
			if (digits[i] != 9) {        //同时考虑了本位数+1和进位
                digits[i]++;          
				return digits;          //直接跳出
			} 
			digits[i] = 0;
		}
                //跳出for循环，说明数字全部是9
		int[] temp = new int[digits.length + 1];
		temp[0] = 1;
		return temp;
    }
}
```