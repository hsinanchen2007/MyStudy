我的思路是找到给定的vector容器当前状态下的最大值和最小值（因为其他数值通过加减K得到的数字，在变化后的数组中如果是最大值或者最小值，那么变化前的最大值和最小值，通过加减K一样可以做到），然后用最大值减去最小值，如果这个差值大于两倍的K，最后的差值就是Max-Min-2*K，否则就是0。

```
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) 
    {
        if(A.size()==1) return 0;
        auto i=A.begin();
        auto j=i+1;
        auto n=i+1;
        for(;i!=A.end();i++)
        {
            if(*j<*i) j=i;
            if(*n>*i) n=i;
        }
        int max=*j;
        int min=*n;
        if((max-min)>2*K) return (max-min-2*K);
        else return 0;


    }
};
```
