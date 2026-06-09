首先想到异或，确实不错，当然也可以用哈希来做。

```Java
class Solution{
	public char findTheDifference(String s,String t){
		int a[]=new int[26];
		for(char c:s.toCharArray()){
			a[c-'a']++;
		}
		for(char c:t.toCharArray()){
			if(a[c-'a']==0)
				return c;
			else a[c-'a']--;
		}
		return 0;
	}
}
```