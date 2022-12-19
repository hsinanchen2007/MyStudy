
## 解决方案

首先我们会想到使用 具现化 来解决题目，使用二维数组 将变换后的 Z字形图案 保存下来，然后按行读取拼接 得到最终答案；之后 我们发现 不需要将 Z字形图案 具现化到二维数组，也能实现按行读取拼接得到答案。仔细分析Z字形图案的特点，可以得出结论 ”每一行字符的原始下标有一定的特征“，于是我们可以利用该特征来进一步优化算法。

借助下图再来分析一下题目。红色箭头 表示字符串走向，蓝色框 将 字符们 分组，Z字形图案是由多个分组 组成的，最后一个分组可能会缺几个字符。下文以及代码中，给定字符串s的长度将用n表示，每组字符数将用m表示，由题已知 行数为 numRows ，我们可以推出 m = numRows + (numRows-2) =   2 * numRows - 2 .  


![1.png](https://pic.leetcode-cn.com/b0da2635ff8a886aa216b7a66b50a9736c64a1f0650129df652388af2fecb263-1.png)



下面我们依次来介绍4种解法。

### 方法一 :  具现大法

首先我们new一个二维数组p，然后将Z字形图案生成到p种，最后按行读取p并拼接所有字符，即为最终结果。

p的行数为numRows，我们可以根据已知条件求出p的列数 numCols= Math.Ceiling(n/m) * (numRows-1) , 其中Math.Ceiling(n/m)表示s一共可以分成几组，(numRows-1)表示每组的列数。

参考代码如下：


        public string Convert(string s, int numRows)
        {
            if (numRows == 1) return s;
            int n = s.Length;
            int m = 2 * numRows - 2; //每组几个数
            int numCols = (int)(Math.Ceiling(n * 1.0 / m)) * (numRows - 1);
            char[,] p = new char[numRows, numCols];

            int i = 0, j = 0;
            int index = 0;
            while (index < n)
            {
                while (i < numRows)
                {
                    if (index == n) break;
                    p[i++, j] = s[index++];
                }
                i--;
                while (i > 0)
                {
                    if (index == n) break;
                    p[--i, ++j] = s[index++];
                }
                i++;
            }

            StringBuilder result = new StringBuilder();
            for (i = 0; i < numRows; i++)
            {
                for (j = 0; j < numCols; j++)
                {
                    //Console.Write(p[i, j]);
                    //Console.Write(" ");
                    if (p[i, j] != '\0')
                    {
                        result.Append(p[i, j]);
                    }
                }
                //Console.WriteLine();
            }
            return result.ToString();
        }

#### 执行结果

执行结果 通过。 执行用时： 168ms, 内存消耗 42.3M

#### 复杂度分析

**时间复杂度：O(numRows*n)**

这里时间复杂度忽略系数后也可以认为是 O(n),但为了与后面的方法进行对比，故这里将系数也加上。

**空间复杂度：O(numRows*n)**

二维数组p的行数为numRows，列数numCols= n/m *numRows ，而 m=2*numRows-2, 故p的空间复杂度也认为是行数乘以列数约为  O(numsRows*n).

### 方法二 : 根据走向按行排序

该方法参考了官方题解一。

回顾一下上文方法一：方法一中，我们将Z字型图案给具现化到二维数组，这占用了额外的空间，并且在拼接结果时，有很多空位也需要判断，也占用了额外的时间。

我们已经分析过Z字形图案的走向：先下，再右上，再下，再右上。。。 在给定的行数内，重复这个规律。 在向下走的时候，列数不变，行数不断增加；在向右上走的时候，行数减小，列数增加。得到这个规律后，我们不再需要具现化到二维数组，而只需要利用这个规律来依次判断s[i]属于哪一行即可。最后按行排序拼接，得到最终结果。

示例代码如下：

      public string Convert(string s, int numRows)
        {
            if (numRows == 1) return s;
            int n = s.Length;

            List<List<char>> ps = new List<List<char>>();

            for (int i = 0; i < numRows; i++)
            {
                ps.Add(new List<char>());
            }

            bool goingDown = false;
            int curRow = 0;

            for (int i = 0; i < n; i++)
            {
                ps[curRow].Add(s[i]);
                if (curRow == 0 || curRow == numRows - 1)
                    goingDown = !goingDown;
                curRow += goingDown ? 1 : -1;
            }

            StringBuilder result = new StringBuilder();
            for (int i = 0; i < numRows; i++)
                ps[i].ForEach(x => result.Append(x));
            return result.ToString();
        }


#### 执行结果

执行结果 通过。 执行用时： 104ms, 内存消耗 27M

#### 复杂度分析

**时间复杂度：O(n)**

对s的每个字符判断属于第几行 时间复杂度为 O(n) ； 因ps中共有n个字符，所以将ps组合为result的时间复杂度为 O(n), 两者为并列关系，故总复杂度为 O(2n) = O(n).

**空间复杂度：O(n)**

ps里面的元素总个数为n，result总元素个数为n，故空间复杂度为 O(2n) =O(n)


### 方法三 : 根据下标按行排序

该方法与方法二类似，方法二为根据Z字形走向来按行排序，而方法三为根据下标特征来按行排序。

我们仍以题目给的字符串为例来分析下标与Z字形的关系。 当 numRows=3时，m=4，第0行的字符的下标对m取余后余数为0，第1行的字符下标对m的余数为1或3，第2行的字符下标对m的余数为2； 当numRows=4时，m=6, 第0行的字符下标对m余数为0，第一行为1或5，第二行为2或4，第三行为3。

![2.png](https://pic.leetcode-cn.com/35ff1e0d327dcd4703a8441d366cd512df7458ab80a8cc941a4593083f7129f5-2.png)





分析一下可得：若 s[i]%m=0,则s[i]在第0行； 若 s[i]%m=1 或 s[i]%m=m-1 ，则s[i]在第1行，若 s[i]%m=2 或 s[i]%m=m-2 时，s[i]在第2行。所以我们得到了s中 字符的下标 与 所在Z字的行数的关系：  **若 s[i]%m=r 或 s[i]%m=m-r ，则 s[i] 在第 r 行**。

根据上面的推论，我们可以写出如下代码：

        public string Convert(string s, int numRows)
        {
            if (numRows == 1) return s;
            int n = s.Length;
            int m = 2 * numRows - 2; //每组几个数

            List<List<int>> ps = new List<List<int>>();

            for (int i = 0; i < numRows; i++)
            {
                ps.Add(new List<int>());
            }

            for (int i = 0; i < n; i++)
            {
                int a = i % m;//余数
                int r = a > m / 2 ? (m - a) : a;//表示第i个字符应该在第几行
                ps[r].Add(i);//将i添加到对应行的list
            }

            StringBuilder result = new StringBuilder();

            for (int i = 0; i < numRows; i++)
            {
                ps[i].ForEach(x => result.Append(s[x]));
            }
            return result.ToString();
        }


#### 执行结果

执行结果 通过。 执行用时： 104ms, 内存消耗 27M

#### 复杂度分析

**时间复杂度：O(n)**

对s的每个字符判断属于第几行 时间复杂度为 O(n) ； 因ps中共有n个字符，所以将ps组合为result的时间复杂度为 O(n), 两者为并列关系，故总复杂度为 O(2n) = O(n).

**空间复杂度：O(n)**

ps里面的元素总个数为n，result总元素个数为n，故空间复杂度为 O(2n) =O(n)


### 方法四: 根据结果下标按行访问

该方法参考了官方题解二。

方法二和方法三中，我们都是先依次推算出s[i]所在的行，然后再组合出result的；但是分析后可以发现，我们可以依次计算出result结果中的字符在s中的下标。如果直接根据result字符在s的下标来访问s，并将对应的字符加入到result中，就可以省去判断s[i]所在行的步骤（相对于方法二和三），这将使得时间复杂度和空间复杂度从 O(2n) 提升为 O(n) .

我们使用k来表示当前分组（从0开始），则第 k 个分组的第0行的字符在s中的下标为 km,最后一行的字符在s中的下标为 km+m/2 , 中间行 第i行的字符有2个，下标分别为 km+i 和 (k+1)m - i . 读者可以通过下图来验证这些结论。

![2.png](https://pic.leetcode-cn.com/7f4d96c8900de56c56cafff112c30a66498e3df1bb6fad7d817f734b4dc7d795-2.png)




所以，我们可以先访问第一行的字符，依次将它添加到result；再访问第二行的字符，再第三行。。。 这样一行一行的将字符添加到result。 示例代码如下：

        public string Convert(string s, int numRows)
        {
            // 行 0 的索引为 km
            // 行 numRows-1 索引为 km + m/2
            // 中间行的 i 的索引为 km+i,(k+1)m-i
            if (numRows == 1) return s;
            int n = s.Length;
            int m = 2 * numRows - 2; //每组几个数

            StringBuilder result = new StringBuilder();

            for (int i = 0; i < numRows; i++)
            {
                for (int j = 0; j + i < n; j += m)
                {
                    result.Append(s[j + i]);
                    if (i != 0 && i != numRows - 1 && j + m - i < n)
                    {
                        result.Append(s[j + m - i]);
                    }
                }
            }
            return result.ToString();
        }


#### 执行结果

执行结果 通过。 执行用时： 104ms, 内存消耗 26.1M

#### 复杂度分析

**时间复杂度：O(n)**

将s中的n个字符加入到result，所以时间复杂度为 O(n).

**空间复杂度：O(n)**

result空间复杂度为 O(n).


## 参考资料汇总

题目：

[https://leetcode-cn.com/problems/zigzag-conversion/](https://leetcode-cn.com/problems/zigzag-conversion/)

官方题解：

[https://leetcode-cn.com/problems/zigzag-conversion/solution/z-zi-xing-bian-huan-by-leetcode/](https://leetcode-cn.com/problems/zigzag-conversion/solution/z-zi-xing-bian-huan-by-leetcode/)
