### 解题思路
利用erase函数删除元素

封装函数真的好用！！！

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        for (auto it = nums.begin(); it != nums.end();) {
            if (*it == val) it = nums.erase(it);
            else  it++;
        }
        return nums.size();
    }
};
```