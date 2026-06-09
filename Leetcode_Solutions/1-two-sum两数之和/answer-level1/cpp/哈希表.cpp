### 解题思路
此处撰写解题思路
//别人的代码，记个笔记
提前存满哈希表，比边遍历边存快
原因是提前存满可以更快找到，边遍历边存会出现刚开始哈希表里元素少而浪费许多时间。
### 代码
\\m.find(target-nums[i]) != m.end()**注意find用法**
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> m;

        for(int i=0;i<nums.size();i++)
            m[nums[i]] = i;   //向map中添加元素
        
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(target-nums[i]) != m.end() && m[target-nums[i]] != i)//m中存在对应的键值，并且不为i
                return {i,m[target-nums[i]]};
        }
        return {};
    }
};

```