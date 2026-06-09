### 解题思路
执行用时 :16 ms, 在所有 C++ 提交中击败了92.59% 的用户
内存消耗 :21.4 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> data;
        for(int i=0;i<nums.size();i++){
            if(data.find(nums[i])!=data.end()){
                data[nums[i]] += 1;
            }else{
                data[nums[i]] = 1;
            }
        }
        for(auto it=data.begin();it!=data.end();it++){
            if(it->second>nums.size()/2) return it->first;
        }
        return -1;
    }
};
```