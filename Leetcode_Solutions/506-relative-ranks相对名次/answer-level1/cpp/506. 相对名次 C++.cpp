### 解题思路
1.使用hash_map记录每一个成绩对应的下标。
2.将nums降序排列，前三个为一次为金牌、银牌和铜牌，并根据下标写入result容器中，其余的将名次直接写入result容器中。

### 代码

```cpp
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> result(nums.size());
    unordered_map<int,int> index_save_map;
    unordered_map<int,int>::iterator index_save_map_iter;
    
    
    for(int i = 0;i < nums.size();i++){
        index_save_map[nums[i]] = i;
    }
    
    sort(nums.begin(),nums.end(),greater<int>());
    
    for(int i = 0;i < nums.size();i++){
        index_save_map_iter = index_save_map.find(nums[i]);
        if(i == 0){
            result[index_save_map_iter->second] = "Gold Medal";
        }else if(i == 1){
            result[index_save_map_iter->second] = "Silver Medal";
        }else if(i == 2){
            result[index_save_map_iter->second] = "Bronze Medal";
        }else{
            result[index_save_map_iter->second] = to_string(i + 1);
        }
    }
    
    return result;
    }
};
```