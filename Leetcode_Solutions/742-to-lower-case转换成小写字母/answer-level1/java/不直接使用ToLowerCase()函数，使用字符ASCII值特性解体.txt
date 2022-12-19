### 解题思路
字符的ASCII值在处理字符串类算法时其实也是比较常见
A-Z 65-90  a-z 97-12 差值为32
具体应用见代码

### 代码

```java
class Solution {
    public String toLowerCase(String str) {
        StringBuilder sBuilder = new StringBuilder();
    	for(int i = 0;i<str.length();i++) {
    		char t  =str.charAt(i);
    		if(t>=65 && t<=90) {
    			char temp = (char)(t+32);
    			sBuilder.append(temp);
    		}else {
    			sBuilder.append(t);
    		}
    	}
    	return sBuilder.toString();
    }
}
```