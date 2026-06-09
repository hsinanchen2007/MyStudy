### 解题思路


### 代码

```java
class Solution {
    public int strStr(String haystack, String needle) {
        int result = -1;
		if(needle == null || needle.length() == 0) {
			return 0;
		}
		
		int hlen = haystack.length();
		int nlen = needle.length();
		
		if(hlen < nlen) {
			return result;
		}
		
		int j = 0;
		for (int i = 0; i < hlen; i++) {
			if(haystack.charAt(i) == needle.charAt(j)) {
				int temp = i;
				result = i;
				if(nlen == 1) {
					return result;
				}
				if(hlen - 1 - i < nlen -1) {
					return -1;
				}else {
					for (j = 1; j < nlen; j++) {
						temp++;
						if(haystack.charAt(temp) != needle.charAt(j)) {
							j = 0;
							result = -1;
							break;
						}else {
							if(j == nlen -1) {
								return i;
							}
						}
					}
				}
			}
		}
		return result;
    }
}
```