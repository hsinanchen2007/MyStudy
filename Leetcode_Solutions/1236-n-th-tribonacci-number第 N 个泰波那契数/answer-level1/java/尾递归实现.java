```
class Solution {
    public int tribonacci(int n) {
        return fobo(n,0,1,1);
    }
    public int fobo(int n,int l1,int l2,int cur ){   
            if(n==0) return l1;
            if(n==1) return l2;
            if(n==2) return cur;
            return fobo(n-1,l2,cur,l1+l2+cur);
    }
}
```
