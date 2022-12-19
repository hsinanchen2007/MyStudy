
在回溯的时候进行剪枝操作，对下一个进行判断，如果和之前点的值相同就跳过。


    public IList<IList<int>> PermuteUnique(int[] nums) {
      if (nums.Length == 0)
                return new List<IList<int>>();
            List<IList<int>> res = new List<IList<int>>();
            List<int> temp = new List<int>();
            Array.Sort(nums);
            int[] flag = new int[nums.Length];
            for (int i = 0; i < flag.Length; ++i)
                flag[i] = 0;
            fun2(ref res, nums, flag, temp);
            return res;
        }
        public void fun2(ref List<IList<int>> res, int[] nums, int[] flag, List<int> temp)
        {
            if (temp.Count == nums.Length)
            {
                res.Add(new List<int>(temp));
                return;
            }
            for (int i = 0; i < nums.Length;i++)
            {
                if (flag[i] == 1)
                    continue;
                flag[i] = 1;
                temp.Add(nums[i]);
                fun2(ref res, nums, flag, temp);
                temp.RemoveAt(temp.Count - 1);
                flag[i] = 0;
                while(i < nums.Length - 1 && nums[i + 1] == nums[i])
                    i++;
            }

        }
