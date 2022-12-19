## 解决方案

首先想到的是将两个有序数组合并为一个有序数组，再根据长度取中间值，计算中位数即可；另外，还可以 不真正合并数组的情况下找寻中位数； 但是上面两种方式思想是相同的，均为合并成一个数组后根据长度找中位数，达不到要求的 O(log(m + n)) 的 时间复杂度要求。根据 LeetCode 题解中 windliang 提供的方法“第k小数”方法，时间复杂度可以达到题目要求；根据 LeetCode 官方题解中提供的方法，时间复杂度可以达到 O( log( min(m,n))  ) ,比题目要求的时间复杂度还要小。下面我们依次来介绍这几种方法。

### 方法一 : 合并List根据长度找中位数

new 一个 List , 并将 nums1 和 nums2 都添加到list 中，然后进行排序。对于排序后的 list, 根据长度计算出中位数的index，进而计算出最终结果。

假设合并后的list长度为13，则从小到大第7个数字为中位数，resultIndex=6;

假设合并后的list长度为14，则从小到大第7，8个数字的平均值为中位数，index 分别为 6，7，此时resultIndex =7,resultIndex-1 =6 , 结果为 ( list[resultIndex-1] + list[resultIndex] ) / 2.0 ;
	
        public double FindMedianSortedArrays(int[] nums1, int[] nums2)
        {
            int m = nums1.Length;
            int n = nums2.Length;
            int len = m + n;
            var resultIndex = len / 2;
            List<int> list = new List<int>(nums1);
            list.AddRange(nums2);
            list.Sort();
            if (len % 2 == 0)
            {
                return (list[resultIndex - 1] + list[resultIndex]) / 2.0;
            }
            else
            {
                return list[resultIndex];
            }
        }

#### 执行结果

执行结果 通过，执行用时 156ms，内存消耗 27.2MB .

#### 复杂度分析

**时间复杂度：O( (m+n)(1+log(m+n) ))**

将长度为m,n的两个数组添加到list，复杂度分别为常数级的m和n ；list.Sort()的复杂度根据官方文档可得为 (m+n)log(m+n)，所以该方法时间复杂度为 O( m+n+(m+n)log(m+n) ) = O( (m+n)(1+log(m+n) ))

**空间复杂度：O(m+n)**

使用list的长度为m+n.

### 方法二 : 归并排序后根据长度找中位数

方法一使用了list.Sort() 方法，可以对list进行排序，但是，若题目给出的nums1 和 nums2 是无序数组，使用 list.Sort() 才算是 物有所用。 本题中 nums1 和 nums2 是有序数组，所以使用 list.Sort() 有写 杀鸡用宰牛刀的感觉，换句话说，这里面存在着效率的浪费。我们可以利用 【nums1 和 nums2 是有序数组】 这个条件，来精简我们的排序。

     public double FindMedianSortedArrays(int[] nums1, int[] nums2)
        {
            // nums1 与 nums2 有序添加到list中
            List<int> list = new List<int>();
            int i = 0, j = 0;
            int m = nums1.Length;
            int n = nums2.Length;
            int len = m + n;
            var resultIndex = len / 2;

            while (i < m && j < n)
            {
                if (nums1[i] < nums2[j])
                    list.Add(nums1[i++]);
                else
                    list.Add(nums2[j++]);
            }
            while (i < m) list.Add(nums1[i++]);
            while (j < n) list.Add(nums2[j++]);

            if (len % 2 == 0)
            {
                return (list[resultIndex - 1] + list[resultIndex]) / 2.0;
            }
            else
            {
                return list[resultIndex];
            }
        }

#### 执行结果

执行结果 通过，执行用时 152ms，内存消耗 27.2MB .

#### 复杂度分析

**时间复杂度：O(m+n)**

i 和 j 一起把长度为 m 和 n 的两个数组遍历了一遍，所以时间复杂度为 O(m+n) 

**空间复杂度：O(m+n)**

使用list的长度为m+n.


### 方法三 : 方法二的优化，不真实添加到list

对于方法二，我们在已知 resultIndex 的情况下，也可以不把 nums1 和 nums2 真实添加到 list 中，只需要在i 和 j 不断向右移动的过程中，计算是否到达了 resultIndex 即可。 若到达了 resultIndex，可以直接返回结果，而不必再处理后面的数据。但是相对的，我们需要在 i 或者 j 向右移动时，判断是否到达了resultIndex.


        public double FindMedianSortedArrays(int[] nums1, int[] nums2)
        {
            int i = 0, j = 0, m = nums1.Length, n = nums2.Length;
            int len = m + n;
            int resultIndex = len / 2;
            int resultIndexPre = resultIndex - 1;
            int result = 0, resultPre = 0;  
            bool isTwoResult = len % 2 == 0;
            while (i < m || j < n)
            {
                var nums1ii = i < m ? nums1[i] : int.MaxValue;
                var nums2jj = j < n ? nums2[j] : int.MaxValue;
                if (nums1ii < nums2jj)
                {
                    if (i + j == resultIndexPre) resultPre = nums1[i];
                    if (i + j == resultIndex)
                    {
                        result = nums1[i];
                        if (isTwoResult) return (resultPre + result) / 2.0;
                        else return result;
                    }
                    i++;
                }
                else
                {
                    if (i + j == resultIndexPre) resultPre = nums2[j];
                    if (i + j == resultIndex)
                    {
                        result = nums2[j];
                        if (isTwoResult) return (resultPre + result) / 2.0;
                        else return result;
                    }
                    j++;
                }
            }
            return 0;
        }

#### 执行结果

执行结果 通过，执行用时 144ms，内存消耗 26.8MB .

#### 复杂度分析

**时间复杂度：O(m+n)**

i 和 j 一起把长度为 m 和 n 的两个数组遍历了一半，但是每一步都需要判断当前i+j的值是否等于resultIndex，所以时间复杂度仍可认为 O(m+n) 

**空间复杂度：O(1)**

对比方法二，不再使用list，只使用了几个变量来存值，所以空间复杂度为O(1)



### 方法四 : 第k小数

此方法来自 leetcode题解中 windliang 贡献的题解。在此感谢 windliang，文末给出了他的题解的链接。

前面的几种方法，时间复杂度都没有达到题目要求的 O(log(m+n)) 。 看到log，很明显需要使用二分法。根据 windliang提供的思路，题目求中位数，实际上是求第 k 小数的一种特殊情况，而求第 k 小数 有一种算法。

方法三中，i 和 j 每次向右移动一位时，相当于去掉了一个不可能是中位数的值，也就是一个一个的排除。由于给定的两个数组是有序的，所以我们完全可以一半一半的排除。假设我们要找第 k 小数，我们每次循环可以安全的排除掉 k/2 个数，下面看一个例子。

假设 nums1=[ 1,4,7,9 ] , nums2=[ 1,2,3,4,5,6,7,8 ] ,我们要找第7小的数字，即 k=7， 则 k/2 = 3 (向下取整).


![1.png](https://pic.leetcode-cn.com/3cbbf83c6379f7e9eab279b1344917e30c95632e14ee86d09044fd53366c1158-1.png)





因为 B的第三位为3 ，A的第三位为7，所以B的第三位较小，所以B的前三位 1，2，3 都不可能是第7小的数字。

上面这句话如果没有理解的话，可以换个说法：我们的目标 result 是第7小的数字，也就是说 A和B中 比 result 小的值 合计共有6个才对。但是对于B的前三位 1，2，3 来说，B后面的值因为B本身是有序数组，所以都比B的前三位大，而A的第三位又比B的第三位大，所以对于B的第三位B[2]来说，A和B中，没有合计的6个值比B[2]小的。B的前两位又一定是比第三位小的，就更不用说了。



![2.png](https://pic.leetcode-cn.com/1df17e64bbb5e6943d6142770956215ef9692e6cf059c25251731287e5911ee1-2.png)




因为减少了3位，所以我们要求的第7小的值，变为了剩下数据中第4小的值 k=4, k/2=2  ,所以需要比较当前A与B剩余数据的第二位。


![3.png](https://pic.leetcode-cn.com/6823d28c67b41168144665e1c6e18db9b921f4dec30fc9dfc2cb9458eaf46ef4-3.png)





当前A的第二位为4，B的第二位为5，A<B,所以A的前两位1和4被排除掉。


![4.png](https://pic.leetcode-cn.com/50477b25f083640e2c3b67294f7c453a7e71a12a354f29c13463f77f0c8ce2ff-4.png)





此时已经排除了5位，我们需要找的第7小的数，变成了剩下数据中第2小的数， k=2, k/2 =1 ,所以需要比较当前A与B剩余数据的第1位。



![5.png](https://pic.leetcode-cn.com/5b1dd6be07f8716fe394a824a25d08c209dc136265bdc071439b52ddfb839bb9-5.png)





此时B<A,所以B剩余数据的第一位 4 被排除掉。


![6.png](https://pic.leetcode-cn.com/c114946473a5f063c4750a6595b31916fd796a9454ef886a9d631d10f692be44-6.png)







我们需要找的是第7小的数，而现在已经排除了6个，所需现在需要找的是剩余数据中第1小的数， k=1 ； 当k=1时，达到了我们的循环出口条件：下面只需要比较A和B剩余数据的第一位，取小的那个数，就是我们的答案。



![7.png](https://pic.leetcode-cn.com/76a05d974d6336d4b11c6b6a1c2fee2ca450f94055bf54b0580405d05dcd4ca0-7.png)






因为5<7，所以5为最终答案。 即 对于A与B的第7小的数是5.

根据上面的分析，我们C#代码如下：

        public double FindMedianSortedArrays(int[] nums1, int[] nums2)
        {
            int n = nums1.Length;
            int m = nums2.Length;
            int len = n + m;
            int kPre = (len + 1) / 2;
            int k = (len + 2) / 2;
            if (len % 2 == 0)
                return (GetKth(nums1, 0, n - 1, nums2, 0, m - 1, kPre) + GetKth(nums1, 0, n - 1, nums2, 0, m - 1, k)) * 0.5;
            else
                return GetKth(nums1, 0, n - 1, nums2, 0, m - 1, k);
        }

        private int GetKth(int[] nums1, int start1, int end1, int[] nums2, int start2, int end2, int k)
        {
            int len1 = end1 - start1 + 1;
            int len2 = end2 - start2 + 1;
            //让 len1 的长度小于 len2，这样就能保证如果有数组空了，一定是 len1 
            if (len1 > len2) return GetKth(nums2, start2, end2, nums1, start1, end1, k);
            if (len1 == 0) return nums2[start2 + k - 1];
            if (k == 1) return Math.Min(nums1[start1], nums2[start2]);
            int i = start1 + Math.Min(len1, k / 2) - 1;
            int j = start2 + Math.Min(len2, k / 2) - 1;
            if (nums1[i] > nums2[j])
                return GetKth(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1));
            else
                return GetKth(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1));
        }
 
           
#### 执行结果

执行结果 通过，执行用时 136ms，内存消耗 27.1MB .

#### 复杂度分析

**时间复杂度：O(log(m+n))**

每进行依次循环，就减少 k/2个元素，所以时间复杂度为 O(log(k)) , 而 k = (m+n)/2 , 所以最终复杂度是 O(log(m+n))

**空间复杂度：O(1)**

只使用了几个变量来存值，递归是尾递归不占用堆栈, 所以空间复杂度为O(1)




### 方法五 : 从中位数的概念定义入手

该方法参考了 LeetCode 题解的 官方题解 以及 windliang 的题解。

首先我们来看一下百度百科中位数的定义：[https://baike.baidu.com/item/%E4%B8%AD%E4%BD%8D%E6%95%B0/3087401?fr=aladdin](https://baike.baidu.com/item/%E4%B8%AD%E4%BD%8D%E6%95%B0/3087401?fr=aladdin)

	Ø 中位数（Median）又称中值，统计学中的专有名词，是按顺序排列的一组数据中居于中间位置的数，代表一个样本、种群或概率分布中的一个数值，其可将数值集合划分为相等的上下两部分。对于有限的数集，可以通过把所有观察值高低排序后找出正中间的一个作为中位数。如果观察值有偶数个，通常取最中间的两个数值的平均数作为中位数。

所以我们可以对数组进行切割。

一个长度为 m 的数组，有 0 到 m 总共 m+1 个位置可以切。

![8.png](https://pic.leetcode-cn.com/a7dba4d9d509e08e6797e96b9ad79287317221265d653a864f2b152f76d188fb-8.png)




我们把数组 A 和数组 B 分别在 I 和 j 进行切割。


![9.png](https://pic.leetcode-cn.com/7ea3ed00e294da661c0b1a177eb25af6ff57b63fb1892a161cedcef3b75c4972-9.png)








将i的左边和j的左边组成[左半部分],将i的右边和j的右边组成[右半部分]。我们将左半部分称为left，右半部分称为right。

当 A数组 和 B数组 的总长度是偶数时，如果我们能够保证下面两点，

	1. len(left) = len(right),也就是 i+j = m-i+n-j, 即j=(m+n)/2-i
	2. max(left) <= min(right),也就是 max( A[i-1] , B[j-1] ) <= min( A[i] , B[j] )

那么 中位数就是 ( max(left) + min(right) ) / 2  , 也就是  ( max( A[i-1] , B[j-1] ) + min( A[i] , B[j] ) )/2

同样的，当 A数组 和 B数组 的总长度为奇数时，如果我们能够保证下面两点：

	1. len(left)=len(right)+1, 即 j=(m+n+1)/2-i 
	2. max(left) <= min(right),也就是 max( A[i-1] , B[j-1] ) <= min( A[i] , B[j] )

那么 中位数就是 max(left)，即max( A[i-1] , B[j-1] ) , 也就是left比right多出来的那一个数。

上面的第一个条件，我们可以将 奇数和偶数 两种情况合并为 j=(m+n+1)/2-i ,因为如果m+n是偶数，再加1之后，由于除以2是int类型的操作，所以对结果没有影响。

于是我们得到了 j与i的关系 j=(m+n+1)/2-i . 由于 0<=i<=m ,为了保证 0<=j<=n ,我们必须保证 m<=n . 这是因为

	j= (m+n+1)/2-i = m/2 + n/2 + 1/2 - i = (m-2i+n)/2 
	 因为0<=j<=n, 所以 0<=(m-2i+n)/2<=n
	先计算左边 
		(m-2i+n)/2 >= 0    
		即  n>=2i-m
		因为 0<=i<=m,所以 0<=2i<=2m,
		所以2i-m的取值范围为 -m <= 2i-m <= m
		又因为 n>=2i-m,需要大于等于2i-m的最大值m
		所以n>=m; 即 m <= n;
	再计算右边   
		(m-2i+n)/2 <= n   
		=>  m-2i+n <= 2n
		=>  m-2i <=n
		=>  n >= m-2i
		因为 0<=i<=m， 所以 0<=2i<=2m,
		所以m-2i的范围为 -m <= m-2i <= m
		又因为 n >= m-2i , 需要大于等于 m-2i的最大值m
		所以 n>=m；即 m <= n;

有了上面的证明，可以得知m<=n，即A数组的长度需要小于等于B数组的长度。所以在计算时若出现A数组长度大于B数组长度的情况时，交换两个数组的位置再继续计算即可。

对于上面的第二个条件，奇数和偶数的情况时一样的，都是 max(left) <= min(right),也就是 max( A[i-1] , B[j-1] ) <= min( A[i] , B[j] ) . 我们进一步分析，因为由题意已知A数组和B数组是有序的，所以一定有 A[i-1] <= A[i] 及 B[j-1] <= B[j] ,所以我们只需要保证 B[j-1] <= A[i] 和 A[i-1] <= B[j]  ,就可以保证 max(left) <= min(right). 

所以我们先讨论以下两种情况：

	1. 当 B[j-1] > A[i] 时，我们需要增加i，并且为了平衡left和right的数量，我们还需要减少j。 幸运的是 j=(m+n+1)/2-i, 当i增大时，j自然就会减小。
	2. 当A[i-1] > B[j] 时，与上面情面类似，我们需要增大j，即减小i。

两种情况示例图如下：



![10.png](https://pic.leetcode-cn.com/09011f0be05c92fbc09e7546ad9854b3d6cf78812afb98e9d35a2547fe3120c4-10.png)







  










上述两种情况，我们没有考虑切割位置在数组边界的情况。即 i的取值可能为0或者m；j的取值可能为0或n.

当i=0时，max(left) = B[j-1] ； 当 i=m时，min(right) = B[j];



![11.png](https://pic.leetcode-cn.com/2411a6f9781f48771f04d98ecc59293789f884b0e10cb0649d0ef75a7ff42f49-11.png)















类似的，当j=0时， max(left)= A[i-1] , 当 j=n时， min(right) = A[i] .

分析至此，所有的思路都理清了，最后一个问题，增加i的方式，当然是用二分了，因为题目要求的时间复杂度为log。 初始化i为中间的值，然后增加或减少一半的值，再增加或减少一半的值，类似有序数组中二分查找指定值。就这样二分查找直到最终结果。

代码也是参考了 windliang题解的代码。

        public double FindMedianSortedArrays(int[] A, int[] B)
        {
            int m = A.Length;
            int n = B.Length;
            //保证第一个数组是较短的
            if (m > n) return FindMedianSortedArrays(B, A);
            //正在寻找的范围为 [ A[iMin],A[iMax] ) , 左闭右开。二分查找取i=(iMin+iMax)/2
            int iMin = 0, iMax = m;
            while (iMin <= iMax)
            {
                int i = (iMin + iMax) / 2;
                int j = (m + n + 1) / 2 - i;
                if (j != 0 && i != m && B[j - 1] > A[i])
                { // i 需要增大
                    iMin = i + 1;
                }
                else if (i != 0 && j != n && A[i - 1] > B[j])
                { // i 需要减小
                    iMax = i - 1;
                }
                else
                { // 达到要求，并且将边界条件列出来单独考虑
                    int maxLeft = 0;
                    if (i == 0) { maxLeft = B[j - 1]; }
                    else if (j == 0) { maxLeft = A[i - 1]; }
                    else { maxLeft = Math.Max(A[i - 1], B[j - 1]); }
                    if ((m + n) % 2 == 1) { return maxLeft; } // 奇数的话不需要考虑右半部分

                    int minRight = 0;
                    if (i == m) { minRight = B[j]; }
                    else if (j == n) { minRight = A[i]; }
                    else { minRight = Math.Min(B[j], A[i]); }

                    return (maxLeft + minRight) / 2.0; //如果是偶数的话返回结果
                }
            }
            return 0.0;
        }

       
#### 执行结果

执行结果 通过，执行用时 128ms，内存消耗 27.2MB .

#### 复杂度分析

**时间复杂度：O(log(min(m，n))**

我们对较短的数组进行了二分查找，所以时间复杂度是 O(log(min(m，n))

**空间复杂度：O(1)**

只使用了几个变量来存值，所以空间复杂度为O(1)


## 参考资料汇总

题目：

[https://leetcode-cn.com/problems/median-of-two-sorted-arrays/](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/)

官方题解：

[https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu-b/](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu-b/)

windliang 题解：

[https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-2/](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-2/)

微软官方 List.Sort() 文档：

[https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1.sort?f1url=https%3A%2F%2Fmsdn.microsoft.com%2Fquery%2Fdev16.query%3FappId%3DDev16IDEF1%26l%3DZH-CN%26k%3Dk(System.Collections.Generic.List%601.Sort);k(DevLang-csharp)%26rd%3Dtrue&view=netframework-4.8](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1.sort?f1url=https%3A%2F%2Fmsdn.microsoft.com%2Fquery%2Fdev16.query%3FappId%3DDev16IDEF1%26l%3DZH-CN%26k%3Dk(System.Collections.Generic.List%601.Sort);k(DevLang-csharp)%26rd%3Dtrue&view=netframework-4.8)

百度百科中位数的定义：
[https://baike.baidu.com/item/%E4%B8%AD%E4%BD%8D%E6%95%B0/3087401?fr=aladdin](https://baike.baidu.com/item/%E4%B8%AD%E4%BD%8D%E6%95%B0/3087401?fr=aladdin)

百度百科 二分查找：
[https://baike.baidu.com/item/%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE/10628618?fr=aladdin](https://baike.baidu.com/item/%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE/10628618?fr=aladdin)
