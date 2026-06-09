### 解题思路
对迭代器进行操作，若等于val删除，否则加一进行下一个判断

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator index = nums.begin();
        while(index != nums.end())
        {
            if (*index == val)
            {
                nums.erase(index);
            }else
                index++;
        }
        return nums.size();
    }
};
```