### 解题思路
遍历字符串，碰到大写字母+32再强转，别问为什么

### 代码

```java
class Solution {
    public String toLowerCase(String str) {
    	if (str==null) {
			return null;
		}
    	StringBuilder stringBuilder = new StringBuilder();
    	for (char c : str.toCharArray()) {
			if (c>='A'&&c<='Z') {
				stringBuilder.append((char)(c+32));
			}else {
				stringBuilder.append(c);
			}
		}
		return stringBuilder.toString();
    }
}
```