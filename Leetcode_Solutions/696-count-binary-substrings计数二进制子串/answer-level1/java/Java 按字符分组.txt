### 解题思路

![696.png](https://pic.leetcode-cn.com/ad962b8c15268e0c82e3869c6837ca947ce4b158b9999ee4958b85f9dcf342fd-696.png)


### 代码

```java
class Solution {
    public int countBinarySubstrings(String s) {
        char chars[] = s.toCharArray();
		int group[] = new int[s.length()];
		int anchor = 0;
		group[0] = 1;
		for(int i=1;i<chars.length;i++) {
			if(chars[i-1] != chars[i]) {
				anchor++;
				group[anchor]=1;
			}else {
				group[anchor]++;
			}
		}
		int result = 0;
		for(int i=1;i<=anchor;i++) {
			result += Math.min(group[i-1], group[i]);
		}
		return result;
    }
}
```