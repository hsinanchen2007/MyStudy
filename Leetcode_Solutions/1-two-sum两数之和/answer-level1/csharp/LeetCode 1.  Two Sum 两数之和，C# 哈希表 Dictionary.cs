## 解决方案

解决方案参考了官方题解。

### 方法一：暴力法

看了题目，很自然的就会想到，只要进行两层循环，对所有的数字进行一次相加，当和为target时，将两个值的index返回即可。 所以有了我们的暴力法破解：

        //方法一：暴力法
        public int[] TwoSum(int[] nums, int target)
        {
            for (int i = 0; i < nums.Length; i++)
            {
                for (int j = i + 1; j < nums.Length; j++)
                {
                    if (nums[i] + nums[j] == target)
                    {
                        return new int[] { i, j };
                    }
                }
            }
            return new int[] { 0, 0 };
        }

#### 执行结果

执行结果 通过，执行用时 480ms，内存消耗 29.6MB .

#### 复杂度分析

时间复杂度： O(n^2)

空间复杂度： O(1)


### 方法二：两遍哈希表

对于方法一的时间复杂度 O(n^2) 不太满意，我们需要一种更有效的方法来检查数组中是否存在目标元素。如果存在，我们需要找出它的索引。保持数组中每个元素与其索引相互对应的最好方法是 哈希表。

哈希表 可以 用空间来换取时间，将查找时间从O(n)降低为O(1). 哈希表正是为此目的而构建的，它支持以 *近似* 恒定的时间进行快速查找。 这里用 “近似”来描述，是因为一旦出现冲突，查找用时可能会退化到O(n)。 但只要仔细的挑选哈希函数，在哈希表中进行查找的用时应当被摊销为O(1).

下面代码实现了简单的两次迭代。第一次迭代中，我们将每个元素的值和它的索引添加到表中。然后，在第二次迭代中，我们将检查每个元素所对应的目标元素（target - nums[i]）是否存在于表中。注意，该目标元素不能是 nums[i] 本身！

C#中，哈希表使用 Dictionary 类 来实现。关于C#的 Dictionary 将在下文中更详细的介绍。

在进行特殊情况处理后，代码如下：

      //方法二：两遍哈希表
        public int[] TwoSum(int[] nums, int target)
        {
            Dictionary<int, int> kvs = new Dictionary<int, int>();
            for (int i = 0; i < nums.Length; i++)
            {
                //需要对重复值进行判断；因为结果的唯一，所以若有重复值，且答案中包含了重复值的话，说明必有 重复值*2==target; 否则直接忽略重复值即可
                if (kvs.ContainsKey(nums[i]))
                {
                    if (nums[i] * 2 == target)
                    {
                        return new int[] { i, kvs[nums[i]] };
                    }
                }
                else
                {
                    kvs.Add(nums[i], i);
                }
            }
            for (int i = 0; i < nums.Length; i++)
            {
                int complement = target - nums[i];
                if (kvs.ContainsKey(complement) && kvs[complement] != i)
                {
                    return new int[] { i, kvs[complement] };
                }
            }
            return new int[] { 0, 0 };
        }


#### 执行结果

执行结果 通过，执行用时 280ms，内存消耗 30.6MB .

#### 复杂度分析

时间复杂度： O(n)

空间复杂度： O(n)


### 方法三：一遍哈希表

事实证明，我们可以一次完成。在进行迭代并将元素插入到表中的同时，我们还会回过头来检查表中是否已经存在当前元素所对应的目标元素。如果它存在，那我们已经找到了对应解，并立即将其返回。


       //方法三：一遍哈希表
        public int[] TwoSum(int[] nums, int target)
        {
            Dictionary<int, int> kvs = new Dictionary<int, int>();
            for (int i = 0; i < nums.Length; i++)
            {
                int complement = target - nums[i];
                if (kvs.ContainsKey(complement) && kvs[complement] != i)
                {
                    return new int[] { i, kvs[complement] };
                }
                //需要对重复值进行判断,若结果包含了重复值，则已经被上面给return了；所以此处对于重复值直接忽略
                if (!kvs.ContainsKey(nums[i]))
                {
                    kvs.Add(nums[i], i);
                }
            }
            return new int[] { 0, 0 };
        }


#### 执行结果

执行结果 通过，执行用时 280ms，内存消耗 30.1MB .

#### 复杂度分析

时间复杂度： O(n)

空间复杂度： O(n)



## C# 哈希表 Dictionary

### 什么是哈希表

散列表（Hash table，也叫哈希表），是根据关键码值(Key value)而直接进行访问的数据结构。也就是说，它通过把关键码值映射到表中一个位置来访问记录，以加快查找的速度。这个映射函数叫做散列函数，存放记录的数组叫做散列表。

给定表M，存在函数f(key)，对任意给定的关键字值key，代入函数后若能得到包含该关键字的记录在表中的地址，则称表M为哈希(Hash）表，函数f(key)为哈希(Hash) 函数。

### 基本概念

若关键字为k，则其值存放在f(k)的存储位置上。由此，不需比较便可直接取得所查记录。称这个对应关系f为散列函数，按这个思想建立的表为散列表。

对不同的关键字可能得到同一散列地址，即k1≠k2，而f(k1)=f(k2)，这种现象称为冲突（英语：Collision）。具有相同函数值的关键字对该散列函数来说称做同义词。综上所述，根据散列函数f(k)和处理冲突的方法将一组关键字映射到一个有限的连续的地址集（区间）上，并以关键字在地址集中的“像”作为记录在表中的存储位置，这种表便称为散列表，这一映射过程称为散列造表或散列，所得的存储位置称散列地址。

若对于关键字集合中的任一个关键字，经散列函数映象到地址集合中任何一个地址的概率是相等的，则称此类散列函数为均匀散列函数（Uniform Hash function），这就是使关键字经过散列函数得到一个“随机的地址”，从而减少冲突。

### C# 中的 哈希表

Java 中的 哈希表 使用 HashMap 类 来实现。 在 C# 中，官方的哈希表实现为 Dictionary 。

可能很多读者会想到 Hashtable 类，它也是哈希表，但所有元素都为object类型，不支持泛型。官方推荐使用 Dictionary，可以简单的把它理解为支持泛型的Hashtable.

官方推荐使用 Dictionary 来代替 Hashtable ，具体可以查看下面两篇官方文章。

[https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.hashtable?f1url=https%3A%2F%2Fmsdn.microsoft.com%2Fquery%2Fdev16.query%3FappId%3DDev16IDEF1%26l%3DZH-CN%26k%3Dk(System.Collections.Hashtable);k(DevLang-csharp)%26rd%3Dtrue&view=netframework-4.8](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.hashtable?f1url=https%3A%2F%2Fmsdn.microsoft.com%2Fquery%2Fdev16.query%3FappId%3DDev16IDEF1%26l%3DZH-CN%26k%3Dk(System.Collections.Hashtable);k(DevLang-csharp)%26rd%3Dtrue&view=netframework-4.8)

[https://github.com/dotnet/platform-compat/blob/master/docs/DE0006.md](https://github.com/dotnet/platform-compat/blob/master/docs/DE0006.md)


## 参考资料汇总

[https://leetcode-cn.com/problems/two-sum/solution/liang-shu-zhi-he-by-leetcode-2/https://leetcode-cn.com/problems/two-sum/solution/liang-shu-zhi-he-by-leetcode-2/]()

[https://baike.baidu.com/item/%E5%93%88%E5%B8%8C%E8%A1%A8/5981869?fr=aladdin](https://baike.baidu.com/item/%E5%93%88%E5%B8%8C%E8%A1%A8/5981869?fr=aladdin)

[https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.hashtable?f1url=https%3A%2F%2Fmsdn.microsoft.com%2Fquery%2Fdev16.query%3FappId%3DDev16IDEF1%26l%3DZH-CN%26k%3Dk(System.Collections.Hashtable);k(DevLang-csharp)%26rd%3Dtrue&view=netframework-4.8](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.hashtable?f1url=https%3A%2F%2Fmsdn.microsoft.com%2Fquery%2Fdev16.query%3FappId%3DDev16IDEF1%26l%3DZH-CN%26k%3Dk(System.Collections.Hashtable);k(DevLang-csharp)%26rd%3Dtrue&view=netframework-4.8)

[https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.dictionary-2.-ctor?f1url=https%3A%2F%2Fmsdn.microsoft.com%2Fquery%2Fdev16.query%3FappId%3DDev16IDEF1%26l%3DZH-CN%26k%3Dk(System.Collections.Generic.Dictionary%602.%2523ctor);k(DevLang-csharp)%26rd%3Dtrue&view=netframework-4.8](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.dictionary-2.-ctor?f1url=https%3A%2F%2Fmsdn.microsoft.com%2Fquery%2Fdev16.query%3FappId%3DDev16IDEF1%26l%3DZH-CN%26k%3Dk(System.Collections.Generic.Dictionary%602.%2523ctor);k(DevLang-csharp)%26rd%3Dtrue&view=netframework-4.8)

[https://github.com/dotnet/platform-compat/blob/master/docs/DE0006.md](https://github.com/dotnet/platform-compat/blob/master/docs/DE0006.md)

