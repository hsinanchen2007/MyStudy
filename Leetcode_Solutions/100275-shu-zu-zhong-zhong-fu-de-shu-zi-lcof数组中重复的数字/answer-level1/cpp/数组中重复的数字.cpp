### 解题思路
三种方法：
1、用map记录数字出现次数,超过1则返回；
2、抽屉原理+换位排序trick(注意只能在这种数组元素值在数组长度范围内的情况用)，一旦出现位置被占则返回；
3、快排+遍历查看重复

### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> num_map;
        for (auto num : nums) {
            num_map[num]++;
            if (num_map[num] > 1) {
                return num;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i) {
                if (nums[i] == nums[nums[i]])
                    return nums[i];
                swap(nums[i], nums[nums[i]]);
            }
        }
        return -1;
    }
};

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        fast_rank(0, nums.size()-1, nums);
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i+1])
                return nums[i];
        }
        return -1;
    }
    void fast_rank(int left, int right, vector<int>& nums) {
        if (left >= right)
            return;
        int i = left, j = right, base = nums[left];
        while (i < j) {
            while (nums[j] >= base && i < j) j--;
            while (nums[i] <= base && i < j) i++;
            if (i < j) {
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[left], nums[i]);
        fast_rank(left, i-1, nums);
        fast_rank(i+1, right, nums);
    }
};
```