### 解题思路
抄的代码
 [@ck567](/u/ck567/) 
[@qiyexue](/u/qiyexue/)

搞了快一天了，代码写了删，删了写，不下一千行了。
能想到的着，都用了，还是不行。
最后，抄了一个代码，先过关，再学习！
### 代码

```csharp

    public class Solution
    {
        public IList<IList<int>> ThreeSum(int[] nums)
        {
            //调用数组排序（按从小到大排序）
            Array.Sort(nums);
            //定义一个list，用来包装返回值
            IList<IList<int>> resultList = new List<IList<int>>();

            for (int i = 0; i < nums.Length - 2; i++)
            {
                if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
                {  // 跳过可能重复的答案
                   //定义一个l，用来标记第二个数的下标
                   // r是第二个数的最大值，初始为数组的最后一个元素的下标
                   // 定义一个sum，这样接下来计算就会省很多步
                    int l = i + 1, r = nums.Length - 1, sum = 0 - nums[i];
                    while (l < r)
                    {
                        if (nums[l] + nums[r] == sum)
                        {
                            //如果符合情况，则添加在返回值中
                            resultList.Add(new List<int>() { nums[i], nums[l], nums[r] });
                            //然后继续判断，是否有元素重复
                            while (l < r && nums[l] == nums[l + 1]) l++;
                            while (l < r && nums[r] == nums[r - 1]) r--;
                            l++;
                            r--;
                        }
                        else if (nums[l] + nums[r] < sum)
                        {
                            //如果 nums[l] + nums[r] + num[i] < 0 则说明当前数字相加之和还不够大，需要将指针往后移动
                            // 则前面的指针往后移动一位 遇到重复的跳过
                            while (l < r && nums[l] == nums[l + 1]) l++;   // 跳过重复值
                            l++;
                        }
                        else
                        {
                            //如果 nums[l] + nums[r] + num[i] > 0 则说明当前数字相加之和过大，后面的元素已经不满足条件，
                            // 则后面的指针往前移动一位 遇到重复的跳过
                            while (l < r && nums[r] == nums[r - 1]) r--;
                            r--;
                        }
                    }
                }
            }
            return resultList;
        }
    }
```