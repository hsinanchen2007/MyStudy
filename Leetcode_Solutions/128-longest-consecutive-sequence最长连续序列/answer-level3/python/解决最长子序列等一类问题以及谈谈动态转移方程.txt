



-----------
开始正文
------------
#### `PART1`
##### <LeetCode笔记-Java版-专题篇-子序列>
##### 一些名词
- `LCIS`:`Longest Continuous Increasing Subsequence` 最长连续递增序列
- `LIS`:`Longest Increasing Subsequence` 最长上升子序列
- `LCS`:`Longest Consecutive Sequence` 最长连续序列
- `LCS`:`longest common subsequence` 最长公共子序列

- 参考`liweiwei1419`大神
- 1、子序列（`Subsequence`）：“子序列”并不要求是连续子序列，只要保证元素前后顺序一致即可，例如：序列 `[4, 6, 5]` 是 `[1, 2, 4, 3, 7, 6, 5]` 的一个子序列；
- 2、上升：这里“上升”要求严格“上升”。
- 例如一个序列 `[2, 3, 3, 6, 7]` ，由于 `3` 重复了，所以不是严格“上升”的，因此它不是题目要求的“上升”序列。
- 一个序列可能有多个最长上升子序列，题目中只要我们求这个最长的长度。如果使用回溯算法，选择所有的子序列进行判断，时间复杂度为 $O((2^N) * N)$

##### 300. 最长上升子序列 Medium
###### 方法1：DP
- `dp[i]`表示以`i`索引结尾的最长上升子序列的长度，即在`[0-i]`范围内，以`nums[i]`结尾的可以获得的最长上升子序列的长度
- 如果遍历到`i`位置，在`[0-i]` 区间内有`[0-j] j<i` 当`nums[i]<=nums[j]`时，表示以`j`结束的子序列和`i`结束的子序列不能形成上升子序列，举 例：`[1,4,5,7,6,8]`，当`i`在`index`为`4`的位置，也就是`nums[i] =6` ,`j `为`index` 为`3`时，`nums[j] =7` ,以`nums[j] `和`nums[i]` 不能形成一个上升子序列；
那么情况当`nums[i]>nums[j]`时，可以考虑在`max[dp[j]]`的最大值加上当前`nums[i]`的长度也就是，  $dp[i] = Math.max(dp[i], dp[j] + 1)|0<=j<i<n$,此为状态转移方程



- 复杂度
    - 时间复杂度$O(n^2)$。有两个 `n` 的循环。
    - 空间复杂度$O(n)$，用了大小为 `n` 的矩阵 `dp`。
  
```java []
public int lengthOfLIS(int[] nums) {
        //dp[i]: 到i为止 (对于所有 j in [0, i], 记录max length of increasing subsequence
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int len = nums.length;
        int[] dp = new int[len];
        for (int i = 0; i < len; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                //i 位置的数与[0,i]位置之间的数比较，如果大于进逻辑
                if (nums[i] > nums[j]) {
                    //等于dp[i]或者dp[j] + 1（j对应的值比i小）的最大值
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
        }
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < len; i++) {
            max = Math.max(max, dp[i]);
        }
        return max;
    }
```
```python []
console.log("hello python")
```

##### 举一反三：牛牛的数列

###### 方法1：DP
- 牛牛现在有一个`n`个数组成的数列,牛牛现在想取一个连续的子序列,并且这个子序列还必须得满足:最多只改变一个数,就可以使得这个连续的子序列是一个严格上升的子序列,牛牛想知道这个连续子序列最长的长度是多少。
- `output`:一个整数，表示最长长度
- 这一题注意是求连续的
- 准备两个`dp array`，`start` 表示以`nums[i]` 开始的的最长递增连续子序列的长度，`end`表示以`nums[i]`结束的最长递增连续子序列的长度，
- 初始化`start[n-1] =1`(表示最后一个字符开始的最长连续子序列的长度，即其本身，长度为`1`)，初始化`end[0] =1`(表示第一个字符结束的最长连续子序列的长度，即其本身，长度为`1`)
- 注意`start`和`end`的生成的`loop`顺序
- 然后取i位置，当`nums[i-1]<nums[i+1]` 表示可以形成一段连续递增子序列，只需要改i位置的值就可以了，然后取`sum= start[i + 1] + end[i - 1] + 1`; 表示以`i-1`位置结束的数最长递增子序列和i+1开始的最长递增子序列可以连起来
例如`{7 2 3 1 5 6}`，`end[0]` 表示以7结束的，`end[0] =1`,`end[1]` 表示以2结束的，`end[1] =1`,`end[2]=2`,`end[3]=1`,`end[4]=2`,`end[5]=3`,同理可的`start`的

```java []
public static int lengthOfContinusLIS(int[] nums, int n) {
        int[] start = new int[n];
        int[] end = new int[n];
        end[0] = 1;
        for (int i = 1; i < n; i++) {
            end[i] = nums[i] > nums[i - 1] ? end[i - 1] + 1 : 1;
        }
        start[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            start[i] = nums[i] < nums[i + 1] ? start[i + 1] + 1 : 1;
        }
        int result = 0;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i - 1] < nums[i + 1]) {
                int sum = start[i + 1] + end[i - 1] + 1;
                result = Math.max(result, sum);
            }
        }
        return result;
    }
```
```python []
console("hello world!")
```


##### 举一反三：非严格上升子序列

- 这一题同举一反三：牛牛的数列

##### 674. 最长连续递增序列 Easy
- 给定一个未经排序的整数数组，找到最长且连续的的递增序列。
- `dp[i]`表示以i位置结尾，即`nums[i]`值结尾的，最长连续递增序列的长度
- 想要求`dp[i]` 只需要关注 `nums[i]` 与 `nums[i - 1]`的对比
- 当`nums[i] > nums[i - 1]`，可以和`nums[i-1]`拼接起来， `dp[i] = dp[i - 1] + 1`;
- 当`nums[i] <=nums[i - 1] nums[i]`自身形成一个最长连续递增序列，长度为`1`
###### 方法1：DP `Space O(n)`
```java []
 public int findLengthOfLCIS(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        int n = nums.length;
        int[] dp = new int[n];
        Arrays.fill(dp,1);
        int max = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
                max = Math.max(max, dp[i]);
            }
        }
        return max;
    }
```
```python []
console("hello world!")
```


###### 方法2：DP `Space O(1)`
- 因为连续的序列，`i`依赖前一个数`i-1`，使用`int[] dp = new int[2]`; 重复使用
```java []
public int findLengthOfLCIS(int[] nums) {
       if (nums == null || nums.length == 0) return 0;
        int n = nums.length;
        int[] dp = new int[2];
        dp[0] = 1;
        int maxLen = 1;
        for (int i = 1; i < n; i++) {
            dp[i % 2] = 1;
            if (nums[i] > nums[i - 1]) {
                dp[i % 2] += dp[(i - 1) % 2];
            }
            maxLen =Math.max(maxLen,dp[i%2]);
        }
        return maxLen;
    }
```
```python []
console("hello world!")
```




##### 673. 最长递增子序列的个数 Medium
###### 方法1：DP
- 与`300`题主体框架一样，注意是递增子序列，可以不连续，可以跳跃，本题的难点是记下来组合方式，一开始选用的时`Map`计数，过不了，`1,2,4,3,5,4,7,2`，最长递增序列有`1,2,4,5,7;1,2,3,5,7;1,2,3,4,7`三种情况，但是采用`map`只有2种
- 主体的`dp`不变`，dp[i]`表示以`nums[i]`结束的最长递增子序列的长度，动态转移方程，`[0-i]`范围内，然后扫`[0-j]`范围内，`j<i`, `dp[i] = Math.max(dp[j] + 1, dp[i])`; `dp`的初始化都为`1`，因为`nums[i]`自身可以形成一个子序列，长度为`1`
- 难点是计数，也就是要记下来`nums[i]`结尾的所有子序列的，也就是组合数，准备一个`n`长度的数组`counter`，，`counter[i]`表示以`nums[i]`结尾的最长子序列的个数，也就是以`nums[i]`结尾的最长子序列的组合数量，(如`1,2,4,3,5,4,7,2`，最长递增序列有`1,2,4,5,7;1,2,3,5,7;1,2,3,4,7`三种情况，以`nums[6]=7`结尾的`counter[6]=3`)
- 在满足` if (nums[i] > nums[j])` 条件时，比较`dp[j] + 1` 与 `dp[i]`的大小，
- 当`dp[j] + 1>dp[i]`,说明第一次找到以nums[i]为结尾的最长递增子序列，长度为`dp[j] + 1，->counter[i] = counter[j]`, 以`nums[i]`结尾的最长递增子序列的组合数`=`以`nums[j]`结尾的最长递增子序列的组合数
- 当`dp[j] + 1=dp[i]`,说明这个长度已经找到过一次了，  `counter[i] += counter[j]`，现在的组合方式`+counter[j]`的组合方式
- 核心代码：
```java
if (nums[i] > nums[j]) {
    if (dp[j] + 1 > dp[i]) {
        dp[i] = Math.max(dp[j] + 1, dp[i]);
        counter[i] = counter[j];
    } else if (dp[j] + 1 == dp[i]) {
        counter[i] += counter[j];
    }
}
```


- 举例：
![dbf04caf16370077061aead090c28d8.jpg](https://pic.leetcode-cn.com/12fb1188040ae3ac38377a6de12d5435ef73e92102bebf84f3d589e3d61253a8-dbf04caf16370077061aead090c28d8.jpg)


```java []
public int findNumberOfLIS(int[] nums) {
    if (nums == null || nums.length == 0) return 0;
    int n = nums.length;
    int[] dp = new int[n];
    int[] counter = new int[n];
    Arrays.fill(counter, 1);
    dp[0] = 1;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = Math.max(dp[j] + 1, dp[i]);
                    counter[i] = counter[j];
                } else if (dp[j] + 1 == dp[i]) {
                    counter[i] += counter[j];
                }
            }
        }
        maxLen = Math.max(maxLen, dp[i]);
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] == maxLen) result += counter[i];
    }
    return result;
}
```
```python []
console("hello world!")
```


##### 397. 最长上升连续子序列 [LC] Medium
###### 方法1：`DP`
- `Challenge`
- 使用 `O(n)` 时间和` O(1)` 额外空间来解决
- 本题不太一样的是可以从前往后也可以从后往前生成上升连续子序列
- 准备两个数组，`start`，`end` ，容量都为`2`，`start`表示从前往后，`end`表示从后往前
`Math.max(maxStart, maxEnd)`;未答案

```java []
public int longestIncreasingContinuousSubsequence(int[] nums) {
    if (nums == null || nums.length == 0) return 0;
    int n = nums.length;
    int[] start = new int[2];
    Arrays.fill(start,1);
    int maxStart = 1;
    for (int i = 1; i < n; i++) {
        start[i % 2] = 1;
        if (nums[i] > nums[i - 1]) {
            start[i % 2] += start[(i - 1) % 2];
        }
        maxStart = Math.max(maxStart, start[i % 2]);
    }
    int[] end = new int[2];
    int maxEnd = 1;
    Arrays.fill(end,1);
    for (int i = n - 2; i >= 0; i--) {
        end[i % 2] = 1;
        if (nums[i] > nums[i + 1]) {
            end[i % 2] += end[(i + 1) % 2];
        }
        maxEnd = Math.max(maxEnd, end[i % 2]);
    }

    return Math.max(maxStart, maxEnd);
}
```
```python []
console("hello world!")
```



##### 77. 最长公共子序列[LC] Medium 1143. 最长公共子序列
###### 方法1：`DP`
- 基本经典动态规划题目
- 定义`dp[m][n]`组成一个`m`行`n`列的二维动态矩阵，`dp[i][j]`表示`str1[0-i]与str2[0-j]`中的最长公共子序列的长度
- 先初始化`dp[0][0]`，先行，后列
- 当`str1[i]!=str2[j]`时，
- 表明`str1[0-i]与str2[0-j]`的最长公共子序列的长度与`str1[0-(i-1)]`与`str2[0-j]`的最长公共子序列的长度的效果是一样的,即`dp[i][j]=dp[i-1][j]`
- 但是也可能：`str1[0-i]`与`str2[0-j]`的最长公共子序列的长度与`str1[0-i]`与`str2[0-(j-1)]`的最长公共子序列的长度的效果是一样的,即`dp[i][j]=dp[i][j-1]`
- 当`str1[i]=str2[j]`时，只要知道`str1[0-(i-1)]`与`str2[0-(j-1)]`的最长公共子序列的长度，再在其基础上`+1`即可`dp[i][j]=dp[i][j]`, `dp[i - 1][j - 1] + 1`

```java []
    public int longestCommonSubsequence(String text1, String text2) {
        if (text1 == null || text2 == null || text1.length() == 0 || text2.length() == 0) return 0;
        char[] chas1 = text1.toCharArray();
        char[] chas2 = text2.toCharArray();
        int m = chas1.length, n = chas2.length;
        int[][] dp = new int[m][n];
        dp[0][0] = chas1[0] == chas2[0] ? 1 : 0;
        for (int i = 1; i < m; i++) dp[i][0] = chas1[i] == chas2[0] ? 1 : dp[i - 1][0];
        for (int j = 1; j < n; j++) dp[0][j] = chas1[0] == chas2[j] ? 1 : dp[0][j - 1];
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                if (chas1[i] == chas2[j]) dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
        return dp[m - 1][n - 1];
    }

```
```python []
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        if not text1 or not text2: return 0
        m, n = len(text1), len(text2)
        dp = [[0] * n for _ in range(m)]
        dp[0][0] = 1 if text1[0] == text2[0] else 0
        for i in range(1, m): 
            dp[i][0] = 1 if text1[i] == text2[0] else dp[i - 1][0]
        for j in range(1, n): 
            dp[0][j] = 1 if text1[0] == text2[j] else dp[0][j - 1]
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1])
                if text1[i] == text2[j]:
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1)
        return dp[m - 1][n - 1]
```




##### 128. 最长连续序列 Hard 
- 要求算法的时间复杂度为` O(n)`
###### 方法1：排序
- 先排序，再转逻辑
- 复杂度分析
- 时间复杂度：`O(nlgn)`
- 算法核心的 `for`循环恰好运行` n` 次，所以算法的时间复杂度由 `sort` 函数的调用决定，通常会采用` O(nlgn)` 时间复杂度的算法。
- 空间复杂度：`O(1)`或者` O(n)`
- 以上算法的具体实现中，由于我们将数组就低排序，所以额外的空间复杂度是常数级别的。如果不允许修改输入数组，我们需要额外的线性长度的空间来保存中间结果和排好序的数组。


```java []
if (nums == null || nums.length == 0) return 0;
Arrays.sort(nums);
int n = nums.length;
int longestCnt = 1;
int curCnt = 1;
for (int i = 1; i < n; i++) {
    if (nums[i] != nums[i - 1]) {
        if (nums[i - 1] + 1 == nums[i ]){
            curCnt++;
        } else{
            longestCnt = Math.max(longestCnt, curCnt);
            curCnt = 1;
        }
    }
}
return Math.max(longestCnt, curCnt);
```
```python []
console("hello world!")
```



###### 方法2：哈希表和线性空间的构造
- 参考`leetcode`官方题解
- 准备一个`set`，将`nums`中的数都倒进去
- `for loop nums`当前为`num`如果`num-1`出现在`set`中，不需要计算，如果去掉这段代码，也能通过，效率差点
- 当前的`curNum`的下一个数`curNum+1`如果出现在set中，说明，目前还是连续的，`curNum`更新，`curCnt`更新
- `loop`的过程中记录下`longestCnt`，最终返回

- 复杂度分析
- 时间复杂度：`O(n)`	
- 尽管在 `for` 循环中嵌套了一个` while` 循环，时间复杂度看起来像是二次方级别的。但其实它是线性的算法。因为只有当 currentNum 遇到了一个序列的开始， `while` 循环才会被执行（也就是 currentNum-1 不在数组 nums 里）， `while `循环在整个运行过程中只会被迭代 nn 次。这意味着尽管看起来时间复杂度为 O(n *n)O(n⋅n) ，实际这个嵌套循环只会运行 `O(n + n) = O(n)O(n+n)=O(n)` 次。所有的计算都是线性时间的，所以总的时间复杂度是`O(n)`的。
空间复杂度：`O(n)`
- 为了实现` O(1)`的查询，我们对哈希表分配线性空间，以保存 `nums`数组中的 `O(n)` 个数字。除此以外，所需空间与暴力解法一致。

```java []
public int longestConsecutive(int[] nums) {
    Set<Integer> set = new HashSet<>();
    for (int num : nums) set.add(num);
    int longestCnt = 0;
    for (int num : nums) {
        if (!set.contains(num - 1)) {
            int curNum = num;
            int curCnt = 1;
            while (set.contains(curNum + 1)) {
                curNum++;
                curCnt++;
            }
            longestCnt = Math.max(longestCnt,curCnt);
        }
    }
    return longestCnt;
}
```
```python []
console("hello world!")
```




##### 857. 最小的窗口子序列[LC] Hard TODO
- 同`LeetCode` 727

#### `PART2`:谈谈动态转移方程 
##### 子串、子序列、回文的动态转移方程：

##### `LC-300`:最长上升子序列`Longest Increasing Subsequence` /`LIS`
  - `dp[i]`表示的是`s[0...i]`这个范围内的最长上升子序列的长度
  - `base case`:`s[0]`时，长度为`1`，字符本身可以形成一个上升子序列，故`dp[0]=1`
  - 其他情况下，需要探测下`i`之前的数，假如到了`nums[j]`这个数，有两种情况
    - `nums[j]>=nums[i]`，这种情况下对于结果没有意义，因为上升子序列的话，需要前面的数`nums[j]`比`nums[i]`小，才可以形成一个上升子序列
    - `nums[j]<nums[i]`，也就是`[0...j]`这个范围内已经形成的上升子序列加上`nums[i]`这个数后可以形成一个新的上升子序列，显然：$dp[i]=max(dp[i],dp[j]+1)|j∈[0,i)$
[![8IRuQK.png](https://pic.leetcode-cn.com/1ba8f955bbbd9646e47b5f4d88c4ba5e1d702e6816415b23d22e726927288bbc.png)](https://imgchr.com/i/8IRuQK)
    - 举例：
	    [![85QBTI.png](https://pic.leetcode-cn.com/f82b87253152ca147663703d4ccbf4fdef13a8d34e9ec03c8e9f6ed29a9aff5b.png)](https://imgchr.com/i/85QBTI)
        - 当`i=2`时，因为前面没有比`nums[2]=2`小的数，所以`dp[2]=1`,也就是说以`nums[2]=2`结尾的最长上升子序列，是其本身，长度为`1`
        - 当`i=3`,前面比起小的数只出现在索引`2`,`[2,5]`可以形成一个上升子序列，因此`dp[3]=max(dp[3],dp[2]+1)=2`
        - 当`i=5`时，`dp[5]=max(dp[5],dp[3]+1)=3`


##### `LC-516`:最长回文子序列`Longest Palindromic Subsequence`/`LPS`

- **本题只涉及一个字符串，但是在组成`dp`时，需要用到两个字符数组**

  [![8IXB0s.png](https://pic.leetcode-cn.com/ca068b56174ba01b926af096db7375465824bdd3cfc95bb1f327f92482458566.png)](https://imgchr.com/i/8IXB0s)

- **`dp[i][j]`表示的是字符`s[i...j]这个范围内的最长回文子序列的长度`**，记住子序列可以跳跃，`i`的值小于`j`的值
- 当`s[i]==s[j]`，可以很容易想到，根据`dp`的思想，要找其子问题，也就是`dp[i+1][j-1]`，即`s[i+1....j-1]`这个字符串区间范围内的值，再加上`s[i]`与`s[j]`已经形成了回文，要加上长度`2`，得结果:$dp[i][j]=dp[i+1][j-1]+2$

- 当`s[i]!=s[j]`,还是要找其子问题，有两种情况：
  - 求出`dp[i+1][j]`,也就是`s[i+1....j]`字符串范围上的最大回文子序列
  - 求出`dp[i][j-1]`,也就是`s[i....j-1]`字符串范围上的最大回文子序列
  - 因为`s[i]`与`s[j]`不能形成回文，故此：$dp[i][j]=max(dp[i+1][j],dp[i][j-1])$

- 做出的`dp table`,两种遍历方式，斜着遍历或者倒着遍历

[![8o994s.png](https://pic.leetcode-cn.com/4922e6e851d2ec7055e4d076d71c74b7e55fd1fd1143cb7178419e87cffc0a55.png)](https://imgchr.com/i/8o994s)

[![8o9SEQ.png](https://pic.leetcode-cn.com/1af79780bdd1077898c5ade4a4aed37ac9c40bcabca1632c386da76f3dd7c9dc.png)](https://imgchr.com/i/8o9SEQ)

- TODO

---
---

#### **更多内容，欢迎订阅**
- **微信公众号:阿飞算法**
- **github(求个star):[geek-algorithm-leetcode](https://github.com/wat1r/geek-algorithm-leetcode)**
![qrcode_for_gh_76cb721bf802_258.jpg](https://pic.leetcode-cn.com/3a58c16558d9218298013dac7197caa816120e478f0f0ed1be2e2bd205395d56-qrcode_for_gh_76cb721bf802_258.jpg)