### 解题思路
末位+1，然后从末位开始循环，如果大于等于10上一位再加一，循环过后，如果第一位是零的话，再给第一位设1，后面位数顺延。

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        digits[digits.length-1]++;
		for(int i = digits.length-1; i >= 0; i--){
			if(digits[i]>=10){
				digits[i]=0;
				if(i>0){
					digits[i-1]++;
				}
			}
		}
		if(digits[0] == 0){
			int[] temp = new int[digits.length+1];
			temp[0] = 1;
			for(int i = 0; i < digits.length; i++){
				temp[i+1]=digits[i];
			}
			digits = temp;
		}
		return digits;
    }
}
```