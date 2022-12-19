## 概要

自从安卓使用“手势解锁”系统保护手机以免非授权使用之后，一个常被提及的问题是：这个图案的安全性到底有多高？本文将给出这个答案，以呈现以下算法：计算有多少种合法图案。这个算法面向初学者并介绍两个基本概念：回溯和数组。

## 题解

#### 方法：回溯

**算法**

算法适用回溯方法模拟所有可能的 $k$ 个数字 $[1…9]$ 的组合，其中 $m \leq k \leq n$。在构造递归搜索树的时候，算法会剪枝掉所有不满足规则的方案。

为了计算一个合法手势，算法按照如下步骤进行：

* 选择一个当前仍然未被使用的数字 $i$，这一步通过一个访问数组 $used$ 实现，保存所有可用数字。
* 我们需要记录上一个访问的数字 $last$。算法需要检查是否满足以下任一条件：
  * 从 $last$ 到 $i$ 之间是国际象棋中马的移动，或者 $last$ 和 $i$ 是同一行或列的相邻元素。这种情况下，两个数字之和应当为奇数。
  * 连接 $last$ 和 $i$ 的中间元素 $mid$ 已经被访问过，比方说 $last$ 和 $i$  选择的是对角线上的两点，那么中间点 $mid = 5$ 应当已经选过。
  * $last$ 和 $i$ 是对角线上的相邻元素。

假设上面有一个条件满足，数字 $i$ 就变成了合法手势的一部分，算法继续枚举下一个数字，知道整个手势图案被生成。最终计数总方案数。

加入没有任一条件符合，算法当前就不会选择数字 $i$，回溯然后继续在未使用的数字中搜索可行的数字。

![image.png](https://pic.leetcode-cn.com/6ff3556255ac4f503f4f82273bdfb135d724c1f52c805dcc1f7dead1d526eb72-image.png){:width=400}
{:align=center}


```java [-Java]
public class Solution {

    private boolean used[] = new boolean[9];

    public int numberOfPatterns(int m, int n) {	        
        int res = 0;
        for (int len = m; len <= n; len++) {	            
            res += calcPatterns(-1, len);
            for (int i = 0; i < 9; i++) {	                
                used[i] = false;
            }            
        }
        return res;
    }

    private boolean isValid(int index, int last) {
        if (used[index])
            return false;
        // first digit of the pattern    
        if (last == -1)
            return true;
        // knight moves or adjacent cells (in a row or in a column)	       
        if ((index + last) % 2 == 1)
            return true;
        // indexes are at both end of the diagonals for example 0,0, and 8,8          
        int mid = (index + last)/2;
        if (mid == 4)
            return used[mid];
        // adjacent cells on diagonal  - for example 0,0 and 1,0 or 2,0 and //1,1
        if ((index%3 != last%3) && (index/3 != last/3)) {
            return true;
        }
        // all other cells which are not adjacent
        return used[mid];
    }

    private int calcPatterns(int last, int len) {
        if (len == 0)
            return 1;    
        int sum = 0;
        for (int i = 0; i < 9; i++) {
            if (isValid(i, last)) {
                used[i] = true;
                sum += calcPatterns(i, len - 1);
                used[i] = false;                    
            }
        }
        return sum;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n!)$，其中 $n$ 是最大手势长度。

  算法计算每个手势一次，没有数字在手势中出现两次。时间复杂度和手势中出现的数字成正比，所以可能组合的上界是：

$$
\ \sum_{i=m}^{n} A_9^i = \ \sum_{i=m}^{n} \frac{9!}{(9 - i)!}
$$

* 空间复杂度：$O(n)$，其中 $n$ 是最大手势长度。

  最坏情况下最大迭代深度为 $n$，因此需要 $O(n)$ 空间存储栈。

## 思考

如果利用对称的性质可以优化算法，我们发现从数字 1, 3, 7, 9 出发的手势是相同的，同理从 2, 4, 6, 8 出发的也是。因此对这些相同的组我们只需要对结果乘以 4 即可。