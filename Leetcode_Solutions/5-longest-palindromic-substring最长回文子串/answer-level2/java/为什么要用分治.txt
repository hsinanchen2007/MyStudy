原文地址：https://www.cnblogs.com/niuyourou/p/12466662.html
分治法是不断的将问题分解，直到分解到最小子问题，然后不断的向上返回，由小问题的解表示大问题的解。
首先需要了解的是，分治不等于二分，二分法是分治的一个特例。二分法可以直接在每次计算时，将问题规模减半。而普通的分治并没有缩小总的问题规模，只是将问题分解为了多个子问题。
时间复杂度表示如下：
二分：通过O(1)的操作，将规模为 n 的问题变成了 n/2 的问题。
即：T( n ) = T( n / 2 ) + O( 1 )
分治：通过O(1)的操作，将规模为 n 的问题变成了2个 n/2 的问题。
即：T( n ) = 2 T( n / 2 ) + O( 1 )
递推下来：
二分：
    T( n ) = T( n/2 ) + O( 1 )
    T( n ) = T( n/4 ) + 2 O( 1 )
    T( n ) = T( n/8 ) + 3 O( 1 )
    …
    …[共 logN 次]
    …
    T( n ) = T( 1 ) + logN·O( 1 )
    T( n ) = O( 1 ) + O (logN)
    T( n ) = O(logN)
分治：
    分治1次
    T( n ) = 2 T( n/2 ) + O( 1 )
    分治2次
    T( n ) = 4 T( n/4 ) + 3 O( 1 )
    分治3次
    T( n ) = 8 T( n/8 ) + 7 O( 1 )
    …
    …[共 logN 次]
    …
    T( n ) = (n) T( 1 ) + (n-1) O ( 1 )
    T( n ) = n*O(1) + O(n-1）
    T( n ) = O(n) + O(n-1)
    T( n ) = O(n)
可以简单理解为，二分是特殊情况下的分治进行了减枝。

问题规模不变，听起来似乎没有进行分治的必要。

但我们比较一下暴力解法于分治解法的递归函数：

暴力解法：　search1(int left, int mid, int depth)，以 mid 为中心依靠 left 的移动搜索回文串。 

分治解法：   dp(int left, int right) ，判断 left - right 之间的字符串是否是回文串。


对于暴力解法而言，我们只是单纯的沿着解空间在搜索，函数的入参只需要能够支持我们进行搜索，可以保存临时结果和搜索的坐标就可以了，除此之外并没有特别的语义。

但对于分治解法，因为我们有分解问题的思想，每一次函数调用，就是在定义和解决一个子问题。入参的集合必须足够我们唯一的定义一个子问题，并且我们定义出了子问题与上级问题间解的关系，这样很容易的我们便可以发现，同层级的问题所需的子问题有许多是重复的。自然的我们可以以入参的集合为坐标建立缓存，避免无效计算。

其实细想一下，对于暴力搜索，解空间与分治本质上是相同的，也存在着大量的重复计算。

比如 mid=3，left=0 时我们判断该字符串是否为回文串，我们完全可以根据 mid=3，left=1 的串是否为回文串推导出来。但我们没有定义状态转移方程，很难发现这种重复的结构。我们并不能很清晰的感知到，在计算 mid=3，left=1 时，它的意义是什么，它的结果是否可以复用，我们是否需要缓存这个临时结果。
子问题的划分，让我们搜索过程中的每一步计算都有了明确的定义，而不只是一味的面向搜索进行计算。这样我们可以更加方便的发现解空间中的重复结构，避免重复计算。 

相比于暴力搜索，分治的问题规模与解空间的大小完全没有区别。但避免重复计算这一点好处，足够我们优先考虑分治。

下面是分治的代码，leetcode 中已提交通过：
```
    int maxLength = 0;
    String ans = "";

    public final String longestPalindromeDP(String s) {
        if (s == null || s.length() == 0) {
            return "";
        }
        int length = s.length();
        int[][] cache = new int[length][length];
        dp(s, 0, length - 1, cache);
        if (maxLength == 0) {
            return s.substring(0, 1);
        }
        return ans;
    }

    private final boolean dp(String source, int left, int right, int[][] cache) {
        if (left >= right) {
            return true;
        }
        if (cache[left][right] == 1) {
            return true;
        }
        if (cache[left][right] == -1) {
            return false;
        }
        char leftChar = source.charAt(left);
        char rightChar = source.charAt(right);
        //头尾不相等，尝试其它可能
        if (leftChar != rightChar) {
            dp(source, left, right - 1, cache);
            dp(source, left + 1, right, cache);
            cache[left][right] = -1;
            return false;
        }
        //头尾相等，判断去掉头尾的子串是否是回文串
        boolean childIsSubstring = dp(source, left + 1, right - 1, cache);
        if (childIsSubstring == false) {
            dp(source, left, right - 1, cache);
            dp(source, left + 1, right, cache);
            cache[left][right] = -1;
            return false;
        }
        //子串是回文串，则直接判断结果。即使尝试其它可能，也不会比主串长度长,所以没有尝试其它可能的必要。
        int length = right - left + 1;
        if (length > maxLength) {
            maxLength = length;
            ans = source.substring(left, right + 1);
        }
        cache[left][right] = 1;
        return true;
    }

```

   