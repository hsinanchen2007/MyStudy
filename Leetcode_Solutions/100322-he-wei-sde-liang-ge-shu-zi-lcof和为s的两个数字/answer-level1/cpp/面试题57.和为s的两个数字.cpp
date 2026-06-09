### 解题思路
- 核心要点：hashset保存数字，一遍即可过
- 执行用时：864 ms, 在所有 C++ 提交中击败了5.61%的用户
- 内存消耗：143.6 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int>uset;
        for(auto i:nums){
            int res=target-i;
            if(uset.find(res)==uset.end()){
                uset.insert(i);
            }
            else{
                return {res,i};
            }
        }
        return {};
    }
};
```