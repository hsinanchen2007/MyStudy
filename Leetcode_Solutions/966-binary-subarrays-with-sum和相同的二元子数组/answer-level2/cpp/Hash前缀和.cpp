- 依次向后遍历，记录下数组开头到当前元素的和`sum`，
- 更新`res+=m[sum-S]`（`m[sum-S]`表示在此之前`sum-S`出现的个数，换一句话就是必然有`m[sum-S]`个子数组和为`S`，说不清，自己走一遍代码就很好理解了）
- 最后加上前缀和为`S`的数目

```
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int res=0,sum=0;
        unordered_map<int,int>m;
        for(auto i:A){
            sum+=i;
            res+=m[sum-S];
            m[sum]++;
        }
        res+=m[S];
        return res;
    }
};
```

个人网站：[liyiping](https://liyiping.cn)
