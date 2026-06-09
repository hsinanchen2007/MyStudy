
回溯法

```cpp
class Solution {
private:
    vector< vector<int> > res;
    vector<bool> used;

    // nums: 没有重复数字的序列
    // index: [0, index) 已处理，index待处理
    // p: 已找到的[0, index)的一个排列
    // example: nums=[2,3,4,5]  index=2(将要确定第三位)  p：已经确定了前两位比如[3，2]（任意两个数都有可能）
    void fintPermute(const vector<int>& nums, int index, vector<int> &p) 
    {

        if (p.size() == nums.size()) {
            res.push_back(p);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                p.push_back(nums[i]);
                fintPermute(nums, index+1, p);  
                p.pop_back();  // 记得 push 进 p 的 nums[i] 在 findPermute 完成后要 pop 掉，始终只有一个p
                used[i] = false;
            }
        }
    }

public:
    vector< vector<int> > permute(vector<int>& nums) {  //[2,3,4]
        
        if (nums.size() == 0)
            return res;
        
        used = vector<bool> (nums.size(), false);
        vector<int> p; //  始终只有一个p
        fintPermute(nums, 0, p);
        return res;
        
    }
};
```