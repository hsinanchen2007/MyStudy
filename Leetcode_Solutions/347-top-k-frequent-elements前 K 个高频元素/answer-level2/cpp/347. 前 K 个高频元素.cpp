

```cpp
class Solution {
public:
    //return true表示不交换，前面的大于后的时候不交换，降序排列
    static bool cmp(pair<int,int> a,pair<int,int> b){
        return a.second>b.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //建立频率哈希表
        unordered_map<int,int>hash;
        for(int i=0;i<nums.size();++i){
            hash[nums[i]]++;
        }
        //根据频率降序排序
        vector<pair<int,int> > arr(hash.begin(),hash.end());
        sort(arr.begin(),arr.end(),cmp);
        
        //返回前k个的key值
        vector<int>res;
        for(int i=0;i<k;++i){
            res.push_back(arr[i].first);
        }
        return res;
    }
};
```