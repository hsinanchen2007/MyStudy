### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      for(auto it=nums.begin();it!=nums.end();)
    {
        // cout<<*it<<endl;
        if(val==*it)
            it=nums.erase(it);
        else
            it++;
    }
    return nums.size();
    }
};
```