```
class Solution {
    public int fib(int N) {
        if(N==0){
            return 0;
        }
        if(N<=2){
            return 1;
        }
        int first = 1,second =1;
        int res =0;
        for(int i=3;i<=N;i++){
            res = first +second;
            first = second;
            second = res;
        }
        return res;
    }
}
```
