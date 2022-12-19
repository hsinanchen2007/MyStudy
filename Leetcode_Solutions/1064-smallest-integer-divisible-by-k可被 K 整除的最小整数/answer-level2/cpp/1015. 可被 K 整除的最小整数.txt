```
class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if(K%2==0||K%5==0)return -1;
        int n=1%K;
        int cnt=1;
        while(n)
        {
            n=(n*10+1)%K;
            ++cnt;
        }
        return cnt;
    }
};
```
