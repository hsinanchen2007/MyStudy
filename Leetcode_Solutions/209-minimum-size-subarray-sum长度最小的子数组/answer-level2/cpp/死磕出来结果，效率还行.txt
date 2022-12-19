
```cpp
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r = 0, sum = 0;
        int len = nums.size();
        if (len == 0)
            return 0;
        int min = len;

        //l <= r: 4 [1,4,4]
        while (l <= r && r < len){
            while (r < len && sum + nums[r] < s){
                sum += nums[r++];
            }
            //3 [1,1]
            if (r - l == len)
                return 0;
            if (r - l  + 1 < min)
                min = r - l + 1;
            sum -= nums[l++];
        }
        return min;
    }
};
```