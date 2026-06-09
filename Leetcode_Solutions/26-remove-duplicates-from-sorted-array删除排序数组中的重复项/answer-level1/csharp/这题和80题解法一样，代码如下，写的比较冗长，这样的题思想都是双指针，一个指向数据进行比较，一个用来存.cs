第26题
![1.png](https://pic.leetcode-cn.com/9cb771031dc97e903ef5eb83e9f692d20ca6da01aab1ca48a02a0be1dd096017-1.png)


第80题

public static int RemoveDuplicates2(int[] nums)
        {
            int count = 0;
            int i = 0;
            for (int j = 0; j < nums.Length; j++)
            {
                if (j == 0)
                {
                    nums[i++] = nums[j];
                    count = 1;
                }
                else
                {
                    if (count == 1)
                    {
                        if (nums[j] == nums[j - 1])
                        {
                            count = 2;
                            nums[i++] = nums[j];
                        }
                        else
                            nums[i++] = nums[j];
                    }
                    else if (count == 2)
                    {
                        if (nums[j] != nums[j - 1])
                        {
                            count = 1;
                            nums[i++] = nums[j];
                        }
                        else
                        {
                            int k;
                            for (k = j + 1; k < nums.Length; k++)
                            {
                                if (nums[k] != nums[j])
                                {
                                    nums[i++] = nums[k];
                                    count = 1;
                                    j = k;
                                    break;
                                }
                            }
                            if (k == nums.Length) return i;
                        }
                    }
                }
            }
            return i;
        }