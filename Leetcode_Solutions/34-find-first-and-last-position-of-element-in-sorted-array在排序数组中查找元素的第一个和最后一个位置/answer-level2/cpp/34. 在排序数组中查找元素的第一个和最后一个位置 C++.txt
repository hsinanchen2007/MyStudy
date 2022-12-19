### 解题思路
二分法

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2);
        res[0] = -1;
        res[1] = -1;
        if(nums.empty()) return res;      // 如果nums为空，返回0
        int len = nums.size();  // len保存nums长度
        int left = 0;   
        int right = len - 1;
        int findIndex = -1;  // 标记target的位置，没有找到为-1

        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] > target){
                right = mid - 1;
            }
            else if(nums[mid] == target){
                findIndex = mid;
                break;
            }
            else{
                left = mid + 1;
            }
        }

        if(findIndex == -1) return res;

        // 查找左右两边
        left = findIndex;
        right = findIndex;
        // cout << findIndex << endl;
        while(left >= 0 && nums[left] == target) --left;
        while(right < len && nums[right] == target) ++right;

        // 此时left已经是target左边界-1， right是右边界+1,所以出现次数应该为(right + 1) - (left - 1) + 1
        res[0] = left + 1;
        res[1] = right - 1;
        return res;
    }
};
```