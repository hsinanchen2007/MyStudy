### 解题思路
1、二分查找是否有对应target的Index ---(时间复杂度O(lgn));
2、根据该Index，向左右拓展查找对应上下限Index
3、塞入vecor后返回

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size() - 1;
        int index = INT_MIN;
        while (begin <= end) {
            int medium = (begin + end) / 2;
            if (nums[medium] > target) {
                end = medium - 1;
            } else if (nums[medium] < target){
                begin = medium + 1;
            } else {
                index = medium;
                break;
            }
        }
        vector<int> vec;
        if (index == INT_MIN) {
            vec = {-1, -1};
            return vec;
        }
        int beginIndex = index;
        int endIndex = index;
        while (beginIndex - 1 >= 0 && nums[beginIndex - 1] == target) {
            beginIndex--;
        }
        vec.push_back(beginIndex);
        while (endIndex + 1 < nums.size() && nums[endIndex + 1] == target) {
            endIndex++;
        }
        vec.push_back(endIndex);
        return vec;
    }
};
```