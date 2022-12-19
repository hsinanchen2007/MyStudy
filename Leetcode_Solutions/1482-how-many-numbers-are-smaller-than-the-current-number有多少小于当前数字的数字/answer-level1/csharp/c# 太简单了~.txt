参考一下：
 https://blog.csdn.net/us2019/article/details/104846603

```
        public int[] SmallerNumbersThanCurrent(int[] nums)
        {
            //var dic = new Dictionary<char, int>();
            int[] res = new int[nums.Length];
            for (int i = 0; i < nums.Length; i++)
            {
               int tempvalue= getVALUE(i,nums[i], nums);
                res[i] = tempvalue;
            }
            return res;
        }

        private int getVALUE(int id, int value, int[] nums)
        {
            int tempnum = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                if (i!=id && nums[i] < value)
                {
                    tempnum++;
                }
            }
            return tempnum;
        }
```
