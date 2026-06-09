### 解题思路
首先判断str1和str2是否有最大公约数，即两字符串是否有公因子（两字符串不同顺序相加是否一致）然后求最大公约数，之后分割字符串。

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        String gcd = "";
		int a = str1.length();
		int b = str2.length();
		if ((str1+str2).equals(str2+str1)) {
			//求最大公约数a
			while(b!=0) {
				int temp = b;
				b = a % b;
				a = temp;
			}
            return str1.substring(0,a);
		}
		return "";
	}
}
```