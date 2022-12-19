在所有java提交中击败100%的用户

public String simplifyPath(String path) {
       	   if(path == null) {
		   return null;
	   }
	   int len = path.length();
       StringBuffer re = new StringBuffer();
       int start = 0;
       for(int i = 0; i< len;) {
    	   if(path.charAt(i) == '.') {
    		   start = i;
    		   while(i < len && path.charAt(i) != '/') {
    			   i++;
    		   }
    		   if((i - start) == 2 && path.charAt(i-1) == '.') {
    			   int m = re.length();
    			   if(m > 2) {
        			   int end = m - 2;
        			   while(end >= 0 && re.charAt(end) != '/') {
        				   end--;
        			   }
    				   re.delete(end + 1 ,m);
    			   }
    			   continue;
    		   }
    		   if((i - start) == 1)continue;
    		   if(i == len) {
    			   re.append(path.substring(start,i));
        		   break;
    		   }
    		   while(i < len && path.charAt(i) != '/') {
    			   i++;
    		   }
    		   re.append(path.substring(start,i));
    		   continue;
    	   }
    	   else if(path.charAt(i) == '/') {
    		   while(i < len && path.charAt(i) == '/') {
    			   i++;
    		   }
    		   if(re.length() == 0  || re.charAt(re.length()-1) != '/') {
    			   re.append("/");
    		   }
    		   continue;
    	   }
    	   else {
    		   start = i;
    		   while(i < len && path.charAt(i) != '/' && path.charAt(i) != '.') {
    			   i++;
    		   }
    		   re.append(path.substring(start,i));
    	   }
       }
       if(re.length() > 1 && re.charAt(re.length() -1) == '/') {
    	   re.delete(re.length() - 1, re.length());
       }
       return re.toString();
    }