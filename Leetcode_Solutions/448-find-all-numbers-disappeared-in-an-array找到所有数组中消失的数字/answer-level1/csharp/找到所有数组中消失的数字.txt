**思路：** 数组内的元素范围为(1,nums.length),所以如果不缺的话，正好能和数组的下标对应上。遍历数组，把对应元素值-1下标的元素置为复数，最后再遍历一次，找到所有元素为正数的值，然后+1添加到结果数组中。
```
public IList<int> FindDisappearedNumbers(int[] nums)
        {
            var result = new List<int>();

            for (int i = 0; i < nums.Length; i++)
            {
                int newIndex = Math.Abs(nums[i]) - 1;
                if (nums[newIndex] > 0)
                {
                    nums[newIndex] = -1 * nums[newIndex];
                }
            }

            for (int i = 0; i < nums.Length; i++)
            {
                if (nums[i] > 0)
                {
                    result.Add(i + 1);
                }
            }

            return result;
        }
```
