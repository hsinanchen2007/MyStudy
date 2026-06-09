# 思路
先用c++自带sort函数对nums进行排序，然后枚举nums中的元素(nums[i])，此时只需
**nums[j] + nums[k] == -nums[i];**
即可满足题目要求。而找到j和k的方法就是利用双指针来实现。其中，左指针指在i的下一个位置，右指针指在数组的末尾，当左右指针指向的数相加小于等于目标值，右移一位左指针，否则左移一位右指针。


# 正确性分析
初次看到别的题解里的这种思路时，感觉这个双指针很精髓，但是不明白为什么这么做是对的，下面是我的一点理解：
首先，**我们约定合法的j, k始终都包含于闭区间[left, right]内**，那么最终一定会找到一组解。

当左右指针指向的数相加小于目标值，我们利用反证法，先假设left指向的数就是最终的解中的一个数，那么对于这个left，我们需要找到一个比right更大的数x，才有可能使其和等于目标值。而这个数x在闭区间[left, right]之外，根据我们的约定，x不可能是最终解中的一个，产生了矛盾，因此我们的假设不成立，即left指向的数不是j, k当中的一个，因此可以将区间缩小到[left + 1, right]内。

反之，左右指针指向的数相加大于目标值，那么说明j, k位于闭区间[left, right - 1]之内，通过不断缩小区间的长度，最终会出现两种结果：找到一组left和right，使其和等于目标值；或者是区间长度缩小到0，这意味着对于本次枚举的元素nums[i], 不存在满足条件的j, k，那么接着枚举下一个nums[i]。

不过，这里有一个问题，找到了一组满足条件的[left, right]并不意味着本次循环的结束，因为[left, right]中，还可能有**不止一组满足条件的i, k**，那么下一步我们该如何移动指针呢？
只从满足相加的和等于目标值这一个限定条件考虑，无论是左移还是右移指针，都满足条件，也不会漏解；但是，别忘了题目中的另一个要求：**答案中不可以包含重复的三元组。**那么该怎么保证三个数不出现重复呢？

首先可以简化一下问题，因为当nums[i]和nums[j] (或者nums[k])唯一确定，那么nums[k] (或者nums[j])也就唯一确定了。我们只用确保nums[i]和nums[j] (或者nums[k])不出现重复。

nums[i]的去重是比较容易的，假如当前nums[i]与nums[i-1]相等，因为nums[i]对应的[left, right]包含于nums[i-1]对应[left, right]当中，因此由nums[i]构成的所有解也必然包含在由nums[i-1]构成的所有解中，因此可以continue:
```
if (i > 0) //防止i - 1越界
{
    if (nums[i] == nums[i - 1]) //重复枚举
    {
        continue;
    }
}
```
而nums[j] 的去重同理。根据nums[left] + nums[right] == target时移动指针的策略，假如我们右移左指针，只需保证nums[j] != nums[j - 1]即可（但是nums[j]是可以等于nums[i]的，因此要特判）；假如我们左移右指针，只需保证nums[k] != nums[k + 1]即可 （nums[k]可以等于nums[i]，也需要特判）。

另外，注意nums长度小于3时，i, j, k的枚举可能会出现各种越界，需要特判一下。

个人认为，本题重点在边界条件和去重方面。

完整算法包含一个n*log(n)的排序和n^2的双指针，时间复杂度为n^2。

最后附上完整代码
```
class Solution
{
public:
    vector<vector<int> > threeSum(vector<int>& nums)
    {
        vector<vector<int> > ans;
        if (nums.size() < 3) //特判
        {
            return ans;
        }
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i > 0) //防止i - 1越界
            {
                if (nums[i] == nums[i - 1]) //重复枚举
                {
                    continue;
                }
            }
            int targetNum = 0 - nums[i];
            vector<int>::iterator left = nums.begin() + i + 1;
            vector<int>::iterator right = nums.end() - 1;
            while (left < right)
            {
                if (*left + *right == targetNum)
                {
                    if (left == nums.begin() + i + 1)
                    {
                        ans.push_back({nums[i], *left, *right});
                    }
                    else if (*left != *(left - 1)) //判重
                    {
                        ans.push_back({nums[i], *left, *right});
                    }
                }
                if (*left + *right <= targetNum)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        return ans;
    }
};
```
