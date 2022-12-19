### 解题思路
利用循环遍历字符串。对每一个字符判断是否为'.'。如果不是，将它添加到创建的StringBuilder对象中。如果是，将[.]添加到StringBuilder对象中。最后返回StringBuilder对象的字符串。

### 代码

```java
class Solution {
    public String defangIPaddr(String address) {
        StringBuilder result=new StringBuilder();
		for(int i=0;i<address.length();i++) {
			if(address.charAt(i)=='.')
				result.append("[.]");
			else
				result.append(address.charAt(i));
		}
		return result.toString();
	}
}
```