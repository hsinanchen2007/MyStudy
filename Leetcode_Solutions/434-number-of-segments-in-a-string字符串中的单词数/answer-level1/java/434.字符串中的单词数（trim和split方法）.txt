```Java
class Solution{
	public int countSegments(String s){
		s=s.trim();
		if(s==null||s.equals(""))
			return 0;
		String str[]=s.split(" +");
		return str.length; 
	}
}
```