#### 方法一：回溯
让我们先看看这个问题要求我们做什么，然后才能找到解决它的方法。因此，我们得到一个数字串和 3 个不同的运算符： 
+ `+` Addition
- `-` Subtraction 
* `*` Multiplication

我们必须找到数字之间所有可能的二元运算符组合，以便结果表达式的整体值等于给定的目标值。让我们来看看将运算符放在数字之间的确切含义的几个可能性，这样问题就更清楚了。 

假设我们有以下一组数字 `“123456789”`，给我们的目标值是 `45`。让我们看看通过将操作符放在不同的位置可以得到的一些可能的结果表达式。 

```
1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 = 45
1 + 2 - 3 + 4 - 5 + 6 - 7 + 8 - 9 = -3
1 + 2 * 3 - 4 + 5 + 6 - 7 * 8 - 9 = -51
1 + 2 + 3 + 4 + 5 - 6 * 7 + 8 * 9 = 45
```

这只是使用给定的数字串和三个运算符可能得到的许多表达式中的 4 个。 

通过查看上面的例子，我们无法真正找出结果表达式中的任何特定模式，这些模式告诉我们哪一个表达式将给出结果目标。 

由于这个问题明确地说明我们有二元运算符，这意味着每个运算符都需要两个操作数。 我们可以把每个数字都当作操作数。 

这意味着，在每对数字之间，我们可以使用三个运算符中的任何一个，即 $+$、$-$ 或$\times$。 

如果你看过问题陈述和问题中给出的例子，你会发现有一个例子，数字是 `“105”`，目标值是 `5`。对于这个特殊的例子，有两个表达式给我们，它们是 `1*0+5` 和 `10-5`。

第二个表达式是在解决这个问题之前需要注意的，因为这会使事情变得有点复杂。 

如果我们只需要考虑那些简单地用数字作为操作数的表达式，那么这个问题就更容易解决了。 

但是，在这个问题中，我们可以让各种数字组合在一起，形成一个更大的数字，成为表达式的一部分。让我们看看数字 `“123456”` 和目标 `30` 的一些示例表达式。

```
1 * 23 - 4 + 5 + 6 = 30
12 - 3 * 4 + 5 * 6 = 30
1 - 23 - 4 + 56 = 30
```
这意味着，尽管我们定义了运算符的数量，即3个不同的二元运算符，但是操作数的数量并没有很好地为我们定义。 

这是我们在解决方案中需要解决的原始问题的很大一部分。 

因为我们被要求找出所有值等于给定目标的有效表达式，而且我们不知道两个操作数之间的特定运算符最终会给我们一个有效表达式， 

> 我们尝试所有的选择

这意味着一旦我们定义了给定表达式的操作数，我们就可以在每个连续的操作数对之间选择三个可能的操作数。

从实现的角度来看，操作数对于原始字符串意味着什么？

> 操作数是由原始字符串的子字符串形成的整数

让我们来看看字符串 “123456789” 的两种不同的数组分割方式：

![image.png](https://pic.leetcode-cn.com/9991efd737c5d5e8fe429cf0a62874240eb1053ea09086589a09fdedc274e134-image.png){:width="500"}
{:align=center}

由于我们需要返回所有有效表达式，这些表达式的计算结果为给定的目标值，因此我们必须尝试给定数组的所有可能分区，从而考虑所有可能的操作数，这些操作数可以由数字组成。

有一种非常简单的方法可以将此合并到我们的算法中。现在，在算法的每一点上，我们都有三个不同的选择对应于三个不同的操作符。  

> 我们合并这些分区的方法是考虑第四个运算符，它只向前移动一步，将当前操作数扩展一位。实际上，在我们的实现中，从 $12 --> 123$ 开始是一个无操作操作数。$(12*10)+3$。 

现在，我们的算法中有4个不同的递归路径，我们必须尝试所有这些路径，看看哪一个会导致潜在的解决方案。

**算法：**
在查看伪代码之前，让我们先快速查看回溯算法中涉及的步骤。 
1.  如上所述，我们有多种选择，可以选择使用什么运算符，可以选择哪些操作数，因此，我们必须考虑找到所有有效表达式的所有可能性。 
2. 我们的递归调用 `index` ，它表示我们在原始 `nums` 字符串中看到的当前数字，以及到目前为止构建的表达式字符串。 
3. 在每一步中，我们都有 4 个不同的递归调用。`NO OP` 调用只是将当前的操作数扩展到当前数字并向前移动。其余的递归调用对应于`+`、`-`、和 `*`。
4. 我们继续这样构建表达式，最终会处理整个 `nums` 字符串。那时，我们检查到现在为止构建的表达式是否是有效的表达式，如果是有效的表达式，我们会记录它。

```
1. procedure recurse(digits, index, expression):
2.     if we have reached the end of the string:
3.         if the expression evaluates to the target:
4.             Valid Expression found!
5.     else:
6.         try out operator 'NO OP' and recurse
7.         try out operator * and recurse
8.         try out operator + and recurse
9.         try out operator - and recurse
```
算法现在看起来非常简单。然而，实现需要更多的思考，在实际实现之前，我们需要解决一些问题。

> 当我们用原始字符串中的所有数字构建表达式时，我们检查表达式是否是有效的表达式。我们如何实际检查该表达式是否有效？

一种方法是编写一个自定义的 `eval` 函数，它接受一个字符串并返回表达式的值。如果这样做（python 用户可以使用内置函数 `eval` ），您将超过时间限制。 

**我们不能实时跟踪表达式的值吗？**

是的。这就是我们要遵循的理念。除了跟踪表达式字符串是什么，我们还将跟踪它的值，以便当递归到达基本情况时，我们可以通过 $O(1)$ 的时间复杂度来判断表达式是否等于目标值

如果只是 `+` 和 `-` 运算符参与的话，实现会很简单。这是因为这两个操作符具有相同的优先级。这意味着我们可以继续动态地评估表达式，而不会出现任何问题。

![image.png](https://pic.leetcode-cn.com/1f544cad15ffd3e171f391b2045d0881456f20acca486b0421d997961dfdb400-image.png){:width="500"}
{:align=center}


若添加 * 操作符，看看如何快速构建表达式。 

![image.png](https://pic.leetcode-cn.com/29bb5bb5c19287645b123cbd0bfd7711a15522f9c51d6fd085537b1cd5343e4a-image.png){:width="500"}
{:align=center}


我们所说的动态构建表达式是指我们一直跟踪表达式的值，直到现在，我们只是将该值作为我们的运算符的两个操作数之一。正如我们从上面的两个例子中看到的，如果它只是 `+` 和 `-` 操作符，那么这就可以工作了。

但是，这种方法肯定会失败，因为 `*` 运算符优先于 `+ `和 `-`。`*` 运算符需要表达式中实际的前一个操作数，而不是表达式的当前值。也就是说，在上面的例子中，`*` 运算符需要 `2` 而不是 `12` 才能得到正确的值 `18`。 

**如何处理？** 
如何处理这个问题的想法来源于上面的讨论。我们只需要跟踪表达式中的最后一个操作数，以及它是如何整体修改表达式的值的，这样当我们考虑 `*` 运算符时，我们可以反转前一个操作数的效果，并考虑它的乘法。让我们来看一下以前打破的例子。 

![image.png](https://pic.leetcode-cn.com/a2663dc89bbf7ed3241c2d2bdf05e19092f5ada0cca3ce9c6659f4c2d684ace7-image.png){:width="500"}
{:align=center}


现在我们可以看看这个算法的实际实现。 

```Java [ ]
class Solution {

  public ArrayList<String> answer;
  public String digits;
  public long target;

  public void recurse(
      int index, long previousOperand, long currentOperand, long value, ArrayList<String> ops) {
    String nums = this.digits;

    // Done processing all the digits in num
    if (index == nums.length()) {

      // If the final value == target expected AND
      // no operand is left unprocessed
      if (value == this.target && currentOperand == 0) {
        StringBuilder sb = new StringBuilder();
        ops.subList(1, ops.size()).forEach(v -> sb.append(v));
        this.answer.add(sb.toString());
      }
      return;
    }

    // Extending the current operand by one digit
    currentOperand = currentOperand * 10 + Character.getNumericValue(nums.charAt(index));
    String current_val_rep = Long.toString(currentOperand);
    int length = nums.length();

    // To avoid cases where we have 1 + 05 or 1 * 05 since 05 won't be a
    // valid operand. Hence this check
    if (currentOperand > 0) {

      // NO OP recursion
      recurse(index + 1, previousOperand, currentOperand, value, ops);
    }

    // ADDITION
    ops.add("+");
    ops.add(current_val_rep);
    recurse(index + 1, currentOperand, 0, value + currentOperand, ops);
    ops.remove(ops.size() - 1);
    ops.remove(ops.size() - 1);

    if (ops.size() > 0) {

      // SUBTRACTION
      ops.add("-");
      ops.add(current_val_rep);
      recurse(index + 1, -currentOperand, 0, value - currentOperand, ops);
      ops.remove(ops.size() - 1);
      ops.remove(ops.size() - 1);

      // MULTIPLICATION
      ops.add("*");
      ops.add(current_val_rep);
      recurse(
          index + 1,
          currentOperand * previousOperand,
          0,
          value - previousOperand + (currentOperand * previousOperand),
          ops);
      ops.remove(ops.size() - 1);
      ops.remove(ops.size() - 1);
    }
  }

  public List<String> addOperators(String num, int target) {

    if (num.length() == 0) {
      return new ArrayList<String>();
    }

    this.target = target;
    this.digits = num;
    this.answer = new ArrayList<String>();
    this.recurse(0, 0, 0, 0, new ArrayList<String>());
    return this.answer;
  }
}
```

```Python [ ]
class Solution:
    def addOperators(self, num: 'str', target: 'int') -> 'List[str]':

        N = len(num)
        answers = []
        def recurse(index, prev_operand, current_operand, value, string):

            # Done processing all the digits in num
            if index == N:

                # If the final value == target expected AND
                # no operand is left unprocessed
                if value == target and current_operand == 0:
                    answers.append("".join(string[1:]))
                return

            # Extending the current operand by one digit
            current_operand = current_operand*10 + int(num[index])
            str_op = str(current_operand)

            # To avoid cases where we have 1 + 05 or 1 * 05 since 05 won't be a
            # valid operand. Hence this check
            if current_operand > 0:

                # NO OP recursion
                recurse(index + 1, prev_operand, current_operand, value, string)

            # ADDITION
            string.append('+'); string.append(str_op)
            recurse(index + 1, current_operand, 0, value + current_operand, string)
            string.pop();string.pop()

            # Can subtract or multiply only if there are some previous operands
            if string:

                # SUBTRACTION
                string.append('-'); string.append(str_op)
                recurse(index + 1, -current_operand, 0, value - current_operand, string)
                string.pop();string.pop()

                # MULTIPLICATION
                string.append('*'); string.append(str_op)
                recurse(index + 1, current_operand * prev_operand, 0, value - prev_operand + (current_operand * prev_operand), string)
                string.pop();string.pop()
        recurse(0, 0, 0, 0, [])    
        return answers
```

**复杂度分析**

* 时间复杂度：
1. 在这一过程的每一步中，我们都会考虑 4 种不同的选择或 4 种不同的递归路径。基本情况是当索引值达到 $N$ 时，即 `nums` 数组的长度。因此，我们的复杂性将是$O(4^n)$。 
2. 对于基本情况，我们在 Java 中使用了 `StringBuilder::toString` 函数和在 Python 中使用了 `.join()`  函数花费了 $O(N)$ 时间。这里 $N$ 表示了表达式的长度。在最坏的情况下，每个数字都是一个操作数，我们有 $N$ 个数字和 $N-1$ 个运算符。所以 $O(N)$是对于一个表达式。在最坏的情况下，我们可以有 $O(4^n)$ 有效表达式。
* 空间复杂度：
1. 对于 Python 和 Java 实现，我们有一个列表数据结构，我们只在有效的表达式中更新，我们创建一个新的字符串并添加到我们的答案数组中。因此，中间列表所占的空间将是 $O(n)$ ,因为在最坏的情况下，表达式将从所有数字中构建为操作数。 
2. 由于递归堆栈的大小由索引的值决定，因此递归堆栈占用的空间也将为 $O(n)$ 并且从 $0$ 一直到 $N$ 不等。