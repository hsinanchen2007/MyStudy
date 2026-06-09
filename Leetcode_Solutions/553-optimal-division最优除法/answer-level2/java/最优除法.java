#### 方法 1：暴力 [Accepted]

**算法**

这题的暴力方法是将列表分成 $left$ 和 $right$ 两部分并分别对它们调用函数。我们从 $start$ 到 $end$ 遍历 $i$ 并得到 $left=(start,i)$ 和 $right=(i+1,end)$。

$left$ 和 $right$ 分别返回它们对应部分的最大和最小值和它们对应的字符串。

最小值可以通过左边部分的最小值除以右边部分的最大值得到，也就是 $minVal=left.min/right.max$。

类似的，最大值可以通过左边部分的最大值除以右边部分的最小值得到，也就是 $maxVal=left.max/right.min$。

现在，怎么添加括号呢？由于出发运算是从左到右的，也就是最左边的除法默认先执行，所以我们不需要给左边部分添加括号，但我们需要给右边部分添加括号。

比方假设左边部分是 "2" ，右边部分是 "3/4"，那么结果字符串 "2/(3/4)" 对应的是 左边部分+"/"+"("+右边部分+")"。

还有一点，如果右边部分只有一个数字，我们也不需要添加括号。

也就是说，如果左边部分是 "2" 且右边部分是 "3" （只包含单个数字），那么答案应该是 "2/3" 而不是 "2/(3)"。

```Java []
public class Solution {
    public String optimalDivision(int[] nums) {
        T t = optimal(nums, 0, nums.length - 1, "");
        return t.max_str;
    }
    class T {
        float max_val, min_val;
        String min_str, max_str;
    }
    public T optimal(int[] nums, int start, int end, String res) {
        T t = new T();
        if (start == end) {
            t.max_val = nums[start];
            t.min_val = nums[start];
            t.min_str = "" + nums[start];
            t.max_str = "" + nums[start];
            return t;
        }
        t.min_val = Float.MAX_VALUE;
        t.max_val = Float.MIN_VALUE;
        t.min_str = t.max_str = "";
        for (int i = start; i < end; i++) {
            T left = optimal(nums, start, i, "");
            T right = optimal(nums, i + 1, end, "");
            if (t.min_val > left.min_val / right.max_val) {
                t.min_val = left.min_val / right.max_val;
                t.min_str = left.min_str + "/" + (i + 1 != end ? "(" : "") + right.max_str + (i + 1 != end ? ")" : "");
            }
            if (t.max_val < left.max_val / right.min_val) {
                t.max_val = left.max_val / right.min_val;
                t.max_str = left.max_str + "/" + (i + 1 != end ? "(" : "") + right.min_str + (i + 1 != end ? ")" : "");
            }
        }
        return t;
    }
}
```

**复杂度分析**

* 时间复杂度： $O(n!)$。添加了括号以后所有表达式的数目为 $O(n!)$，其中 $n$ 是列表中元素的数目。

* 空间复杂度： $O(n^2)$。递归树的深度为 $O(n)$ 且每一个节点都最多包含 $O(n)$ 长度的字符串。

#### 方法 2：使用记忆化 [Accepted]

**算法**

上述方法中，我们对于每个 $start$ 和 $end$ 递归地使用了 optimal 函数。我们注意到有许多冗余的调用，所以我们使用记忆化的方法将相同参数的调用记录下来。这里 $memo$ 数组就是为了实现这一目的。

```Java []
public class Solution {
    class T {
        float max_val, min_val;
        String min_str, max_str;
    }
    public String optimalDivision(int[] nums) {
        T[][] memo = new T[nums.length][nums.length];
        T t = optimal(nums, 0, nums.length - 1, "", memo);
        return t.max_str;
    }
    public T optimal(int[] nums, int start, int end, String res, T[][] memo) {
        if (memo[start][end] != null)
            return memo[start][end];
        T t = new T();
        if (start == end) {
            t.max_val = nums[start];
            t.min_val = nums[start];
            t.min_str = "" + nums[start];
            t.max_str = "" + nums[start];
            memo[start][end] = t;
            return t;
        }
        t.min_val = Float.MAX_VALUE;
        t.max_val = Float.MIN_VALUE;
        t.min_str = t.max_str = "";
        for (int i = start; i < end; i++) {
            T left = optimal(nums, start, i, "", memo);
            T right = optimal(nums, i + 1, end, "", memo);
            if (t.min_val > left.min_val / right.max_val) {
                t.min_val = left.min_val / right.max_val;
                t.min_str = left.min_str + "/" + (i + 1 != end ? "(" : "") + right.max_str + (i + 1 != end ? ")" : "");
            }
            if (t.max_val < left.max_val / right.min_val) {
                t.max_val = left.max_val / right.min_val;
                t.max_str = left.max_str + "/" + (i + 1 != end ? "(" : "") + right.min_str + (i + 1 != end ? ")" : "");
            }
        }
        memo[start][end] = t;
        return t;
    }
}
```

**复杂度分析**

* 时间复杂度： $O(n^3)$。 $memo$ 数组的大小为 $n^2$ 且每一项的计算需要 $O(n)$ 的时间。

* 空间复杂度度： $O(n^3)$。 $memo$ 数组的大小为 $n^2$，其中数组的每一个元素的长度都是 $O(n)$ 的。

#### 方法 3：利用数学 [Accepted]

**算法**

使用一些简单的数学技巧，我们可以找到解决这个问题的简单解法。考虑输入形如 [a,b,c,d] 的列表，我们需要设置一些运算优先级来最大化 a/b/c/d。我们知道为了最大化 $p/q$，分母 $q$ 应该最小化，所以为了最大化 $a/b/c/d$ 我们首先需要最小化 b/c/d，现在我们的目标变成了最小化表达式 b/c/d。

有 2 种可能的表达式组合方法，分别是 b/(c/d) 和 (b/c)/d。
```
b/(c/d)        (b/c)/d = b/c/d
(b*d)/c        b/(d*c)
d/c            1/(d*c)
```

显然，对于 $d>1$ 我们有 $d/c > 1/(d*c)$。

我们可以发现只要数字大于 $1$，第二种组合肯定比第一种组合要小。所以答案是 $a/(b/c/d)$。类似的，对于形如 a/b/c/d/e/f... 的表达式，答案将是 a/(b/c/d/e/f...)。

```Java []
public class Solution {
    public String optimalDivision(int[] nums) {
        if (nums.length == 1)
            return nums[0] + "";
        if (nums.length == 2)
            return nums[0] + "/" + nums[1];
        StringBuilder res = new StringBuilder(nums[0] + "/(" + nums[1]);
        for (int i = 2; i < nums.length; i++) {
            res.append("/" + nums[i]);
        }
        res.append(")");
        return res.toString();
    }
}
```

**复杂度分析**

* 时间复杂度： $O(n)$。只需要遍历数组 $nums$ 一遍。

* 空间复杂度： $O(n)$。使用 $res$ 变量来保存答案。
