边界条件太多了……
```
class Solution {
    public double myPow(double x, int n) {
        double result = 1;
        boolean flag  = true;
        

         if (x == 1)
			 return x;
		 else if (x == -1)
		 {
			 if (n % 2 == 0)
				 return 1;
			 else
				 return -1;
		 }
        
        if(n==0){return 1;}
        else if(n<0 && n!=(-2147483648))
        {
            flag = false;
            n = -n;
        }
        else if(n == (-2147483648) && Math.abs(x) > 1)
        {return 0;}
        
        result = x;
        
        for(int i = 1; i<n;)
        {
            if(i*2 <= n)
            {
                result *= result;
                i *= 2;
            }
            else
            {
                result *= x;
                i++;
            }
            if (Math.abs(result) < 1e-16) 
	        return 0;
            
        }
        

        if(flag == false){result = 1/result;}
        //if (Math.abs(result) < 1e-16){return 0;}
	    
        return result;
        
    }
}
```
