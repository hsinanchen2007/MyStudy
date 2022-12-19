### 解题思路
1. 遍历字符串中每个字符，通过ASCII表判断字符是否属于大写；
2. 若字符是大写，则将其`+32`转换为小写，为小写则不作处理；
3. 将转换后的字符连接成赋给最终结果`resultStr`；
4. 返回最终结果`resultStr`；
### 代码

```java
class Solution {
    public String toLowerCase(String str) {
        String resultStr = "";
		for (int i = 0; i < str.length(); i++) {
			int ch = (int) str.charAt(i);
			if ((int) ch >= 65 && (int) ch <= 90) {
				ch += 32;
			}
			resultStr += "" + (char) ch;
		}
		return resultStr;
    }
}
```