```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> tmp;
        int size = nums.size();
        k = k % size;
        //保存后k位
        for (int i = size - k; i < size; i++)
        {
            tmp.push_back(nums[i]);
        }
        //后移前size - k 位
        for (int i = size -1 ; i >= k; i--)
        {
            nums[i] = nums[i - k];
            
        }
        //恢复保存的后k位到前k位
        for (int i = 0; i < k; i++)
        {
            nums[i] = tmp[i];
        }
    }
};
```