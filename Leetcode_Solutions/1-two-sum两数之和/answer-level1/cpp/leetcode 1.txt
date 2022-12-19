### 解题思路
一开始身为菜鸟的我当然是使用两重循环，判断两个数组元素之和是否等于target，但这种做法时间复杂度为O(N*N)，后来搜索了一下，发现有大佬使用了unorder_map，底层由哈希表实现，它虽然是无序的，但查找效率比map更加高效；其用法和map相同；
### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i;
        unordered_map <int,int> m;
        for(i=0;i<nums.size();i++)  {
                if(m.count(target-nums[i]))   //m.count(key)判断key是否存在于m中，返回值为0或1
                    return {m[target-nums[i]],i};
                m[nums[i]]=i;
        }
    return {};
    }
};