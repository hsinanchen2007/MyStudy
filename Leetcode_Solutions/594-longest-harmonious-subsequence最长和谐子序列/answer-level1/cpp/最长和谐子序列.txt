
哈希表
-----------
```cpp
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int curMax=0;
        unordered_map<int,int> hashMap;
        //统计出现频率
        for(auto key:nums){
            hashMap[key]++;
        }
        //如果存在key+1值就，将他们频率相加，比较出最大值
        // mp.find(x)!=mp.end()
        // mp.count(x)!=0
        for(auto it:hashMap){
            if(hashMap.count(it.first+1)){
                curMax=max(curMax,it.second+hashMap[it.first+1]);
            }
        }
        return curMax;
    }
};



```