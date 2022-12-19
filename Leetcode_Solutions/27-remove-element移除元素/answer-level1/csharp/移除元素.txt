**思路：** 双指针
```
public int RemoveElement(int[] nums, int val)
        {
            int currentIndex = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                if (nums[i] != val)
                {
                    nums[currentIndex] = nums[i];
                    currentIndex++;
                }
            }
            //注意不要写成currentIndex + 1，多用例子试一试自己的代码
            return currentIndex;
        }
```
