class Solution {
    public int myAtoi(String str) {
         if (str == null || str.length() == 0) {
            return 0;
        }
int start = 0;
    		for(int i=0;i<str.length();i++) {
    			if(str.charAt(i)!=' ') {
    				start=i;
    				break;
    			}
    		}
    		char c = str.charAt(start);
    		boolean b = !Character.isDigit(c)&&c!='-'&&c!='+';
    		if(b) {
    			return 0;
    		}
    		boolean b1 = c=='-';
    		int j = c=='-'||c=='+'?start+1:start;
    		
    		long ans=0;
    		for(int i=j;i<str.length();i++) {
    				if(!Character.isDigit(str.charAt(i))) {
    					break;
    				}
    				ans=ans*10+Integer.valueOf(str.charAt(i)-'0');
    				if(ans>Integer.MAX_VALUE||ans<Integer.MIN_VALUE) {
    					break;
    				}
    			
    		}
    		if(b1) {
    			ans = -ans;
    		}
    		if(ans>Integer.MAX_VALUE) {
    			return Integer.MAX_VALUE;
    		}else if(ans<Integer.MIN_VALUE) {
    			return Integer.MIN_VALUE;
    		}
    		return (int) ans;
    }
}