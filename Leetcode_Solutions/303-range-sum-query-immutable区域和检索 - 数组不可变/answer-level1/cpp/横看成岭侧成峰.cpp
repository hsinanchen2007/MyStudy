### 解题思路

问题有些简单，思路明显，起初觉得除了暴力方法，也没觉得非得整一些大的方法。但耗时要332ms（暴力法）。后续可以再补充动态规划相关的内容。

### 代码

```cpp
class NumArray {
public:
    NumArray(vector<int>& nums):nums(nums) {
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        for(int s = i; s <= j; s++) {
            sum += nums[s];
        }

        return sum;
    }

private:
    vector<int> nums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
```