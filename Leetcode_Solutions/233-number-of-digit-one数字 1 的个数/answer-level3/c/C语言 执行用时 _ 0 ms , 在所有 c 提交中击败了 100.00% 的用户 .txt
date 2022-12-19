int countDigitOne(int n){
    int i,k=0,x,y,m=n;//x表示位数，y表示10^x
    for(x=0,y=1;m!=0;m/=10)
    {
        i=m%10;
        if(i==1) k+=y/10*x+1-m*y+n;
        else if(i>1) k+=y+y/10*x*i;
        x++;
        if(y!=1000000000)y*=10;
    }
    return k;
}