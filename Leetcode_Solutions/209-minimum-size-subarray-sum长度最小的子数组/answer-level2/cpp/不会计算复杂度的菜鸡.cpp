### 解题思路
此处撰写解题思路
以下是我的思路：
1.从下标0累加至下标n。
2.若下标n处值小于s则返回0。
3.找寻第一个满足>=s的下标位置i。
    3.1自下标0（j)处开始,nums[i]-nums[j]直至 不满足>=s的条件，记录长度。
    3.2递加i直至数组结尾，并重复3.1。
### 代码

```cpp
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        for (int i = 1; i < nums.size(); ++i)
        {
            nums[i] += nums[i - 1];
        }
        if (nums.size() == 0 || nums.back() < s)
        {
            return 0;
        }
        else
        {
            int Size = nums.size();
            int index_1;
            int min_length = 0;
            for (index_1 = 0; index_1 < nums.size(); ++index_1)
            {
                ++min_length;
                if (nums[index_1] >= s && index_1 != nums.size() - 1)
                {
                    break;
                }
            }
            index_1 -= (index_1 == nums.size() ? 1 : 0);
            for (int i = index_1,j=0; i < nums.size(); ++i)
            {
                for (; j < i; ++j)
                {
                    if (nums[i] - nums[j] >= s)
                    {
                        min_length = std::min(min_length, i - (j==0?-1:j));
                    }
                    else
                    {
                        break;
                    }
                }
            }
            return min_length;
        }

        return 0;
    }
};
```