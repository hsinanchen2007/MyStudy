```csharp
    public class UnionFind
    {
        public int                  max;
        public Dictionary<int, int> dic     = new Dictionary<int, int>();
        public Dictionary<int, int> dicSize = new Dictionary<int, int>();

        public UnionFind(int[] nums)
        {
            max = 1;
            // 初始化
            for (int i = 0; i < nums.Length; i++)
            {
                if (!dic.ContainsKey(nums[i]))
                {
                    dic.Add(nums[i], nums[i]);
                    dicSize.Add(nums[i], 1);
                }
            }
        }

        /// <summary>
        /// 找到对应的根,并路径压缩
        /// </summary>
        public int Find(int p)
        {
            int root = p;
            // 找到根
            while (root != dic[root])
            {
                root = dic[root];
            }

            // 路径压缩: 几乎完全扁平化的树,
            // 如果p的上级不是root,一级一级查找上去全部修改为根
            while (p != root)
            {
                int temp = dic[p];
                dic[p] = root;
                p      = temp;
            }

            return root;
        }

        /// <summary>
        /// 比较2个点的根是否相同
        /// </summary>
        public bool Connected(int p, int q)
        {
            return Find(p) == Find(q);
        }

        /// <summary>
        /// 将q集合的根设置为p
        /// </summary>
        public void Union(int p, int q)
        {
            int rootP = Find(p);
            int rootQ = Find(q);
            if (rootP == rootQ)
                return;
            
            dic[rootQ]     =  rootP;
            dicSize[rootP] += dicSize[rootQ];

            max = Math.Max(max, dicSize[rootP]);
        }
    }

    // 并查集解法
    public int LongestConsecutive(int[] nums)
    {
        if (nums == null || nums.Length == 0)
            return 0;

        UnionFind uf = new UnionFind(nums);
        for (int i = 0; i < nums.Length; i++)
        {
            if (uf.dic.ContainsKey(nums[i] - 1))
                uf.Union(nums[i] - 1, nums[i]);
        }

        return uf.max;
    }

    // 哈希表和线性空间的构造解法
    public int LongestConsecutive2(int[] nums)
    {
        // 存放元素, 连续个数
        Dictionary<int, int> dic = new Dictionary<int, int>();
        int                  max = 0;

        for (int i = 0; i < nums.Length; i++)
        {
            if (dic.ContainsKey(nums[i]))
                continue;

            // 比当前值小一的连续序列中的个数
            int left   = dic.GetValueOrDefault(nums[i] - 1, 0);
            // 比当前值大一的连续序列中的个数
            int right  = dic.GetValueOrDefault(nums[i] + 1, 0);
            int length = left + 1 + right;
            max = Math.Max(max, length);

            // 把当前值加入字典
            dic.Add(nums[i], -1);
            // 维护连续序列的左右边界的个数值
            dic[nums[i] - left]  = length;
            dic[nums[i] + right] = length;
        }

        return max;
    }

```
