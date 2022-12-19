由于数字范围都在0~n-1之内，考虑利用一个大小和nums相同的布尔数组记录某个数字是否出现过，如果当前数字没有出现过（对应flag为false），将对应flag标记为true；如果当前数字对应flag为true，说明出现过，将其输出。
目前为止100%
![image.png](https://pic.leetcode-cn.com/1d19c5dec246a939e336ca0836a072822aa7b176bb842072b7e83938d80794e7-image.png)

```c++
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        bool flag[nums.size()];
        memset(flag, false, sizeof(flag));
        for(int i = 0; i < nums.size(); i++)
            if(flag[nums[i]])
                return nums[i];
            else
                flag[nums[i]] = true;
        return -1;
    }
};
```
