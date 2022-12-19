空间换时间，应该没有nlogn吧。。。

```
class Solution {
public:
    struct compByValue//排序比较函数
    {
      bool operator()(pair<int, int>& lhs, pair<int, int>& rhs)
      {
        return lhs.second > rhs.second;
      }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>res(k);
        unordered_map<int,int>map;
        for(auto i:nums){//map记录
            map[i]++;
        }
        vector<pair<int,int>>temp(map.begin(),map.end());
        sort(temp.begin(),temp.end(),compByValue());//排序
        for(int i=0;i<k;i++){//取前k个值
            res[i]=temp[i].first;
        }
        return res;
    }
};
```
