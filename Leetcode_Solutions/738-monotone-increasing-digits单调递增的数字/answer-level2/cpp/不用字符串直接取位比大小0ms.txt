```
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        for(int i=1;N/i/10!=0;i*=10){//很丑的代码
            if(N/i%10<N/i/10%10){
                N=N-N%(i*10)-1;
            }
        }
    return N;
    }
};
```

