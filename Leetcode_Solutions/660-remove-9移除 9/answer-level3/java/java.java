```
   public int newInteger(int n) {
	        String a="";
	       int b =0;
	       while(n>0) {
	    	   int c= n%9;
	    	   a=c+a;
	    	   n=n/9;
	       }
	       return Integer.parseInt(a);
	    }
```
