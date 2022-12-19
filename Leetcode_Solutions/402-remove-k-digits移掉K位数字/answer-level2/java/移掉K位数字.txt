####  方法一：暴力法 [超出时间限制]
我们最容易想到的是列举所有可能的组合，并找出其中最小的数字，即暴力法。

经过了一会儿的思考，我们很快就会排除这种方法，主要原因是：我们从 $N$ 个数字中选择 $K$ 个数字的组合，将具有指数的时间复杂度，即 $C_{n}^{k}$，即使是测试用例也可能超出时间限制。

除了复杂性问题之外，在暴力法中需要解决的另一个问题是比较两个数字串的值。我们可以将数字字符串转换为数值，但是这种方法是具有局限性的。对于一个无符号的 32 位整数，它所能容纳的最大值是一个具有 10 位数字（即 4294967295）。但是很多测试用例是由数百位数字组成的。

我们可以不将字符串转为整数，只需要从左到右逐个比较数字序列就可以了。

但是，这个问题应该有某种方法来构造答案，而不是列举所有可能的组合。


####  方法二：利用栈的贪心算法
对于两个相同长度的数字序列，最左边不同的数字决定了这两个数字的大小，例如，对于 `A = 1axxx`，`B = 1bxxx`，如果 `a > b` 则 `A > B`。

知道了这个以后，我们可以想到，在删除数字时应该从左向右迭代。

确定了迭代的顺序以后，就必须制定如何消除数字的标准，以便获得最小值。

![在这里插入图片描述](https://pic.leetcode-cn.com/ee8ec228112935ff01b80cd1d8dfa38c0ffb6a0b4f9f5c3e288d9dd919cb86fb-file_1578026872206){:width=400}


让我们从一个简单的例子开始。给定一个数字序列，例如 `425`，如果要求我们只删除一个数字，那么从左到右，我们有 `4`、`2` 和 `5` 三个选择。我们将每一个数字和它的左邻居进行比较。从 `2` 开始，小于它的左邻居 `4`。则我们应该去掉数字 `4`。如果不这么做，则随后无论做什么，都不会得到最小数。

如果我们保留数字 `4`，那么所有可能的组合都是以数字 `4`（即 `42`，`45`）开头的。相反，如果去掉 `4`，留下 `2`，我们得到的是以 `2` 开头的组合（即 `25`），这明显小于任何留下数字 `4` 的组合。

我们可以总结上述删除一个数字的规则，如下：
给定一个数字序列 $[D_1D_2D_3…D_n]$，如果数字 $D_2$ 小于其左邻居 $D_1$，则我们应该删除左邻居（$D_1$），以获得最小结果。

**算法：**

上述的规则使得我们通过一个接一个的删除数字，逐步的接近最优解。

这个问题可以用贪心算法来解决。上述规则阐明了我们如何接近最终答案的基本逻辑。一旦我们从序列中删除一个数字，剩下的数字就形成了一个新的问题，我们可以继续使用这个规则。

我们会注意到，在某些情况下，规则对任意数字都不适用，即单调递增序列。在这种情况下，我们只需要删除末尾的数字来获得最小数。

我们可以利用栈来实现上述算法，存储当前迭代数字之前的数字。
- 对于每个数字，如果该数字小于栈顶部，即该数字的左邻居，则弹出堆栈，即删除左邻居。否则，我们把数字推到栈上。
- 我们重复上述步骤（1），直到任何条件不再适用，例如堆栈为空（不再保留数字）。或者我们已经删除了 `k` 位数字。

![在这里插入图片描述](https://pic.leetcode-cn.com/14125c5da72706c6f30459f8ee0d28febe2fe2a1bd95a4dfc3a8697fe4e1a056-file_1578026872219){:width=400}


我们在上图中演示了该算法的工作原理。给定输入序列 `[1，2，3，4，5，2，6，4]` 和 `k=4`，规则在 `5` 触发。删除数字 `5` 后，规则将在数字 `4` 处再次触发，直到数字 `3`。然后，在数字 `6` 处，规则也被触发。

在上述主循环之外，我们需要处理一些情况，以使解决方案更加完整：
- 当我们离开主循环时，我们删除了 `m` 个数字，这比要求的要少，即（`m<k`）。在极端情况下，我们不会删除循环中单调递增序列的任何数字，即 `m==0`。在这种情况下，我们只需要从序列尾部删除额外的 `k-m` 个数字。
- 一旦我们从序列中删除 `k` 位数字，可能还有一些前导零。要格式化最后的数字，我们需要去掉前导零。
- 我们最终可能会从序列中删除所有的数字。在这种情况下，我们应该返回零，而不是空字符串。

```python [solution2-Python]
class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        numStack = []
        
        # Construct a monotone increasing sequence of digits
        for digit in num:
            while k and numStack and numStack[-1] > digit:
                numStack.pop()
                k -= 1
        
            numStack.append(digit)
        
        # - Trunk the remaining K digits at the end
        # - in the case k==0: return the entire list
        finalStack = numStack[:-k] if k else numStack
        
        # trip the leading zeros
        return "".join(finalStack).lstrip('0') or "0"
```

```java [solution2-Java]
class Solution {
  public String removeKdigits(String num, int k) {
    LinkedList<Character> stack = new LinkedList<Character>();
        
    for(char digit : num.toCharArray()) {
      while(stack.size() > 0 && k > 0 && stack.peekLast() > digit) {
        stack.removeLast();
        k -= 1;
      }
      stack.addLast(digit);
    }
        
    /* remove the remaining digits from the tail. */
    for(int i=0; i<k; ++i) {
      stack.removeLast();
    }
        
    // build the final string, while removing the leading zeros.
    StringBuilder ret = new StringBuilder();
    boolean leadingZero = true;
    for(char digit: stack) {
      if(leadingZero && digit == '0') continue;
      leadingZero = false;
      ret.append(digit);
    }
        
    /* return the final string  */
    if (ret.length() == 0) return "0";
    return ret.toString();
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(N)$。尽管存在嵌套循环，但内部循环最多只能运行 $k$ 次。由于 $0 < k \le N$，主循环的时间复杂度被限制在 $2N$ 以内。对于主循环之外的逻辑，它们的时间复杂度是 $\mathcal{O}(N)$。总时间复杂度为 $\mathcal{O}(N)$。
* 空间复杂度：$\mathcal{O}(N)$，在最坏的情况下栈存储了所有的数字。