### 解题思路
此处撰写解题思路
1.定义result=-1，默认不存在
2.当haystack中不包含needle时，返回-1
3.当needle为""时，返回0
4.循环判断
	遍历haystack，内层遍历haystack
	当内层循环一直满足条件haystack.charAt(i + j) == needle.charAt(j) 时，返回答案
### 代码

```java
class Solution {
    public int strStr(String haystack, String needle) {
        int result = -1;
		if (!haystack.contains(needle))
			return result;
		if (needle.equals(""))
			return 0;
		for (int i = 0; i < haystack.length(); i++) {
			for (int j = 0; j < needle.length(); j++) {
				if (haystack.charAt(i + j) == needle.charAt(j)) {
					if (j == 0)
						result = i;
					if (j == needle.length() - 1)
						return result;
					continue;
				} else {
					result = -1;
					break;
				}
			}
		}
		return result;
    }
}
```