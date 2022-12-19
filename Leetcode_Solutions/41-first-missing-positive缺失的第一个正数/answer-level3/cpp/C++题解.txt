![屏幕快照 2019-08-08 下午2.48.12.png](https://pic.leetcode-cn.com/d81fc6994f767515c4b516402fbbe6c8651b5747487da3f1db2679f549235f9d-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-08-08%20%E4%B8%8B%E5%8D%882.48.12.png)


思路：先对数组排序，分三类情况讨论：
1. 长度为0；排序后最大的元素还是非正；数组中缺少1；都返回1；
2. 线性搜索，从第一个数开始判断，若当前数为正，且下一个数跳跃时，返回当前数+1；
3. 当到末尾时仍然不满足，说明数组连续，此时，返回末尾数+1。

```
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        
        if(len == 0 || nums[len-1] <= 0 || find(nums.begin(), nums.end(), 1) == nums.end())
            return 1;

        int i;
        for(i = 0; i < len-1; i++) {
            if(nums[i] > 0 && nums[i+1]-nums[i] > 1)
                return nums[i]+1;
        }
        
        return nums[len-1]+1;
    }
};
```
