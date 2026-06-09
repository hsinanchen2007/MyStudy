```c# []
public int[] DiStringMatch(string S) {
        var tail=S.Length;
        var head=0;
        var res=new int[tail+1];
        for(var i=0;i<S.Length;i++){
            if(S[i]=='I'){
               res[i]=head;
               head++; 
            }else{
                res[i]=tail;
                tail--;
            }
        }
        res[S.Length]=tail;
        return res;
    }
```

