### 解题思路
时间复杂度O(nlgn)，尝试了原地重排，但遇到重复数字超过三个时有难度

### 代码

```cpp
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp = nums;
        int n = nums.size(), k = (n + 1) / 2, j = n; 
        sort(tmp.begin(), tmp.end());
        bool bigger = false;
        for (int i = 0; i < n; ++i) {
            nums[i] =(bigger)? tmp[--j] : tmp[--k];
            bigger = !bigger;
        }
    }
};
```