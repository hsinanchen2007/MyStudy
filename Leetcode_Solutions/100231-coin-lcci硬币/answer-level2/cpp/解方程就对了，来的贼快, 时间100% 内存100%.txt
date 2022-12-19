求解：
n = 25*i + 10*j + 5*k + l  s.t. i,j,k,l 均为非负整数

```c++
for i={0,1,...,n/25}
    for j={0,1,... (n-i*25)/10}
        for k={0,1,...,(n-i*25-j*10)/5}
            ans += 1
化简一下
for i={0,1,...,n/25}
    for j={0,1,... (n-i*25)/10}
        ans += (n/5-5*i-j*2)+1
再次化简
for i={0,1,...,n/25}
    jmax = (n-i*25)/10
    ans += (jmax+1)*(n/5-5*i-jmax*2+1);
```
下面是代码啦
```c++
class Solution {
public:
    int waysToChange(int n) {
        const int C = 1000000007;
        long long N = n;
        int res = 0;
        for(int i=0; i<=n/25; ++i){
            long long jmax = (n-i*25)/10;
            auto t = (jmax+1)*(N/5-5*i-jmax+1);
            res = (res + t) % C;
        }
        return res;
    }
};
```
