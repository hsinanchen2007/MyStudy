```
c#
```
 public int[] TwoSum(int[] nums, int target)
    {

        Hashtable hx = new Hashtable();

        for (int i = 0; i < nums.Length; i++)
        {
            int key = target - nums[i];

            if (hx.Contains(key))
            {

                return new int[] { Convert.ToInt32(hx[key]), i };
 
            }
            if (!hx.Contains(nums[i])){
             hx.Add(nums[i],i);//c#的哈希不能有重复的，所以加个判断，提交就可以过了
            }

        }
        return new int[] { -1, 0 };

    }

}
这样的写法还是没有比c++的快啊，好难
