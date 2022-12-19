```
public bool HasAlternatingBits(int n) {
        var count=0;
        var t=n;
        while(t>0){
            t=t&(t-1);
            count++;
        }
        int t1=1;
        int t2=0;
        int tier=2;
        for(var i=1;i<count*2;i++){
            if(i%2==0){
                t1+=tier;
            }
            else{
                t2+=tier;
            }
            tier*=2;
        }
        return n==t1||n==t2;
    }
```
