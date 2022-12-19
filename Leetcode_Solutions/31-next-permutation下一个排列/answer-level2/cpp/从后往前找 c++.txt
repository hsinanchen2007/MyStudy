### 解题思路
首先从后往前找出 非递增序的第一个数字，
例如  2 4 3 9 8 1 ， 这里我们找到的是3，

然后再从最右侧开始找，第一个比3大的数字，这个是8， 然后将3和8互换位置，然后将3后的所有数字reverse即可

### 代码

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1 || nums.size() == 0) {
            return;
        }

        int last = nums.size()-2;
        while (last >= 0) {
            if (nums[last] >= nums[last+1]) {
                last--;
            } else {
                break;
            }
        }
        if (last < 0) {
            reverse(nums.begin(), nums.end()); 

        } else {
            int front = nums.size() - 1;
            while (front > last) {
                if (nums[front] > nums[last]) {
                    swap(nums[front], nums[last]);
                    break;
                }
                front--;
            }
            reverse(nums.begin()+last+1, nums.end());
        }

    }
};
```