**思路1：** 利用hash表存储每个元素的count。
```
public int MajorityElement(int[] nums)
        {
            Dictionary<int, int> dict = new Dictionary<int, int>();
            int countTreshold = nums.Length / 2;
            for (int i = 0; i < nums.Length; i++)
            {
                if (dict.ContainsKey(nums[i]))
                {
                    dict[nums[i]]++;
                }
                else
                {
                    dict.Add(nums[i], 1);
                }
                if (dict[nums[i]] > countTreshold)
                {
                    return nums[i];
                }
            }

            return -1;
        }
```
