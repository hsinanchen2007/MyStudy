# 标题（使用官方提示的桶排序方法，但是测试用例是真的恶心）
```
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size()<2)
            return false;
        if(t<0||k<=0)
            return false;
        if(nums.size()==2)
        {
            long t1=nums[0];
            long t2=nums[1];
            if(abs(t1-t2)<=t)
                return true;
            else
                return false;
        }
        if(t==0)
        {
            unordered_map<int,int> hash_map;
        for(auto i=0;i<nums.size();i++)
        {
            if(hash_map.count(nums[i])==1)
            {
                if(i-hash_map[nums[i]]<=k)
                    return true;
                else
                    hash_map[nums[i]]=i;
            }
            else
                hash_map[nums[i]]=i;
        }
        return false;
        }
        auto index=max_element(nums.begin(),nums.end());
        auto index2=min_element(nums.begin(),nums.end());
        long t1=t;
        long temt=t1+1;
        long tem_index=*index;
        long tem_index2=*index2;
        long bul_num=(tem_index-tem_index2)/temt+1;
        vector<unordered_map<int,int>> vec(bul_num);
        for(auto i=0;i<nums.size();i++)
        {
            if(i>k)
            {
                for(int j=0;j<bul_num;j++)
                {
                    if(vec[j].count(nums[i-k-1])==1)
                        vec[j].erase(nums[i-k-1]);
                }
            }
            if(vec[(nums[i]-tem_index2)/(t1+1)].size()>0)
                return true;
            if((nums[i]-tem_index2)/(t1+1)>=1)
            {
                for(auto j:vec[(nums[i]-tem_index2)/(t1+1)-1])
                {
                    long temj=j.first;
                    long temi=nums[i];
                    if(abs(temj-temi)<=t1)
                        return true;
                }
            }
            if((nums[i]-tem_index2)/(t1+1)<bul_num-1)
            {
                for(auto j:vec[(nums[i]-tem_index2)/(t1+1)+1])
                {
                    long temj=j.first;
                    long temi=nums[i];
                    if(abs(temj-temi)<=t1)
                        return true;
                }
            }
            vec[(nums[i]-tem_index2)/(t1+1)][nums[i]]=i;
        }
        return false;
    }
};
```
