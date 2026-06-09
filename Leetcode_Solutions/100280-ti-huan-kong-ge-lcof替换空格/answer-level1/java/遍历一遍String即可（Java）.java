```
class Solution {
	public String replaceSpace(String s) {
		String out="";
		for(int i=0;i<s.length();i++) { 
			if(s.charAt(i)==' ') {out+="%20";}
			else out+=s.charAt(i);
		}
		return out;
		
	}
}
```
这样很简单