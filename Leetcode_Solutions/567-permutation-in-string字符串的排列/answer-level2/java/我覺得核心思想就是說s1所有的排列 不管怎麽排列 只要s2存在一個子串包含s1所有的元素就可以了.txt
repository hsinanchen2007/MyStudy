### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
public boolean checkInclusion(String s1, String s2) {
      if(s1.length()==0 || s2.length()==0 || s2.length()<s1.length()) return false;
      int[] s1map=new int[26];
      int[] s2map=new int[26];

		for (int i = 0; i <s1.length() ; i++) {
			s1map[s1.charAt(i)-'a']++;
			s2map[s2.charAt(i)-'a']++;
		}
		for (int i = 0; i <s2.length()-s1.length() ; i++) {
			if(match(s1map,s2map)){
				return true;
			}
			s2map[s2.charAt(i+s1.length())-'a']++;
			s2map[s2.charAt(i)-'a']--;
		}
		return match(s1map,s2map);

	}
	private boolean match(int[] s1map,int[] s2map){
		for (int i = 0; i <26 ; i++) {
			if(s1map[i]!=s2map[i])
				return false;

		}
		return true;
	}
}
```