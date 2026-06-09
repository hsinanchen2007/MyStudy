### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator itr1 = nums.begin();
        vector<int>::iterator itr2 = nums.end();
        nums.erase(remove(itr1,itr2,val),itr2);
        return nums.size();
    }
};
```