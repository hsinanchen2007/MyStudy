### 代码

```cpp
class Solution {
public:
    static bool cmp(const pair<int, int>& p, const pair<int, int>& q){
        return p.second > q.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        vector<int> res;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]] += 1;
        }
        vector<pair<int,int>> vt(mp.begin(), mp.end());
        sort(vt.begin(), vt.end(), cmp);
        for(vector<pair<int, int>>::iterator iter=vt.begin(); iter<vt.begin()+k; iter++){
            res.push_back(iter->first);
        }
        return res;
    }
};
```