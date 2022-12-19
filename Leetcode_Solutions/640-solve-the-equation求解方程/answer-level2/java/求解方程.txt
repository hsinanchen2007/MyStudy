#### 方法一：拆分方程【通过】

首先使用 `=` 将方程左右两边拆分开，然后使用方法 `breakIt` 分别遍历方程的左右两边，解析出其中的数字和 `x`，并将结果以数组的形式返回。

对任意一个给定的方程，将其转换为所有的 `x` 都在 `=` 左侧，所有的数字都在 `=` 右侧，如下所示。

`x+5-3+x=6+x-2`

`x+x-x=6-2-5+3`

把在原始方程左边的 `x` 看做正值，右边的 `x` 看做负值。同理，原始方程左边每个数字都被看做负数，右边每个数字都看作正数。那么 $lhs$ 包含了方程中所有的 `x`，$rhs$ 包含了方程中所有的数字。

此外，在解析 `x` 的同时，也需要确定 `x` 转换到左边后的系数；同理也需要确定数字转换到右边的符号。

最后通过 $rhs$ 和 $lhs$ 的比值得到最终结果。如果方程有无限解，则 $lhs$ 和 $rhs$ 都为 0，例如 `x+1=x+1`；如果方程无解，则 `x` 的系数（$lhs$）为 0，有效数字（$rhs$）不为 0。

```java [solution1-Java]
public class Solution {
    public String coeff(String x) {
        if (x.length() > 1 && x.charAt(x.length() - 2) >= '0' && x.charAt(x.length() - 2) <= '9')
            return x.replace("x", "");
        return x.replace("x", "1");
    }
    public String solveEquation(String equation) {
        String[] lr = equation.split("=");
        int lhs = 0, rhs = 0;
        for (String x: breakIt(lr[0])) {
            if (x.indexOf("x") >= 0) {
                lhs += Integer.parseInt(coeff(x));
            } else
                rhs -= Integer.parseInt(x);
        }
        for (String x: breakIt(lr[1])) {
            if (x.indexOf("x") >= 0)
                lhs -= Integer.parseInt(coeff(x));
            else
                rhs += Integer.parseInt(x);
        }
        if (lhs == 0) {
            if (rhs == 0)
                return "Infinite solutions";
            else
                return "No solution";
        }
        return "x=" + rhs / lhs;
    }
    public List < String > breakIt(String s) {
        List < String > res = new ArrayList < > ();
        String r = "";
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '+' || s.charAt(i) == '-') {
                if (r.length() > 0)
                    res.add(r);
                r = "" + s.charAt(i);
            } else
                r += s.charAt(i);
        }
        res.add(r);
        return res;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n)$，计算 $lhs$ 和 $rhs$ 需要时间 $O(n)$。

* 空间复杂度：$O(n)$，数组 $res$ 的长度最大为 $n$。 


#### 方法二：使用正则表达式拆分方程【通过】

**算法**

在 *方法一* 中，使用方法 `beankIt` 拆分方程两边的每一项。本方法中使用 `+` 或 `-` 拆分，其他步骤与方法一相同。

正则表达式用于根据特定条件匹配目标字符串，所以也可以使用正则表达式（regex）拆分方程的每一项。例如正则表达式 `?=n` 表示匹配到的字符串后面必须有 `n`，但 `n` 本身不在匹配到的字符串中。

为了确保拆分后的数字具有正负号，因此 `+` 或 `-` 在拆分后也应该与对应的数字一起保留。

```java [solution2-Java]
public class Solution {
    public String coeff(String x) {
        if (x.length() > 1 && x.charAt(x.length() - 2) >= '0' && x.charAt(x.length() - 2) <= '9')
            return x.replace("x", "");
        return x.replace("x", "1");
    }
    public String solveEquation(String equation) {
        String[] lr = equation.split("=");
        int lhs = 0, rhs = 0;
        for (String x: lr[0].split("(?=\\+)|(?=-)")) {
            if (x.indexOf("x") >= 0) {

                lhs += Integer.parseInt(coeff(x));
            } else
                rhs -= Integer.parseInt(x);
        }
        for (String x: lr[1].split("(?=\\+)|(?=-)")) {
            if (x.indexOf("x") >= 0)
                lhs -= Integer.parseInt(coeff(x));
            else
                rhs += Integer.parseInt(x);
        }
        if (lhs == 0) {
            if (rhs == 0)
                return "Infinite solutions";
            else
                return "No solution";
        } else
            return "x=" + rhs / lhs;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n)$，计算 $lhs$ 和 $rhs$ 需要时间 $O(n)$。

* 空间复杂度：$O(n)$，数组 $res$ 的长度最大为 $n$。