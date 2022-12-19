

### 代码

```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> prime;       
        prime.push_back(1);
        int i = 0,j = 0,k = 0;
        int a = n;
        while(a --){
            int s = prime.size();
            for(;i < prime.size();++i)
                if(prime[i]*2 > prime[s-1])break;
            for(;j < prime.size();++j)
                if(prime[j]*3 > prime[s-1])break;
            for(;k < prime.size();++k)
                if(prime[k]*5 > prime[s-1])break;
            int t = min(prime[i]*2, prime[j]*3);
            prime.push_back(min(t, prime[k]*5));
            cout << prime[s] << " ";
        }
        return prime[n-1];
    }
};
```