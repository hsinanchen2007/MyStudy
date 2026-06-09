bool isPalindrome(int x){
    if(x<0) return 0; 
    long int rev=0;
    int op=x; 
    int gw;  
    while(op!=0){
    	gw=op%10;
    	rev*=10;
    	rev+=gw;
    	op/=10;
	}
	if(rev==x) return 1;
	else return 0;	
}