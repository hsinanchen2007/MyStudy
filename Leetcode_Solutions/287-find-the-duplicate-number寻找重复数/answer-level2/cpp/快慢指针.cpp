用快慢指针解，概念可以参考 https://zhuanlan.zhihu.com/p/38521018
这题里面n刚好不能取0，所以可以这样解。如果n可以取0的话，index需要加1，就会比较绕了。
```
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int slow = nums[0];
        int fast = nums[nums[0]];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        int h = 0;
        while (slow != h) {
            h = nums[h];
            slow = nums[slow];
        }
        
        return h;
    }
    
};
```