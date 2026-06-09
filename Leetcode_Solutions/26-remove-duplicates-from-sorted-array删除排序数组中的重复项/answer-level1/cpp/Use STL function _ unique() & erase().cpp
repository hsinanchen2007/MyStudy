### 解题思路
iterator unique(itr1,itr2) //数组大小不变
iterator erase(itr1,itr2)  //数组大小改变

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator itr1 = nums.begin();
        vector<int>::iterator itr2 = nums.end();
        nums.erase(unique(itr1,itr2),itr2);
        return nums.size();
    }
};
```