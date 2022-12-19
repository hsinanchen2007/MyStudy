```
class Solution {
public:
    using LL=long long;
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<LL, vector<LL>, greater<LL>> q;
        int c=0;
        LL pre=-1;
        q.push(1);
        while(!q.empty()){
            LL t=q.top();q.pop();
            if(t==pre)continue;
            c++;
            if(c==n){
                return t;
            }
            pre=t;
            for(int i=0;i<primes.size();i++){
                q.push(t*primes[i]);
            }
        }
        return 0;
    }
};
```
