### 解题思路
直接按照"."分组，长的再根据是否全为0，是则相等，不是则为1或-1。
### 代码

```java
class Solution {
    public int compareVersion(String version1, String version2) {
    	String[] v1 = version1.split("\\.");
    	String[] v2 = version2.split("\\.");
    	int min = Math.min(v1.length, v2.length);
    	for(int i=0;i<min;i++) {
    		int n1 = Integer.parseInt(v1[i]);
    		int n2 = Integer.parseInt(v2[i]);
    		if(n1 > n2) {
    			return 1;
    		}else if(n1 < n2) {
    			return -1;
    		}else {
    			continue;
    		}
    	}
    	if(v1.length>min) {
    		for(int i=min;i<v1.length;i++) {
    			int n1 = Integer.parseInt(v1[i]);
    			if(n1!=0) return 1;
    		}
    	}
    	if(v2.length>min) {
    		for(int i=min;i<v2.length;i++) {
    			int n2 = Integer.parseInt(v2[i]);
    			if(n2!=0) return -1;
    		}
    	}
    	return 0;
    }
}
```