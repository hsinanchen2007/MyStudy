
char * addBinary(char * a, char * b){
    int len1=strlen(a);
    int len2=strlen(b);
    int j=0;
    int n=1;
    int stepin = 0;
    
    int maxlen=len1>len2?len1:len2;
    int minlen=len1>len2?len2:len1;
    
    char *sum=(char *)malloc(sizeof(char)*(maxlen+2));
    for(j=0;j<(maxlen+1);j++)
    {
    	sum[j]='0';
	}
    sum[maxlen+1]='\0';
    
    for(n=1;n<=minlen;n++)
    {
        sum[maxlen+1-n] = (a[len1-n]-'0' + b[len2-n]-'0' + stepin)%2 + '0';
        stepin = (a[len1-n]-'0' + b[len2-n]-'0' + stepin )/2;
    }
    
    for(n=minlen+1;n<=maxlen;n++)
    {
        if(len1>len2)
        {
            sum[maxlen+1-n] = (a[len1-n]-'0' + stepin)%2+'0';         
            stepin = (a[len1-n]-'0' + stepin )/2;
        }
        else
        {
            sum[maxlen+1-n] = (b[len2-n]-'0' + stepin)%2 + '0';
            stepin = (b[len2-n]-'0' + stepin )/2;            
        }     
    }
    if(stepin==0)
    {
        sum++;
    }
    else
    {
        sum[0]=stepin + '0';  
    }
    return sum;
}