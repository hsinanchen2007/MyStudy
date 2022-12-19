catalan数. h(0)=h(1)=1; h(n)=C(2n,n)/(n+1); h(n)=h(n-1)*(4n-2)/(n+1);
```
class Solution {
public:
    int numTrees(int n) {
        long h=1;   // catalan number C(2n,n)/(n+1)
        for(long i=1; i++<n; h=h*(4*i-2)/(i+1));
        return h;
    }
};
```
