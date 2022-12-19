三次反转，先整体反转，再根据k值进行前后两部分反转

注意，k可能是大于数组大小的，需要对其取余

代码：
```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
```
