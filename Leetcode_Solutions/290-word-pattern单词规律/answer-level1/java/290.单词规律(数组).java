```
class Solution {
    public boolean wordPattern(String pattern, String str) {
        if(pattern.length()<1)
            return false;
           int a[]=new int[90000];
          int b[]=new int[90000];
	  String s[]=str.split(" ");
        if(pattern.length()!=s.length)
            return false;
        else{
            for(int i=0;i<pattern.length();i++){
			int a1=pattern.charAt(i);
			int b1=strTonum(s[i]);
			if(a[a1]!=b[b1])
				return false;
			else{
				a[a1]=i+1;
				b[b1]=i+1;
			}
		}
		return true;
        }
		
	}

	public int strTonum(String s){
		int sum=0;
		for(int i=0;i<s.length();i++){
            sum+=s.charAt(i)*(i+23);
        }
		return sum;
	}
}
```