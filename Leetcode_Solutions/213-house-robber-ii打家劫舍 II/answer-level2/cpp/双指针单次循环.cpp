### 解题思路
双指针同时遍历，一次循环就好了。
### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int pre1=0, cur1=0;
        int pre2=0, cur2=0;

        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];

        for(int i=0, j=1; i<nums.size()-1; i++, j++){
            int temp1 = cur1;
            int temp2 = cur2;
            cur1 = max(pre1+nums[i], cur1);
            cur2 = max(pre2+nums[j], cur2);
            pre1 = temp1;
            pre2 = temp2;
        }

        return max(cur1, cur2);
    }
};
```