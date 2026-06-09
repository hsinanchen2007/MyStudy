double myPow(double x, long n){
	if(x==1.00000) return x;
	if(x==-1.00000){
		if(n%2==0) return 1.0;
		else return -1.0;
	}
    double result=x;
    long pre=0;
    double arr[100];
	int k=0,flage=0;
	if(n==0) 
		result=1;
	else{
		if(n<0) {
			n=-n;flage=1;
		}
    	while(n>0){
	    	if(n==1){
	    		arr[k]=x;break;
			} 
			else {
				result=x;
				for(long i=2;i<=n;i=i*2){
		        	result*=result;pre=i;
	        	}    
			}                  
	        arr[k++]=result;n=n-pre;
		}  
		if(n==0) k--;
		result=1;
		for(int j=0;j<=k;j++)
			result*=arr[j] ;
		if(flage==1) result=1.0/result; 
	} 
    return result;
}