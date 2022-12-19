### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
		for(int i = 0;i<astr.length()-1;i++) {
			if(astr.length()==2 && astr.charAt(0)==astr.charAt(1)) {
				return false;
			}
		for(int j = 0;j<i;j++) {
			if(astr.charAt(i)==astr.charAt(j)) {
				return false;
			}
			
		}
		}
		return true;
    }
}
```