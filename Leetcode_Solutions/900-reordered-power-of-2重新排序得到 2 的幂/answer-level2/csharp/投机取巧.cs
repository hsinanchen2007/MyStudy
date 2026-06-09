
先把2的幂列出来，各自给出一个数组表示0-9数字的个数。
和参数N的个数数组比较。效率自然快，不用全排列。

private static Dictionary<int, int[]> GetHashmap()
        {
            int y = 0;
            double x = 0;
            Dictionary<int, int[]> dic = new Dictionary<int, int[]>();
            while (x < Math.Pow(10, 9))
            {
                x = Math.Pow(2, y);
                if (x < Math.Pow(10, 9))
                {
                    int[] arr = Generate10((int)x);
                    dic.Add((int)x, arr);
                }
                y++;
            }
            return dic;
        }

        private static int[] Generate10(int val)
        {
            int[] arr = new int[10];
            for (int j = 0; j < val.ToString().Length; j++)
                arr[val.ToString()[j] - '0'] += 1;
            return arr;
        }
        public static bool ReorderedPowerOf2(int N)
        {
           int[] Narr = Generate10(N);
           Dictionary<int, int[]> dic = GetHashmap();
           KeyValuePair<int,int[]> kvp = dic.Where(p => Enumerable.SequenceEqual(p.Value, Narr)).FirstOrDefault();
           if(kvp.Key==0 && kvp.Value==null)
               return false;
           return true;
        }