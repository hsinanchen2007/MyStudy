### 解题思路
直接替换掉，然后用indexof函数

### 代码

```java
class Solution {
    public int strStr(String haystack, String needle) {
        if(needle.isEmpty()) {
			return 0;
		}
		
        if(!haystack.contains(needle)) {
			return -1;
		}
        
		haystack=haystack.replaceAll(needle, "2");
        return haystack.indexOf("2");
    }
}
```