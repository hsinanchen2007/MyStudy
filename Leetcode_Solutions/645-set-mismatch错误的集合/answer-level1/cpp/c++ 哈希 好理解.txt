### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(int i = 0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        vector<int> res;
        for(auto it = hash.begin();it != hash.end();it++){
            if(it->second >= 2){
                res.push_back(it->first);
            }
        }
        for(int i = 1;i<= nums.size();i++){
            if(hash[i] == 0){
                res.push_back(i);      
            }
        }
        return res;
    }
};
```