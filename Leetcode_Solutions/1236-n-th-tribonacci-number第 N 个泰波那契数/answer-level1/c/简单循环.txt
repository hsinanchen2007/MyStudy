int tribonacci(int n){
     int f=0;
     if(n==0)
     return 0;
     if(n==1||n==2)
     return 1;
     int a=1;
     int b=1;
     int c=0;
     if(n>=3)
     {
        for(int i=2;i<n;i++)
        {
            f=a+b+c;
            c=b;
            b=a;
            a=f;
        }
     }
return f;
}