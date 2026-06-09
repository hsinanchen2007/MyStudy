### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/34659154e9df169dbd177d20ffe520c717c483dc6613509de7e494774aedcb05-image.png)

### 代码

```cpp
class Solution
{
public:
    
    int removeDuplicates(vector<int> &nums)
    {
        int pos1 = 0, pos2 = 1;
        int lenth = nums.size();
        if (lenth <= 1)
        {
            return lenth;
        }
        while (pos2 < lenth)
        {
            int index = 0;
            if (nums[pos2] != nums[pos1])
            {
                nums[pos1+1] = nums[pos2];
                pos1++;
            }
            pos2++;
        }
        return pos1+1;
    }
};
```