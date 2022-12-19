设a为记录最大值的数组，则当前位置的最大值a[i] = max((nums[i]+a[i-2]),a[i-1])。
（应用时不需要定义数组，仅需记录在前两个位置时的最大值即可，既代码中的a和b）
```
class Solution {
public:
    int massage(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        int a = nums[0],b = max(nums[0],nums[1]),temp = 0;
        for(int i =2;i<nums.size();i++){
            temp = b;
            b = max(b,a+nums[i]);
            a = temp;
        }
        return b;
    }
};

```
执行用时：0ms，内存消耗：7.8MB

