### 解题思路
![image.png](https://pic.leetcode-cn.com/2e4d0c59695dff2395816efe0791ec334388322178f3cf673a103a6b5fa963cb-image.png)


### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        //投票算法
        int len = nums.size();
        if (len == 0) return -1;

        int tmp = nums[0], cnt = 1;
        for (int i = 1; i < len; i++)
        {
            if (nums[i] == tmp) cnt++;
            else cnt--;

            if (cnt == 0) tmp = nums[i], cnt = 1;
        }

        //验证tmp是不是超过一半
        cnt = 0;
        for (auto n : nums)
            if (n == tmp) cnt++;
        return cnt > len / 2 ? tmp : -1;
    }
};
```