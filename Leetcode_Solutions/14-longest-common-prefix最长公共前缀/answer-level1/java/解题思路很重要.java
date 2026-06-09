### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {

        if(strs.length == 0)
			return "";
		
		//字符数组的长度
		int len = strs.length;
		StringBuilder sb = new StringBuilder();
		String prefix = strs[0];
		
		for (int i = 1; i < len; i++) {
			while(strs[i].indexOf(prefix) != 0) { //表示不是公共前缀 -1
				prefix = prefix.substring(0, prefix.length() - 1);
				if(prefix.isEmpty())
					return "";
			}
		}
		return prefix;
    }
}
```
![image.png](https://pic.leetcode-cn.com/bdbcde712fc8b1b0d0cd813fd59a53dfe7ef6911dd211784a3ac24932fabe35e-image.png)
