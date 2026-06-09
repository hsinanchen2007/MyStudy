顺序遍历更新最大值即可

代码：
```
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = nums.size();
        int ans = 0;
        int temp = 0;
        for(int i = 0 ; i < len ; i++) {
            if(nums[i])
                temp++;
            else {
                ans = ans > temp ? ans : temp;
                temp = 0;
            }
        }
        return ans > temp ? ans : temp;
    }
};
```
