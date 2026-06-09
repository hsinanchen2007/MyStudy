        public int SingleNumber(int[] nums)
        {
            if (nums.Length == 1)
            {
                return nums[0];
            }

            Dictionary<int, int> b= new Dictionary<int, int>();
            foreach (var item in nums) // save all numbers to key and mark appear times as value
            {
                if (b.Keys.Contains(item))
                {
                    b[item]++;
                }
                else
                {
                    b.Add(item, 1);
                }                
            }

            foreach (var key in b.Keys) // find first value is 1
            {
                if (b[key] == 1)
                    return key;
            }

            return 0;
        }