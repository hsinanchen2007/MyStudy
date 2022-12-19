### 解题思路
前缀和

### 代码

```cpp
class NumArray {
public:
    vector<int> presum;
    vector<int> newnums;

    NumArray(vector<int> &nums)
    {
        newnums = nums;

        presum = vector<int>(nums.size() + 1, 0);

        for (int i = 1; i < presum.size(); i++) {
            presum[i] = presum[i - 1] + newnums[i - 1];
        }
    }

    void update(int i, int val)
    {
        newnums[i] = val;
        for (int j = i+1; j < presum.size(); j++) {
            presum[j] = presum[j - 1] + newnums[j - 1];
        }
    }

    int sumRange(int i, int j)
    {
        return presum[j + 1] - presum[i];
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
```