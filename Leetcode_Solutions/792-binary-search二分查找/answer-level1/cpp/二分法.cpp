### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;      //置区间初值
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) return mid;//找到待查元素
            else if (nums[mid] > target)
                high = mid - 1;     //继续在前半区间进行查找
            else
                low = mid + 1;       //继续在后半区间进行查找
        }
        return -1;//不存在待查元素
    }
};
```