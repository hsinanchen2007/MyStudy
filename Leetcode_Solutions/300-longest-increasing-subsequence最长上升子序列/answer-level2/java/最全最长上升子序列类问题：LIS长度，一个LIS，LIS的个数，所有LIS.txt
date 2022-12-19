# 最长上升子序列(LIS)

## 1. LIS的定义
LIS指的是最长上升/递增子序列(Longest Increasing Subsequence)。首先给出上升序列的概念，如果某个序列有如下性质
$$
(x_1, x_2,...,x_n)，x_1 < x_2 < ... < x_n
$$
那么就称该序列是上升的。那么LIS类问题就是给定一个序列(不一定是完全升序)

$$
(a_1, a_2,...,a_n)
$$
求该序列中的最长上升/递增子序列的相关内容。

这里简单介绍下字符串的子串(substring)和子序列(subsequence)的基本概念：

1. **子串(substring)**：字符串的子串指的是字符串中连续几个字符组成的序列，例如：string = "12345"，那么"12", "234"和“45”都是子串。对于Java而言，String.subString()便提供了子串截取的方法。

2. **子序列(subsequence)**：字符串的子序列值的是字符串中几个顺序一致的字符组成的序列，例如：string = "12345"，那么"12", "135"和“45”都是子序列。注意到，一个字符串的子序列的集合一定涵盖了该字符串子串的集合。

![image.png](https://pic.leetcode-cn.com/1c6e015de57d7b3ba495174cbbfb9fd3ea878a09b5cca673ffebe9f9e4a7b91c-image.png)

   有了上面的介绍，那么最长上升子序列的定义就很好理解了。这里我们给出一个例子：{1,3,5,2,4,6,7,8}，求该序列的最长上升子序列的长度。我们很快能发现{1,3,5,6,7,8}是该序列的一个最长上升子序列，其长度为6。这便引出了我们今天的第一类问题。

## 2. LIS的长度求解

这个题目是LeetCode上的一道原题[LeetCode. 300](https://leetcode-cn.com/problems/longest-increasing-subsequence/ )，我们抄一下题目。

给定一个无序的整数数组，找到其中的最长上升子序列的长度。
**示例：**
```
输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
```

这里我们主要详细介绍两种算法。其实还有一种树状数组/线段树的算法，不过树状数组/线段树是竞赛级别的方法，这里就不介绍了。

### 2.1 动态规划

#### 动态规划基本思想
动态规划的基本思想与分治法类似，也是将待求解的问题分解为若干子问题，按照顺序求解子问题。与分治法不同的是动态规划的求解问题，进过分解后得到的子问题往往不是相互独立的，即存在重叠子问题。由于动态规划解决的问题多数有重叠子问题的特点，为了减少重复用计算，对每一个子问题只求解一次，然后将不同阶段的不同状态都保存在一个动态规划表中。

#### 动态规划解题三要素

动态规划类题目在OJ题中占了很大一个比例，这类题目刷的多了，我也总结出了一些**One Rule To Rule Them All**规则，比如下面这个动态规划三要素，掌握了这个套路，这类题目大都可以信手拈来。

1. **定义动态规划求解问题**：简单的说就是定义dp[i]表示的问题或者转态是什么。一般来说，这个问题定义清楚，就成功了大半。
2. **状态转移方程**：转态转移就是根据子问题（上一阶段）状态和决策来导出本问题（当前阶段）的状态，确定了决策方法，就可以写出转态转移方程。
3. **边界条件**：状态转移方程是一个递推式，需要一个递推的边界条件来最终解出动态规划问题。

#### LIS长度解题思路

分析最长上升子序列，发现在计算过程中我们既不知道LIS的起始元素，也不知道LIS的结束元素，更不知道LIS包含的元素个数。这种情况下，我们很难定量的分析问题。于是，我们固定一项内容即LIS的结束元素。比如，我们已知LIS的结束元素为nums[i]，我们很容易发现以nums[i]元素为结束的LIS就是nums前i个字符的一个LIS。于是

1. 定义动态规划求解问题：dp[i]表示确定以nums数组中第i个字符结束的由nums[0] ~ nums[i]子串的LIS的长度。我们最终nums[0] ~ nums[len - 1]字符串的LIS肯定是dp[0] ~ dp[len-1]中数值最大的。

定义好了动态规划求解问题，我们下一步要寻找的便是转态转移方程。我们以dp[i]为例，以nums[i]元素为结束的LIS该怎么求呢？由于dp[i]表示确定以nums[i]结束的一个LIS，那么可以确定nums[i]在这个子序列中。那么，剩下的元素从哪里获取呢？状态转移方程描述的之前状态(dp[j], j < i)和当前状态(dp[i])的联系，很自然的我们想到通过dp[j] (j < i)来计算dp[i]。那么，由哪个dp[j]或者那几个dp[j]来推导呢？很自然地，我们发现它是由值最大的dp[j]得到的且这个dp[j]对应的nums[j]需要小于dp[i]，不然就不满足上升的性质了，于是

2. 状态转移方程：dp[i] = Max(dp[j] + 1)，0 <= j < i < len 且 nums[i] > nums[j]
3. 边界条件：这个很好给出，dp[0] = 1

#### 一个Demo
我们以{1,3,5,2,4,6,7}为例，模拟下这个过程：

| \       | \     | nums[j] | 1    | 3    | 5    | 2    | 4    | 6    | 7    |
| :------ | ----- | ------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| nums[i] | dp[i] | 初值/j  | 0    | 1    | 2    | 3    | 4    | 5    | 6    |
| 1       | dp[0] | 1       | \    | \    | \    | \    | \    | \    | \    |
| 3       | dp[1] | 1       | 2    | \    | \    | \    | \    | \    | \    |
| 5       | dp[2] | 1       | 2    | 3    | \    | \    | \    | \    | \    |
| 2       | dp[3] | 1       | 2    | 2    | 2    | \    | \    | \    | \    |
| 4       | dp[4] | 1       | 2    | 3    | 3    | 3    | \    | \    | \    |
| 6       | dp[5] | 1       | 2    | 3    | 4    | 4    | 4    | \    | \    |
| 7       | dp[6] | 1       | 2    | 3    | 4    | 4    | 4    | 5    | \    |

很明显LIS的长度 = dp[6] = 5


#### Show me the code - 动态规划代码
```
    public int lengthOfLIS(int[] nums) {
        int len = nums.length;
        if (len == 0) {
            return 0;
        }

        int max = 1;
        int[] dp = new int[len];
        Arrays.fill(dp, 1);

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
            max = Math.max(dp[i], max);
        }
        return max;
    }
```
#### 复杂度分析
空间复杂度：O(n)，n为nums数组的长度，这个很明显，我们构造了一个长度为n的dp数组
时间复杂度：O(n^2)，代码里 i 从 0 遍历到 n - 1，j 从 0 遍历到 i - 1，最里层的逻辑总共计算了
$$
0 + 1 + 2 + 3 + ... + n - 2 = {{(n - 2)(n - 1)}\over 2}
$$
所以是 O(n^2)。

但是，我们LeetCode提交却发现？？？很明显，这个不是O(n^2)时间复杂度的算法不是最优的方法。


![](https://pic.leetcode-cn.com/fb8241545a4273488e749fef1c5f30828ba4a69d64c033818a22dff7328aa3c2-file_1586338764425)

### 2.2 贪心+二分

#### 贪心+二分解题思路
从时间复杂度角度分析，如何把O(n^2)的时间复杂度降低更低呢？首先，可以明确一次遍历的操作无法避免，那么剩下的这个n是否可以将它降的更低呢？答案是可以将它降至log(n)。
我们有这样一个朴素贪心的想法，如果我维护的子序列上升的速度越慢，那么它是不是更容易加入更多的元素？比如：给出一个原始序列{1,3,5,2,4,6,7,8}，其中子序列{1,2}即比{1,3}上升的更慢，这两种情况下我们选择{1,2}已保证后面上升的空间更大。于是：
我们维护一个slow列表表示nums[]中的最慢上升序列，遍历nums，对于一个nums[i]，若：
1. nums[i] > slow的最后一个元素（即大于slow中的所有元素），就将加入到slow的最后面

2. nums[i] <= slow的最后一个元素，我们就查找slow列表中第一个大于等于nums[i]的数并替换它。由于非严格单调递增的序列，我们很容易的发现，可以使用二分法来查找这个数。这一步的时间复杂度便降到了log(n)

3. 最终的slow数组的长度就等于LIS的长度

#### 一个Demo
我们举一个原始序列为{1,3,5,2,4,6,7,0}的例子来模拟下这个过程：
1. 初始slow = []
2. nums[0] = 1，于是slow = [1]
3. nums[1] = 3，于是slow = [1, 3]
4. nums[2] = 5，于是slow = [1, 3, 5]
5. nums[3] = 2，2替换3，于是slow = [1, 2, 5]
6. nums[4] = 4，4替换5，于是slow = [1, 2, 4]
7. nums[5] = 6，于是slow = [1, 2, 4, 6]
8. nums[6] = 7，于是slow = [1, 2, 4, 6, 7]
9. nums[7] = 0，0替换1,于是slow = [0, 2, 4, 6, 7]
10. LIS的长度 = slow的长度 = 5

我们最后发现slow的长度为LIS的长度，但是slow列表明显不是一个LIS，甚至它都不是一个子序列。在nums[7] = 0这一步**破坏了子序列的性质**，这里的slow列表在于记录最小序列，代表了一种“最可能性”，只是此种算法为计算LIS而进行的一种替换。

#### Show me the code - 贪心+二分代码
```
    public int lengthOfLIS2(int[] nums) {
        int len = nums.length;
        if (len == 0) {
            return 0;
        }

        LinkedList<Integer> slow = new LinkedList<>();
        for (int i = 0; i < len; i++) {
            int ele = nums[i];
            if (slow.isEmpty() || ele > slow.getLast()) {
                slow.add(ele);
            } else {
                int idx = binarySearchLargerEleIndex(slow, ele);
                slow.set(idx, ele);
            }
        }

        return slow.size();
    }

    private int binarySearchLargerEleIndex(LinkedList<Integer> low, int val) {
        int left = 0;
        int right = low.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int ele = low.get(mid);
            if (ele < val) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
```

#### 复杂度分析
空间复杂度：O(k)，k为LIS的长度，这个很明显，我们构造了一个长度为k的slow列表
时间复杂度：O(nlogn)，外层遍历时间O(n)，内层插入O(1)，二分查找O(logn)


![](https://pic.leetcode-cn.com/56b919a2e21abf3a81767a90c96840c4e86213c831bfef5ea81328b0b87ee8c0-file_1586338764428)

### 2.3 What's the diffence?

可以发现，贪心+二分的算法在时间复杂度和空间复杂上都比动态规划的算法好，那么是不是可以说前者优于后者呢？答案是不一定的，在求LIS的长度上，前者是明显要好的。但是，在求具体的LIS解的值情况下，DP算法在很多方面上还是要优于贪心+二分的算法的。这便引出了我们这里要讲的第二类问题。

## 3. LIS的序列值求解
我们描述一下题目。
给定一个无序的整数数组，找到其中的一个最长上升子序列。
**示例：**
```
输入: [10,9,2,5,3,7,101,18]
输出: [2,3,7,101]或者[2,5,7,101]
```

这里我们不在是要求LIS的长度了，而是要求一个具体的LIS序列。同样地，这里我们尝试2种方法。

### 3.1 动态规划
#### 解题思路
前面求LIS长度的分析中，我们知道LIS可能出现在任意一个以nums[i]结尾的子序列中，但是我们并不知道会出现在哪里。在求LIS长度的问题中，我们是求dp[i]中的最大值。那这里，在求具体的LIS中，对于每一个dp[i]，我们需要用一个列表res存下一个结束于nums[i]的LIS。这样，最后找到值最大的dp[i]时，对应的res[i]即为所求整个串的LIS。

#### Show me the code - 动态规划
```
    public List<Integer> getSeqOfLIS(int[] nums) {
        int len = nums.length;
        if (len == 0) return new ArrayList<>();

        // dp[i]表示确定以下标为i元素结尾的nums[0]~nums[i]子串的最长递增子序列的长度
        int dp[] = new int[len];
        Arrays.fill(dp, 1);
        // res[i]表示确定以下标i元素结尾的nums[0]~nums[i]子串一个最长递增子序列
        List<List<Integer>> res = new ArrayList<>();

        int maxId = -1;
        int maxLength = Integer.MIN_VALUE;

        for (int i = 0; i < len; i++) {
            List<Integer> tmp = new ArrayList<>();
            // 链接到上一个不包括i的最长递增子序列的res里面的下标
            int index = -1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    index = j;
                }
            }

            if (index > -1) {
                tmp.addAll(res.get(index));
            }
            tmp.add(nums[i]);
            res.add(tmp);

            if (tmp.size() > maxLength) {
                maxLength = tmp.size();
                maxId = i;
            }
        }
        return res.get(maxId);
    }
```
#### 复杂度分析
空间复杂度：O(n)，这里的辅助数组或者列表用了两个:dp[], res[]，空间复杂度是2n，实际上可以将空间复杂度压缩到n，有兴趣的同学可以写下压缩到n的代码。具体的可以参考[Q300_1SeqOfLIS](https://github.com/UstcAce/SketchJ/blob/master/oj/src/main/java/leetcode/Q300_1SeqOfLIS.java)。
时间复杂度：O(n^2)

### 3.2 贪心+二分
#### 分析思路1

我在写这篇博文的时候参考了很多别人的博客，有一些人说贪心+二分的方法是不一定能找到一个具体的LIS解值的，因为在维护最慢上升序列slow的时候，可能会破坏子序列的性质。那么，我们就真的无法求得一个LIS了吗？我们简单回顾下之前的模拟过程：

原始序列为{1,3,5,2,4,6,7,0}：

1. 初始slow = []

   ....

2. nums[5] = 6，于是slow = [1, 2, 4, 6]

3. nums[6] = 7，于是slow = [1, 2, 4, 6, 7]

4. nums[7] = 0，0替换1,于是slow = [0, 2, 4, 6, 7]

5. LIS的长度 = slow的长度 = 5

我们可以发现，在nums[7] = 0这一步破坏了子序列的性质，但是实际上对于这个例子在nums[6] = 7这一步我们就找到了一个LIS了。这里似乎，此方法是可行的？
1. 我们先用一次贪心+二分的方法求得LIS的长度；
2. 再进行一次同样的过程，在slow数组达到LIS长度的时候停止返回当前的LIS，就如同上述例子一样，我们似乎可以找到[1, 2, 4, 6, 7]这样一个LIS。

**But** 我们的这样一个朴素的想法**是错误的**，举一个简单的反例，在原始序列后再加一个值 {1,3,5,2,4,6,7,0,10}

很显然，一个LIS为{1, 2, 4, 6, 7,10}，长度为6。但是，我们维护的slow列表第一次到达长度6的时候是slow = [0, 2, 4, 6, 7,10]，这显然不是一个LIS。

#### 分析思路2
上面的方法不可行，那么还有没有其他的方法呢？注意到，对slow列表的操作只有替换的时候有可能破坏LIS性质中子序列的特性。即slow表中的slow[i]在原序列的中的位置不一定是在slow[i+1]的左边。注意到，slow[i]与slow[i+1]还有一层含义，其表面slow[i+1]前面还有一个比它小的元素，只是可能数值上不是slow[i]，因为slow[i]可能被替换过。那么对于nums数组，我们可以考虑维护一个preValues数组。举例：
原始序列为{1,3,5,2,4,6,7,0}：

1. 初始slow = []
2. nums[0] = 1，于是slow = [1]，preValues = [null]
3. nums[1] = 3，于是slow = [1, 3]，preValues = [null, 1]
4. nums[2] = 5，于是slow = [1, 3, 5]，preValues = [null, 1, 3]
5. nums[3] = 2，2替换3，于是slow = [1, 2, 5]，preValues = [null, 1, 3, 1]
6. nums[4] = 4，4替换5，于是slow = [1, 2, 4]，preValues = [null,1, 3, 1, 2]
7. nums[5] = 6，于是slow = [1, 2, 4, 6]，preValues = [null, 1, 3, 1, 2, 4]
8. nums[6] = 7，于是slow = [1, 2, 4, 6, 7]，preValues = [null, 1, 3, 1, 2, 4, 6]
9. nums[7] = 0，0替换1,于是slow = [0, 2, 4, 6, 7]，preValues = [null, 1, 3, 1, 2, 4, 6, null]
10. LIS的长度 = slow的长度 = 5
11. 从slow列表的最后一个元素开始查preValue数组回溯， 7 -> 6 -> 4 -> 2 -> 1，最终得到了一个LIS。

#### Show me the code - 贪心 + 二分
```java
    public List<Integer> getSeqOfLIS3(int[] nums) {
        int len = nums.length;
        if (len == 0) {
            return new ArrayList<>();
        }

        LinkedList<Integer> preValues = new LinkedList<>();
        LinkedList<Integer> low = new LinkedList<>();
        for (int i = 0; i < len; i++) {
            int ele = nums[i];
            if (low.isEmpty() || ele > low.getLast()) {
                low.add(ele);
                if (low.size() == 1) {
                    preValues.add(null);
                } else {
                    preValues.add(low.get(low.size() - 2));
                }
            } else {
                int idx = binarySearchLargerEleIndex(low, ele);
                low.set(idx, ele);
                if (idx == 0) {
                    preValues.add(null);
                } else {
                    preValues.add(low.get(idx - 1));
                }
            }
        }

        LinkedList<Integer> res = new LinkedList<>();
        res.addLast(low.getLast());

        Integer pre = low.getLast();
        for (int i = nums.length - 1; i >= 0; i--) {
            Integer numVal = nums[i];
            if (pre.equals(numVal) && preValues.get(i) != null) {
                res.addFirst(preValues.get(i));
                pre = preValues.get(i);
            }
        }

        return res;
    }
```
#### 复杂度分析
空间复杂度：O(n)
时间复杂度：O(nlogn)

### 3.3 So, what's the diffence?
在求得一个具体的LIS解值，贪心+二分的算法也由于DP算法。但是更近一步而言，DP算法在解的广度上比贪心+二分的方法更好，这边引出了我们要讲的第三类问题。

## 4. 求所有的LIS

这个题目是LeetCode上的一道原题非常相似[LeetCode. 673](https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/ )，我们抄一下题目。

```
给定一个未排序的整数数组，找到最长递增子序列的个数。

示例 1:
输入: [1,3,5,4,7]
输出: 2
解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。

示例 2:
输入: [2,2,2,2,2]
输出: 5
解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。

```

LeetCode上求LIS的个数有很多种解法，如动态规划(O(n^2))，线性段(O(nlogn))。但是这里，我们更关心找到所有解。因为，实际应用过程中的优化类问题，我们很多情况下并不关心解有多少个，而是关心解有那几个，解是什么。于是，这里我们要求所有的LIS。顺带地，求出所有的LIS后，自然得出了LIS的个数。

### 4.1 动态规划思路

对于很多串，比如{1,3,5,2,4,6,7}。很明显地，它不止有一个LIS，这里有{1,3,5,6,7}和{1,2,4,6,7}。那么在动态规划求解过程中，如何将所有解都记录下来呢？

1. 首先我们分析多个LIS可能出现在哪里？这里有2种情况：
2. 第一种情况，以nums[i]结束的子序列中出现多个LIS，这里LeetCode.673题干的示例1可以说明。
3. 第二种情况，多个LIS可能出现在以不同nums[i]结束的子序列中，这个很好举例，{3, 5, 1, 2}，两个LIS {3, 5}和{1，2}。
4. 那么，我们就需要保留每一个以nums[i]结束的子串的LIS的集合，并最终根据LIS的长度把长度等于LIS_maxLen的集合合并到一起。

我们注意到，在3.1动态规划求一个LIS序列值的代码，这里条件dp[j] + 1 > dp[i]能保证取到的是顺序上第一个LIS，这里再加一个dp[j] + 1 == dp[i]的分支就很容易的找到其他LIS。

```
        for (int i = 0; i < len; i++) {
            List<Integer> tmp = new ArrayList<>();
            // 链接到上一个不包括i的最长递增子序列的res里面的下标
            int index = -1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    index = j;
                }
            }
         }
```
需要注意的是，dp[j] + 1在某些数值上是可能递增的，我们以{1,3,5,2,4,6,7}为例，在dp[6]的时候dp[j] + 1是从2 递增到5。那么在维护局部的LIS解的时候需要直接替换之前的解。

| \       | \     | nums[j] | 1    | 3    | 5    | 2    | 4    | 6    | 7    |
| :------ | ----- | ------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| nums[i] | dp[i] | 初值/j  | 0    | 1    | 2    | 3    | 4    | 5    | 6    |
| 1       | dp[0] | 1       | \    | \    | \    | \    | \    | \    | \    |
| 3       | dp[1] | 1       | 2    | \    | \    | \    | \    | \    | \    |
| 5       | dp[2] | 1       | 2    | 3    | \    | \    | \    | \    | \    |
| 2       | dp[3] | 1       | 2    | 2    | 2    | \    | \    | \    | \    |
| 4       | dp[4] | 1       | 2    | 3    | 3    | 3    | \    | \    | \    |
| 6       | dp[5] | 1       | 2    | 3    | 4    | 4    | 4    | \    | \    |
| 7       | dp[6] | 1       | 2    | 3    | 4    | 4    | 4    | 5    | \    |

### 4.2 Show me the code - 动态规划
```java
    public List<List<Integer>> getAllSeqOfLIS(int[] nums) {
        int len = nums.length;
        if (len == 0) return new ArrayList<>();

        // dp[i]表示确定以下标为i元素结尾的nums[0]~nums[i]子串的最长递增子序列的长度
        int[] dp = new int[len];
        Arrays.fill(dp, 1);

        // 第一层List<i>表示以i个元素结束的所有最长递增子序列集合
        // 第二层List表示所有子序列
        // 第三层List表示一个子序列
        List<List<List<Integer>>> allSeqList = new ArrayList<>();
        int maxLen = 1;
        for (int i = 0; i < len; i++) {
            List<List<Integer>> local = new ArrayList<>();

            int lastIndex = -1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        // 替换之前的局部的LIS结果
                        local.clear();
                        lastIndex = j;
                        local.addAll(getNewCopyDoubleList(allSeqList.get(j)));
                        for (List<Integer> seq : local) {
                            seq.add(nums[i]);
                        }
                        dp[i] = dp[j] + 1;
                    } else if (dp[j] + 1 == dp[i]) {
                        List<List<Integer>> more = getNewCopyDoubleList(allSeqList.get(j));
                        for (List<Integer> seq : more) {
                            seq.add(nums[i]);
                        }
                        local.addAll(more);
                    }
                }
            }

            if (lastIndex == -1) {
                List<Integer> oneEleList = new ArrayList<>(Arrays.asList(nums[i]));
                local.add(oneEleList);
            }
            allSeqList.add(getNewCopyDoubleList(local));

            maxLen = Math.max(dp[i], maxLen);
        }

        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0; i < len; i++) {
            if (dp[i] == maxLen) {
                res.addAll(new ArrayList<>(allSeqList.get(i)));
            }
        }

        return res;
    }

    private List<List<Integer>> getNewCopyDoubleList(List<List<Integer>> doubleList) {
        List<List<Integer>> result = new ArrayList<>();

        for (List<Integer> list : doubleList) {
            result.add(new ArrayList<>(list));
        }
        return result;
    }
```

### 4.3 复杂度分析
空间复杂度：O(n)
时间复杂度：O(n^2)


## 总结

至此，我们已经用动态规划解决了一类LIS问题，求LIS的长度，求一个LIS，求LIS的个数以及求所有的LIS。虽然，在某些问题上动态规划方法不是时间复杂度最好的，但是它确实适用性最广的。在一般的OJ题(面试题或者笔试题)中动态规划也是非常常见的类型。这里，从LIS的四个子问题深入分析了动态规划的实践，希望能对各位读者有帮助。

本文转载自个人掘金博客https://juejin.im/post/5e8c9a6a51882573ac3ce686
觉得写的不错的同学麻烦点个赞，支持一下呗^_^~


## 参考资料

1. https://cloud.tencent.com/developer/article/1194046
2. https://blog.csdn.net/lxt_Lucia/article/details/81206439
