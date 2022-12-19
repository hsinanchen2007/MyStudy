```
public int BitwiseComplement(int N) {
        if(N==0){
            return 1;
        }
        var n=N;
        var t=0;
        while(n>0){
           n=n>>1; 
           t=(t<<1)+1;
        }
        return N^t;
    }
```
