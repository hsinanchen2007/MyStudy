对于题目而言，抓住两个关键词：长度为k，连续。
因此我们只需要找出连续的长度为k的子数组，然后整除k就可以了。
因此，整个过程是,先求出[0:k-1]这个子数组，然后删去nums[0],加上nums[k],重复这个过程到尽头就可以了。
```
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0,res=-10000;
        int n=nums.size();
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        res=max(res,sum/k);
        for(int i=k;i<n;i++){
            sum-=nums[i-k];
            sum+=nums[i];
            res=max(res,sum/k);
        }
        return res;
    }
};
```
