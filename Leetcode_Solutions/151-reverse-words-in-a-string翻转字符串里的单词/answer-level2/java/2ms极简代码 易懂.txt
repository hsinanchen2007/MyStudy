### 解题思路
去空格
字符串拼接

### 代码

```java
class Solution {
    public String reverseWords(String s) {
		String[] sArr = s.split(" ");
		StringBuilder sb = new StringBuilder();
		for(int i=sArr.length-1;i>=0;i--) {
			sb=sArr[i].length()==0?sb:sb.append(sArr[i]).append(" ");
		}
		return (sb+"").trim();
    }
}
```