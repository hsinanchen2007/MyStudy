```
class Solution {
    public int tribonacci(int n) {
        if(n==0||n==1||n==2)
            return n==0?0:1;
        return getResult(n,0,1,1);
    }

    int getResult(int n,int a,int b,int c){
        if(n==2)
            return c;
        return getResult(n-1,b,c,a+b+c);
    }
}
```
递归