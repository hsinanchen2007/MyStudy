### 解题思路
１．　先把０移动到最左边
２．　再把２移动到最左边


### 代码

```cpp
class Solution {
public:
    void print(vector<int> &nums) {
        std::cout << "-------------" << std::endl;
        for (int i = 0; i < nums.size(); i++) {
            std::cout << nums[i] << ", ";
        }
        std::cout << std::endl;
    }
    void moveSingleNum(vector<int> &nums, int &left, int &right, int num) {
        while (left <= right) {
            while (left <= right && nums[left] == num) left++;
            while (left <= right && nums[right] != num) right--;
            if (left < right) {
                int tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;
            }
            // print(nums);
        }
    }
    void sortColors(vector<int>& nums) {
        int left = 0, right = (int)nums.size() - 1;
        // move zero to left
        moveSingleNum(nums, left, right, 0);

        right = (int)nums.size() - 1;
        moveSingleNum(nums, left, right, 1);
    }
};
```