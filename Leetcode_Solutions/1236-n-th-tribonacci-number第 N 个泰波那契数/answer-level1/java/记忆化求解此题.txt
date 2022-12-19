此题为70爬楼梯以及509斐波那契数的变体。
```
class Solution {
    public int tribonacci(int n) {
    int []a=new int[n+1];
    return tribonacci(1,n,a);    
    }
    public int tribonacci(int i,int n,int []a) {  
   
   if(i>n)return 0;
   if(i==n)return 1;
   if(a[i]>0)return a[i];
   a[i]=tribonacci(i+1,n,a)+tribonacci(i+2,n,a)+tribonacci(i+3,n,a);   
    return a[i];    
    }
}
```
