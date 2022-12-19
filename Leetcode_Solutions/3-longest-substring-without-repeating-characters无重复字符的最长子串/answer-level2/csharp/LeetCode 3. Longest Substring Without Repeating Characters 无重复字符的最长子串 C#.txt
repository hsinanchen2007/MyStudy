
## 解决方案

按照一般逻辑来思考，可能需要3层循环来实现暴力破解，时间复杂度为O(n^3) ；除了暴力破解外，还可以借助哈希表实现O(n)的解决方案。

笔者为大家整理了一下容易卡住的测试集 供大家参考。

	1.  "a"
	2. ""
	3. "pwwkew"
	4. "dvdf"
	5. "abcd" 
	6. "abcabcbb"

### 方法一 : 暴力法

逐个检查所有的子字符串，看它是否不含有重复的字符。

需要用到3层循环计算，时间复杂度为O(n^3).

C# 代码 :
	
        public int LengthOfLongestSubstring(string s)
        {
            int result = 0;
            int i = 0;
            int j = 0;
            for (; i < s.Length; i++)
            {
                bool breakJ = false;
                for (j = i + 1; j < s.Length; j++)
                {
                    for (int k = i; k < j; k++)
                    {
                        if (s[k] == s[j])
                        {
                            int subResult = j - i;
                            result = subResult > result ? subResult : result;
                            breakJ = true;
                            i = k;
                            break;
                        }
                    }
                    if (breakJ) break;
                }
                if (!breakJ)
                {
                    var subResult = j - i;
                    result = subResult > result ? subResult : result;
                    break;
                }
            }
            return result;
        }

#### 执行结果

执行结果 通过，执行用时 520ms，内存消耗 27.3MB .

#### 复杂度分析

时间复杂度：O(n^3)

空间复杂度：O(1)

#### 思路图解：

以 pwwkew 为例:

![1.png](https://pic.leetcode-cn.com/463f69c41e61bf113b9c7031d77445715f1063a5d863f9da5c5d7678a19f36cb-1.png)

#### 时间复杂度的计算

![2.png](https://pic.leetcode-cn.com/b346120ef6b3d35a255e00b5fad907ef7e93c657b27306c5d4bbbf18a09a723b-2.png)


### 方法二 : 滑动窗口

暴力法非常简单，但它太慢了。那么我们该如何优化它呢？

在暴力法中，我们会反复检查一个子字符串是否含有有重复的字符，但这是没有必要的。如果从索引 i 到 j - 1 之间的子字符串  Sij  已经被检查为没有重复字符。我们只需要检查 s[j] 对应的字符是否已经存在于子字符串 Sij中。

要检查一个字符是否已经在子字符串中，我们可以检查整个子字符串，这将产生一个复杂度为 O(n^2)的算法，但我们可以做得更好。

通过使用 HashSet 作为滑动窗口，我们可以用 O(1) 的时间来完成对字符是否在当前的子字符串中的检查。

滑动窗口是数组/字符串问题中常用的抽象概念。 窗口通常是在数组/字符串中由开始和结束索引定义的一系列元素的集合，即 [i, j)（左闭，右开）。而滑动窗口是可以将两个边界向某一方向“滑动”的窗口。例如，我们将 [i, j) 向右滑动 11 个元素，则它将变为 [i+1, j+1)（左闭，右开）。

回到我们的问题，我们使用 HashSet 将字符存储在当前窗口 [i, j)（最初 j = i）中。 然后我们向右侧滑动索引 j，如果它不在 HashSet 中，我们会继续滑动 j。直到 s[j] 已经存在于 HashSet 中。此时，得到一个局部解为 s[i]  到 s[j-1] ,然后我们将 滑动窗口的左侧向右移动，也就是 增加i，直到 HashSet 中没有重复值位置。之后继续将滑动窗口像右侧滑动，增加 j  。循环以上步骤，取所有局部解的最大值，就得到我们的答案。

        
        public int LengthOfLongestSubstring(string s)
        {
            int n = s.Length;
            HashSet<char> set = new HashSet<char>();
            int result = 0;
            int i = 0;
            int j = 0;
            while (i < n && j < n)
            {
                if (set.Contains(s[j]))
                {
                    set.Remove(s[i]);
                    i++;
                }
                else
                {
                    set.Add(s[j]);
                    j++;
                    result = Math.Max(result, j - i);
                }
            }
            return result;
        }


#### 执行结果

执行结果 通过，执行用时 104ms，内存消耗 25.1MB .

#### 复杂度分析

时间复杂度：O(2n) = O(n) ,最糟的情况下，每个字符将同时被 i 和 j 访问，即每个字符被访问2次。

空间复杂度：O(min(m,n)) ，与之前的方法相同。滑动窗口法需要 O(k) 的空间，其中 k 表示 Set 的大小。而 Set 的大小取决于字符串 n 的大小以及字符集 / 字母 m 的大小。


#### 思路图解：

以 pwwkew 为例:

![3.png](https://pic.leetcode-cn.com/3d3b6eeddcd3801384b0ccc81bd0c85c85d2a29f8e3deae3c23b3777ef8f84e6-3.png)


### 方法三 : 优化的滑动窗口

对于方法二，可以发现有一个地方可以优化的。方法二图解的第三步到第四步，i 只向右移动了一格；即发生冲突时，i每次只会向右移动一格，这导致了在最糟糕的情况下，I 和 j 几乎将 s 遍历了一遍，共2n个步骤。

事实上，它可以被优化为仅需要n个步骤。我们可以定义字符到索引的映射，而不是使用集合来判断一个字符是否存在。 当我们找到重复的字符时，我们可以立即跳过该窗口。即对于方法二图解的第四步来说，可以先找到与 s[j]重复的字符的下标index，让窗口左侧移动到 index+1 的位置即可。

C# 代码中，我们不用之前的 HashSet ， 而是改用 Dictionary:

       
        public int LengthOfLongestSubstring(string s)
        {
            int n = s.Length;
            Dictionary<char, int> map = new Dictionary<char, int>();
            int result = 0;
            int i = 0;
            int j = 0;
            while (j < n)
            {
                if (map.ContainsKey(s[j]))
                {
                    var oldJ = map[s[j]];
                    i = Math.Max(oldJ + 1, i);
                    map[s[j]] = j;
                }
                else
                {
                    map.Add(s[j], j);
                }
                j++;
                result = Math.Max(result, j - i);
            }
            return result;
        }

#### 执行结果

执行结果 通过，执行用时 88ms，内存消耗 25.1MB .

#### 复杂度分析

时间复杂度：O(n) , 索引 j 将会迭代 n 次，而索引 i 会在发生冲突时，立即跳到无冲突的位置。

空间复杂度：O(min(m,n)) ，与之前的方法相同。


## 参考资料汇总

[https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)

[https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-by-leetcod/](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-by-leetcod/)

[https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.hashset-1?view=netframework-4.8](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.hashset-1?view=netframework-4.8)

[https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.dictionary-2?view=netframework-4.8](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.dictionary-2?view=netframework-4.8)

[https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.hashtable?view=netframework-4.8](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.hashtable?view=netframework-4.8)

