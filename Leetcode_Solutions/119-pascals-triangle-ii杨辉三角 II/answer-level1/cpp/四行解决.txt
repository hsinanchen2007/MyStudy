多项式系数定理，具体百度。
```
class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> v(n+1,1);
        for(int f=n, i=0; i++<n/2; f=(long)f*(n-i)/(i+1))
            v[i]=v[n-i]=f;
        return v;
    }
};
```
