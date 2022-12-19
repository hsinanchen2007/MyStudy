### 解题思路
1. 若给定的数为负数，则非回文数；
2. 若给定的数是个位数，则是回文数；
3. 给定的数不小于10时，将其转换为String类型；
4. 循环字符串`strX`的前`(int)(strX.length() / 2)`位；
5. 判断字符串的`i`和`strX.length() - 1 - i`位是否相同，一旦不同则不是回文数；
6. 默认x是回文数；

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
       if (x < 0) {
			return false;
		} else {
			if (x < 10){
				return true;
			}else {
				String strx = Integer.toString(x);
				for (int i = 0; i < (int)(strx.length() / 2); i++){
					if (strx.charAt(i) != strx.charAt(strx.length() - 1 - i)){
						return false;
					}
				}
			}
		}

		return true;
    }
}
```