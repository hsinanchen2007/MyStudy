### 解题思路
两个两个比较就行了

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length==0||strs==null)
			return "";
		String ands=strs[0];
		for(int i=1;i<strs.length;i++) {
			int j=0;
			for(;j<ands.length()&&j<strs[i].length();j++) {
				if(ands.charAt(j)!=strs[i].charAt(j))
					break;
			}
			ands=ands.substring(0,j);
		}
		if(ands.equals(""))
			return "";
		return ands;
    }
}
```