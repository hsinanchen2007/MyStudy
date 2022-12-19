通过第一次提交知道46341^2会超int范围，限制在46339内查找即可...
```
int mySqrt(int x){
    if(x<=1) return x;
    int i=x/2;  
    int j; 
    for(j=1;j<=46339;j++)
    {
        if(j*j==x) 
        {
            break;
            return j;
            
        }
        if(j*j<x&&(j+1)*(j+1)>x) 
        {
            break;
            return j; 
            
        }
    }

    return j;

}
```
