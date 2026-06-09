直接暴力搞过的哈哈哈
```
class Solution {
    public int findSubstringInWraproundString(String p) {
        
    	StringBuilder str=new StringBuilder();
        
    	str.append("abcdefghijklmnopqrstuvwxyz");
    	str.append(str.toString());
    	while(str.length()<p.length())
    		str.append(str.toString());
    	
    	int l=0,r=1;
    	int len=p.length(),ans=0;
    	int[] a=new int[30];
    	String s=str.toString();
    	while(l<len) {
    		if(s.contains(p.substring(l,r))) {
    			if(r<len) {a[p.charAt(r-1)-'a']=Math.max(a[p.charAt(r-1)-'a'], r-l);r++;}
    			else {
    				a[p.charAt(r-1)-'a']=Math.max(a[p.charAt(r-1)-'a'], r-l);
    				break;
    			}
    		}
    		else
    			l++;
    	}
    	
    	for(int i=0;i<26;i++) ans+=a[i];
    	
    	return ans;
    }
}
```
