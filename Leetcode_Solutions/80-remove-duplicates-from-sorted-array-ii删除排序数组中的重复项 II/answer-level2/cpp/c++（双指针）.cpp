- 思路：
  - 双指针 + 重复值计数
- 时间复杂度：
  - o(n)
- 空间复杂度：
  - o(1)
- 结果:
  - 用时：94%（8ms）
  - 内存：5%
```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int p=1,dup=1,i=1;
        while(i<nums.size()){
            dup = nums[i]==nums[i-1]?dup+1:1;
            if(dup<3) nums[p++]=nums[i++];
            else i++;
        }
        return p;
    }
};
```