* 利用标准库<algorithm>里的find()函数进行查找
* 通过一次遍历，遍历的同时，从当前位置的下一个位置进行查找
* 因为是查找是否有满足长度不大于k的，所以如果找到，第一个就停止，进行下标长度比较
* 如果没找到，则进行下一次遍历

```cpp
bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        for (int i = 0; i < nums.size(); i++) {
            int len = 0;
            auto it = find(nums.begin() + i + 1, nums.end(), nums[i]);
            if (it != nums.end()) {
                len = it - nums.begin()-i;
                if (len <= k) return true;
            }
        }
        return false;
    }
```