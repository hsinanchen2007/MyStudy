public static int PivotIndex(int[] nums)
        {
            int sumleft = 0;
            int sumright = 0;
            Dictionary<int, int> dicleft = new Dictionary<int, int>();
            Dictionary<int, int> dicright = new Dictionary<int, int>();
            for (int i = nums.Length - 1; i >= 0; i--)
            {
                sumright += nums[i];
                dicright.Add(i, sumright - nums[i]);
            }
            for(int i=0;i<nums.Length;i++)
            {
                sumleft += nums[i];
                dicleft.Add(i, sumleft - nums[i]);
                if (dicright[i] == dicleft[i]) return i;
            }
            return -1;
        }