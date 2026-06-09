### 解题思路
split+trim，跳过空字符串多试几次

### 代码

```java
class Solution {
    public String reverseWords(String s) {
    	String[]words = s.split(" ");
    	String ans = "";
    	for (int i = words.length-1; i>=0; i--) {
    		if ("".equals(words[i])) {
				continue;
			}
			ans +=words[i].trim()+" ";
		}
    	return ans.trim();
    }
}
```