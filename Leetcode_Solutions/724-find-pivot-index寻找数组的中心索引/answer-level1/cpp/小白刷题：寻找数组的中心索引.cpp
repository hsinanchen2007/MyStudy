先求数组元素和sum，然后遍历索引左侧元素和left，应满足2*left+flag=sum

代码：
```
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int len = nums.size();
        int sum = 0;
        for(int i = 0; i < len; i++)
            sum += nums[i];
        int left = 0;
        int flag = 0;
        while(flag < len) {
            if(left * 2 + nums[flag] == sum)
                return flag;
            else {
                left += nums[flag];
                flag++;
            }
        }
        return -1;
    }
};
```
