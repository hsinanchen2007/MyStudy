### 解题思路
1.第一种思路，把0都删掉，记录删除次数，然后在最后补上
2.类似冒泡排序，O(n2)
3.双指针，记录非0元素应该放置的位置，swap
### 代码

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int num = 0;
        auto it = nums.begin();
        while (it != nums.end()) {
            if (*it == 0) {
                it = nums.erase(it);
                num++;
            } else {
                it++;
            }
        }
        while (num-- > 0) {
            nums.push_back(0);
        }
    }
};
```