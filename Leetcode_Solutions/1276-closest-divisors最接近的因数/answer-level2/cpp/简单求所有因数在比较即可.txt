找出所有num+1和num+2的因数再求因数差即可。例如n=8,因数有1，2，4，8，则求$min_{i=1,2,4,8}{ abs(8/i - i) }$
就行了.

```cpp
class Solution {
public:
    int different=INT_MAX;
    vector<int>res={0,0};
    vector<int> closestDivisors(int num) {
        findfactor(num+1);
        findfactor(num+2);
        return res;
    }
    void findfactor(int n){
        int sqr=sqrt(n);
        for(int i=1;i<=sqr;++i){
            if(n%i==0){
                int diff = abs(n/i - i);
                if(different>diff){
                    different = diff;
                    res[0]=i,res[1]=n/i;
                }
            }
        }
    }
};
```