```
bool isPalindrome(int x){
    int Fan = 0,fnum,num,i,len;
    num = x;
    for(len=1,i=x;(int)i/10!=0;len++){
    	i = (int)i/10;
	}
    if(num>=0){
        for(i = 1;x!=0;i++){
            fnum = x%10;
            x = (int)x/10;
			Fan += fnum*pow(10,len-i);
        }
        if(Fan==num)
            return true;
        else
            return false;
    }
    else
        return false;
}
```
