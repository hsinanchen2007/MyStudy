```
class Solution {
    public String countAndSay(int n) {
        
        if (n == 1)
            return "1";
	        
        String[] arr = new String[n];

        arr[0] = "1";

        for (int i = 1; i < arr.length; i++)
            arr[i] = help(arr[i-1]);

        return arr[n-1];
        
    }
    
     private String help(String num)
	    {
	        String res = "";
	        int n = num.length();
	        int cut = 1;
	        for (int i = 0; i < n - 1; i++)
	        {
	            if (num.charAt(i) == num.charAt(i + 1)) 
	            {
	                cut++;
	                continue;
	            }
	            res += String.valueOf(cut) + num.charAt(i) ;
	            cut = 1;
	        }
	        res += String.valueOf(cut) + num.charAt(n-1);
	        return res;
	            
	    }
}
```
