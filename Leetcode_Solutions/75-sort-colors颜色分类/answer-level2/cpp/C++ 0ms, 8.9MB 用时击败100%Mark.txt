### 解题思路
桶排序

![image.png](https://pic.leetcode-cn.com/4de738e5151e35bf42ec8b0998586a2b1fadc02ce460f430d792ec51073f19ef-image.png)

### 代码

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt[3];
        cnt[0] = cnt[1] = cnt[2] = 0;
        for(int i = 0; i < nums.size(); i ++)
        {
            cnt[nums[i]] ++;
        }
        int now = 0;
        for(int i = 0; i < 3; i ++)
        {
            for(int j = 1; j <= cnt[i]; j ++)
                nums[now + j - 1] = i;
            now += cnt[i];
        }
    }
};
```