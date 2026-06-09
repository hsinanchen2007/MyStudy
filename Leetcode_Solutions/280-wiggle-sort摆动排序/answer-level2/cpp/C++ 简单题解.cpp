```
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        for (int i = 1; i + 1 < N; i += 2) {
            swap(nums[i], nums[i + 1]);
        }
    }
};
```
![image.png](https://pic.leetcode-cn.com/09b05159989bfc973046a2c6f591a690e03c2566eb59efe33df5581295fe1179-image.png)
