public static int DominantIndex(int[] nums)
        {
            if (nums.Length == 1) return 0;
            List<int> lst = nums.ToList();
            int bignumber = lst.Max();
            int bigindex = lst.IndexOf(lst.First(p => p == bignumber));
            lst.RemoveAt(bigindex);
            int[] newnums = lst.ToArray();
            Array.Sort(newnums);
            for (int i = newnums.Length - 1; i >= 0; i--)
            {
                if (bignumber < newnums[i] * 2)
                {
                    return -1;
                }
            }
            return bigindex;
        }