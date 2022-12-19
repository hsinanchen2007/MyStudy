### 解题思路
用hash表，（键-值）--->（字符-出现次数）
若两个字符串中所有字符出现的次数相同，则可以重排成同一字符串

### 代码

```java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        char[] c1=s1.toCharArray();
		char[] c2=s2.toCharArray();
		if(c1==null|c2==null|c1.length==0|c2.length==0|c1.length!=c2.length) {
			return false;
		}
		Map<Character,Integer>map1=new HashMap<Character,Integer>();
		Map<Character,Integer>map2=new HashMap<Character,Integer>();
		for(int i=0;i<c1.length;i++) {
			map1.put(c1[i], map1.getOrDefault(c1[i], 0)+1);
		}
		for(int j=0;j<c2.length;j++) {
			map2.put(c2[j], map2.getOrDefault(c2[j], 0)+1);
		}
		for(int i=0;i<c1.length;i++) {
			if(map1.get(c2[i])!=map2.get(c2[i]))  {
				return false;
			}
		}
		return true;
    }
}
```