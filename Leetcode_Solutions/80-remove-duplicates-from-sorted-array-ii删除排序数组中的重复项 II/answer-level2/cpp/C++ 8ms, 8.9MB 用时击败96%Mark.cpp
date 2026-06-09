### 解题思路
类似26题思路，直接替换掉无效位。
需要注意的是因为题目要求最多保留两个，因此设置判断符flag，判断目前是否超过2个

![image.png](https://pic.leetcode-cn.com/25f5bd7fa0a8ec456f6ede2dfd749e0b25ba650fbd2b9b6a45e5166c092ca5b9-image.png)

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 特殊情况处理
        if(nums.size() == 0) return 0;
        // k 存放当前有效位数，flag 为判断符，flag为true：当前已经有2个了，flag为false：当前是第1个
        int k = 0;
        bool flag = false;
        for(int i = 1; i < nums.size(); i ++)
        {
            if(nums[i] == nums[k])
            {
                if(flag) continue;
                flag = true;
            }
            else flag = false;
            k ++;
            nums[k] = nums[i];
        }
        // 务必注意这里返回的是新数组的“长度”，因此是 k + 1
        return k + 1;
    }
};
```