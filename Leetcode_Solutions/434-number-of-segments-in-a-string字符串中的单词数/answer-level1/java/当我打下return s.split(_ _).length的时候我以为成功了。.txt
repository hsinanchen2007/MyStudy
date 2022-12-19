```
 public static int countSegments(String s) {
	        if(s.equals("")){
	            return 0;
	        }
	        String[] aaStrings=s.split(" ");
	        int result=0;
	        for(int i=0;i<aaStrings.length;i++) {
	        	if(!aaStrings[i].equals("")) {
	        		result++;
	        	}
	        }
	        return result;
	    }
```
