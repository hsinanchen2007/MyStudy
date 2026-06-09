```
Dictionary<int,int> dict=new Dictionary<int,int>();
    public int Fib(int N) {
        if(dict.ContainsKey(N)){
            return dict[N];
        }
        if(N==0){
            return 0;
        }
        if(N==1){
            return 1;
        }
        var res=Fib(N-1)+Fib(N-2);
        dict[N]=res;
        return res;    
    }
```
