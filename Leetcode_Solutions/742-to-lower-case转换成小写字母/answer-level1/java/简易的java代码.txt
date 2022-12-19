### 代码

```java
class Solution {
    public String toLowerCase(String str){
		StringBuilder sb = new StringBuilder();
		for(int i=0;i<str.length();i++){
			/*
			 * A-Z:65-90
			 * a-z:97-122
			 */
			int curr = str.charAt(i);
			if(curr>=65 && curr<=90){
				curr = curr+32;
			}
			sb.append((char)(curr));
		}
		return sb.toString();
	}
}
```

### 性能表现

![1.png](https://pic.leetcode-cn.com/7b2546b679a5cecca39a218cd49b50bfdd81b425838e5c01ae9d231e09e032ef-1.png)
