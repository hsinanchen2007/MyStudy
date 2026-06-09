### 解题思路
先后次序遍历填充新字符串，输出

### 代码

```java
class Solution {
    public String reverseLeftWords(String s, int n) {
        StringBuilder stringBuilder = new StringBuilder();
    	for (int i = n; i < s.length(); i++) {
			stringBuilder.append(s.charAt(i));
		}
    	for (int i = 0; i < n; i++) {
			stringBuilder.append(s.charAt(i));
		}
		return stringBuilder.toString();
    }
}
```