### 解题思路
此处撰写解题思路
采用哈希表,统计每个元素出现的次数,超过了半数,返回这个元素值.
### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
       unordered_map<int,int> m; 
        for(int i=0; i< nums.size(); i++)
        {
            if(m.find(nums[i])==m.end()) m.insert({nums[i], 1});  //如果没有在表中出现过,则插入新的键和值
            else    m[nums[i]] ++;  //出现过,则统计值+1
            if(m[nums[i]] > nums.size()/2)  return nums[i]; 
        }
        return -1;

    }
};
```