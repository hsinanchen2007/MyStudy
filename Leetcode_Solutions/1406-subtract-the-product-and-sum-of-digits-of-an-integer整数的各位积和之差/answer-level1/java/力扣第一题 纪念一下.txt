    public int subtractProductAndSum(int n) {
	    int sum=0, mul=1;
	    while(n>=10){
	    	  mul *= n%10;
	    	  sum += n%10;
	    	  n /= 10;
	    }
	    mul *= n;
	    sum += n;
	    return mul-sum;
    }