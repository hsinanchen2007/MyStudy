```
class Solution {
    public String validIPAddress(String IP) {
    	if(IP.length()==0) return "Neither";
        if(IP.contains(".")) {
        	if(IP.charAt(0)=='.' || IP.charAt(IP.length()-1)=='.') return "Neither";
        	String[] str=IP.split("\\.");
        	if(str.length!=4) return "Neither";
        	for(int i=0;i<str.length;i++) {
        		if(str[i].length()==0) return "Neither";
        		if(str[i].length()>1 && str[i].charAt(0)=='0') return "Neither";
        		int sum=0;
        		for(int j=0;j<str[i].length();j++) {
        			if(str[i].charAt(j)<'0' || str[i].charAt(j)>'9') return "Neither";
        			sum=sum*10+(str[i].charAt(j)-'0');
        			if(sum>255) return "Neither";
        		}
        	}
        	return "IPv4";
        }
        else {
        	String[] str=IP.split(":");
        	if(IP.charAt(0)==':' || IP.charAt(IP.length()-1)==':') return "Neither";
        	if(str.length!=8) return "Neither";
        	for(int i=0;i<str.length;i++) {
        		if(!Jud(str[i]) || str[i].length()==0) return "Neither";
        		for(int j=0;j<str[i].length();j++) {
        			if(str[i].charAt(j)>='0' && str[i].charAt(j)<='9' 
        					|| str[i].charAt(j)>='a' && str[i].charAt(j)<='f'
        					|| str[i].charAt(j)>='A' && str[i].charAt(j)<='F')
        				continue;
        			return "Neither";
        		}
        	}
        	return "IPv6";
        }
    }
    
    private boolean Jud(String str) {
    	if(str.length()>4) return false;
    	return true;
    }
}		
```
