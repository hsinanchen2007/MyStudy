
递归公式
f(n,m)=(f(n-1,m)+m)%n
当n=2时，退出;
自顶向下
```
class Solution {
public:
    int f(int n,int m)
    {
        
        if(n==2)
        {
           int i=0;
          i=(i+m-1)%n;
         return   !i;
        }
       return (f(n-1,m)+m)%n;
    }
    int lastRemaining(int n, int m)
    {
       return f(n,m);
        
    }
    
};
```
递推解法
我们直接求出n==2时的结果，假设为i,那么n==3时，i=(i+m)%n以此类推。
```
class Solution {
public:
  
    int lastRemaining(int n, int m)
    {
       
        if(n==1)return 0;
         int i=0;
         i=!((i+m-1)%2);  
         for(int j=3;j<=n;j++)
         {
             
            i=(i+m)%j;
         }
         return i;

    }
    
};
```

