### 解题思路
map 的key是从小到大排列，value记录在nums中的下标, value+1也是排名。通过辅助的len记录剩余num个数，也作为排名的标识，并且需要修改。

### 代码

```cpp
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int len = nums.size();
        vector<string> res(len);
        map<int, int> hashmap; // map key从小到大排列
        for(int i=0;i<nums.size();i++){
            hashmap[nums[i]] = i;
        }

        for(auto it:hashmap){
            if(len == 1){
                res[it.second] = "Gold Medal";
            }
            else if(len == 2){
                res[it.second] = "Silver Medal";
                len --;
            }
            else if(len == 3){
                res[it.second] = "Bronze Medal";
                len--;
            }
            else{
                res[it.second] = to_string(len--);
            } 
        }
        return res;

    }
};
```