### 解题思路
f[i] 表示 前i个数的和，前i个数，下标为i-1
所以求i-j为：f[j+1] - f[i]

### 代码

```cpp
class NumArray {
public:
    vector<int> f;
    NumArray(vector<int>& nums) {
        f = vector<int>(nums.size()+1, 0);
        for (int k=1; k<=nums.size(); ++k) {
            f[k] = f[k-1] + nums[k-1];
        }
    }
    
    int sumRange(int i, int j) {
        return f[j+1]-f[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
```