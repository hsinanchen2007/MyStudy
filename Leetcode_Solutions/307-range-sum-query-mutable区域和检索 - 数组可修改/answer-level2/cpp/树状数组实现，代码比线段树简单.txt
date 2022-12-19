树状数组实现的重点在于lowbit(int idx)。
对于节点idx:
    idx + lowbit(idx) 是它的父节点；
    idx - lowbit(idx) 是它的相同父节点的前一个节点；

```
class NumArray {
public:
    NumArray(vector<int>& nums) 
    : treeNums_(nums.size() + 1, 0)
    {
        for (size_t i = 0; i < nums.size(); ++i) {
            update(i, nums[i]);
        }
    }
    
    void update(int i, int val) {
        int idx = i + 1;
        int num = getPrefixSum(idx) - getPrefixSum(idx - 1);
        int diff = val - num;
        
        for (; idx < treeNums_.size(); idx += lowbit(idx)) {
            treeNums_[idx] += diff;
        }
    }
    
    int sumRange(int i, int j) {
        return getPrefixSum(j + 1) - getPrefixSum(i);
    }
private:
    vector<int> treeNums_;
    // 可以将nums也存起来，空间换取时间，以减少update时候计算num的时间开销。
    
    inline int lowbit(int idx) {
        return idx & (-idx);
    }
    
    inline int getPrefixSum(int idx) {
        int prefix = 0;
        
        for (; idx > 0; idx -= lowbit(idx)) {
            prefix += treeNums_[idx];
        }
        
        return prefix;
    }
};
```
