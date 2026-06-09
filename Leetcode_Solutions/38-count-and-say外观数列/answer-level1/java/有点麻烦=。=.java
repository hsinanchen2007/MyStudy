只想到了这个笨办法，1ms，击败98.56%，还行吧
```
class Solution {
    public String countAndSay(int n) {
        if(n==1)return "1";
        if(n==2)return "11";
        String s = "11";
        while(n>2){
            s = ppp(s);
            n-=1;    
        }
        return s;
    }
    public String ppp(String it){
        int count = 1;
        StringBuilder sb = new StringBuilder();
        int len = it.length();
        for(int i =1;i<len;i++){
        	char lastchar = it.charAt(i-1);
        	char nowchar = it.charAt(i);
            if(nowchar==lastchar){
            	count+=1;
            }else{
            	sb.append(count);
            	sb.append(lastchar);
            	count=1;
            }
            if(i==len-1) {
        		sb.append(count);
        		sb.append(nowchar);
        	}
        }
        return sb.toString();
        
    }
}
```
