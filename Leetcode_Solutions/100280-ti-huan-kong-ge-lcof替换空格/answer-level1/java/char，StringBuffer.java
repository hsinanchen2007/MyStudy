### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        String str1 = "%20";
		StringBuffer sb = new StringBuffer();
		char[] ch = s.toCharArray();
		int i= 0;
		for(i = 0;i < ch.length;i++) {
			if(ch[i] == ' ') {
				sb.append(str1);
			}
			else
				sb.append(ch[i]);
		}
		return sb.toString();
    }
}
```