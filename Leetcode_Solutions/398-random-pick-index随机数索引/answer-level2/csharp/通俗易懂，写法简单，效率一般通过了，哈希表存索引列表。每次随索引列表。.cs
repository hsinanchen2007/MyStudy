 Dictionary<int, List<int>> dic = new Dictionary<int, List<int>>();
        public Solution(int[] nums)
        {
            for(int i=0;i<nums.Length;i++)
            {
                if (dic.ContainsKey(nums[i]) == false)
                    dic.Add(nums[i], new List<int>() { i });
                else
                    dic[nums[i]].Add(i);
            }
        }

        public int Pick(int target)
        {
            List<int> lst = dic[target];
            byte[] buffer = Guid.NewGuid().ToByteArray();
            int iSeed = BitConverter.ToInt32(buffer, 0);
            Random rd = new Random(iSeed);
            int rand = rd.Next(0, lst.Count);//左闭右开
            return lst.ElementAt(rand);
        }