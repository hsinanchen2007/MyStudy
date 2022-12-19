寻找数组上下边界，设为[n,m]，则理想情况下，元素个数等于m-n+1；若使用m-n+1个桶存储m-n+1个元素，理想情况每个桶有且只有一个元素。
若存在某个桶含有多个元素，则最大间距在该桶以及相邻两桶元素之中。进一步定位，最大间距是前一桶的最大值与当前桶最小值的差值；或是后一桶的最小元素与当前桶的最大值的差值。
最大间距必然在相邻桶之间出现，不会落入单个桶内！遍历所有桶，求相邻桶之间的间距，为最大间距。
前面为理想情况下的推断，对于给定数组，选择合适的桶个数与桶大小，进行桶排序。这里选择(m-n)/(size-1)作为桶大小s，桶个数为(m-n)/s+1.
```
class Solution {
    struct Bucket{
        int minv, maxv;
        bool used;
        Bucket(int n=INT_MAX, int m=INT_MIN, bool u=false):minv(n),maxv(m),used(u){}
    };
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        const auto min_max=minmax_element(nums.begin(),nums.end());
        const int n=*min_max.first, m=*min_max.second;      // min, max
        const long s=max(1L,(0L+m-n)/((long)nums.size()-1));// bucket size
        vector<Bucket> buckets((0L+m-n)/s+1);
        for(const auto &num:nums){
            const long i=(0L+num-n)/s;
            buckets[i]={min(num,buckets[i].minv),max(num,buckets[i].maxv),true};
        }
        long gap=0, prev_max=n;
        for(const auto &b:buckets){
            if(!b.used) continue;
            gap=max(gap,b.minv-prev_max);
            prev_max=b.maxv;
        }
        return gap;
    }
};
```