直接上代码
int mySqrt(int x)

{
    if(!x)return x;
    double x0;
    int x1=x;
    x0=x;
    while(1)
    {
        x0=0.5*x0+0.5*((double) x/x0);
        if((int)x0==x1)
            break;
        x1=(int)x0;
            
    }
    return x1;

}
