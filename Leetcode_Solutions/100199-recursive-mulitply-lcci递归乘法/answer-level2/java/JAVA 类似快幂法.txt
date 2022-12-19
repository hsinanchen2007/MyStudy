```
class Solution {
    public int multiply(int A, int B) {
        if(A==0||B==0) return 0;
        int m=multiply(A/2,B);
        if((A&1)==1){    
            return m+m+B;
        }else{
            return m+m;
        }
    }
}
```
