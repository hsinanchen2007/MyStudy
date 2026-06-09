```
/// <summary>
    /// 移动零
    /// 把不为0的数字依次放在数组前,并记录此时指针的索引,将索引后面的元素覆盖为0
    /// </summary>
    /// <param name="nums"></param>
    public void MoveZeroes(int[] nums)
    {
        if (nums==null || nums.Length==0)
        {
            return;
        }
        int point = 0;//指针记录不为0的数字索引位置
        for (int i = 0; i < nums.Length; i++)
        {
            //当前数字不为0
            if (nums[i]!=0)
            {
                nums[point++] = nums[i];//当前数字放在前面,并向后移动指针
            }
        }
        //后面的元素补零
        for (int i = point; i < nums.Length; i++)
        {
            nums[i] = 0;
        }
    }
```