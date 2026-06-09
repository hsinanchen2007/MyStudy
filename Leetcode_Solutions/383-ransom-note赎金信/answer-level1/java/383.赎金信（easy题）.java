```JAVA
class Solution{
	public boolean canConstruct(String ransomNote,String magazine){
		int b[]=new int[26];
		for(char c:magazine.toCharArray()){
			b[c-'a']++;
		}
		for(char c:ransomNote.toCharArray()){
			if(b[c-'a']==0)
				return false;
			b[c-'a']--;
		}
		return true;
	}
}
```