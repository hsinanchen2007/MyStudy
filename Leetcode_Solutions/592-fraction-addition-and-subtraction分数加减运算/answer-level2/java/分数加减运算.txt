#### 方法一：全部通分

首先我们需要预处理整个字符串，将它拆分成若干个分数和符号。我们通过 `+` 和 `-` 将字符串拆分成若干个分数，并将 `+` 和 `-` 依次存放在符号数组中。随后对于每一个分数，我们通过 `/` 将其拆分成分子和分母部分，并存储到数组中。接下来我们就可以通过分数的加减法得到最终的结果了。

在进行分数加减时，我们可以先将这些分数的分母全部通分，再对分子进行加减，例如：

$\frac{3}{2} + \frac{5}{3} - \frac{7}{6}$

可以变成：

$\frac{9}{6} + \frac{10}{6} - \frac{7}{6}$

要计算出通分后分母的值，我们需要计算出所有分母的最小公倍数 `LCM`。两个数的最小公倍数等于它们的乘积除以它们的最大公约数 `GCD`，即 `LCM(a, b) = a * b / GCD(a, b)`。在计算多个数的最小公倍数时，我们可以先计算出前两个数的最小公倍数，再计算出其与第三个数的最小公倍数，以此类推，即 `LCM(a, b, c, d) = LCM(LCM(LCM(a, b), c), d)`，这样我们就可以很方便地计算出分母的值。在这之后，我们对所有分数进行通分，对分子进行加减，就可以得到答案。

注意此时的答案可能没有化成最简形式（没有约分），在上面的例子中，答案是 $\frac{12}{6}$，应当约分成 $\frac{2}{1}$。因此在得到答案后，我们还需要计算出分子和分母的最大公约数，将答案约分成最简形式。

``` Java [sol1]
public class Solution {
    public String fractionAddition(String expression) {
        List < Character > sign = new ArrayList < > ();
        for (int i = 1; i < expression.length(); i++) {
            if (expression.charAt(i) == '+' || expression.charAt(i) == '-')
                sign.add(expression.charAt(i));
        }
        List < Integer > num = new ArrayList < > ();
        List < Integer > den = new ArrayList < > ();
        for (String sub: expression.split("\\+")) {
            for (String subsub: sub.split("-")) {
                if (subsub.length() > 0) {
                    String[] fraction = subsub.split("/");
                    num.add(Integer.parseInt(fraction[0]));
                    den.add(Integer.parseInt(fraction[1]));
                }
            }
        }
        if (expression.charAt(0) == '-')
            num.set(0, -num.get(0));
        int lcm = 1;
        for (int x: den) {
            lcm = lcm_(lcm, x);
        }

        int res = lcm / den.get(0) * num.get(0);
        for (int i = 1; i < num.size(); i++) {
            if (sign.get(i - 1) == '+')
                res += lcm / den.get(i) * num.get(i);
            else
                res -= lcm / den.get(i) * num.get(i);
        }
        int g = gcd(Math.abs(res), Math.abs(lcm));
        return (res / g) + "/" + (lcm / g);
    }
    public int lcm_(int a, int b) {
        return a * b / gcd(a, b);
    }
    public int gcd(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N\log C)$，其中 $N$ 是字符串中分数的个数，$\log C$ 来源于计算最大公约数的时间复杂度，虽然在这道题中，分子和分母的范围不是很大，但需要时刻牢记计算最大公约数的时间复杂度并不是 $O(1)$。

* 空间复杂度：$O(N)$，用来存储分子，分母和符号。也可以优化到 $O(1)$。

#### 方法二：逐个通分

方法一存在一个缺点，就是当分母的范围较大时，将所有分数通分会导致得到的分母整数溢出（虽然在这道题中，分母的范围是 `[1, 10]` 的正整数，不会出现溢出的情况），因此我们可以考虑每次只对两个分数进行通分，计算出它们相加或相减的最简结果后，再跟下一个分数进行通分并计算，以此类推。假设我们需要计算

$\frac{a}{b} + \frac{c}{d}$

的值，可以先算出 `b` 和 `d` 的最小公倍数 `LCM`，设 `x = LCM / b`，`y = LCM / d`，即有

$\frac{a}{b} + \frac{c}{d} = \frac{a * x + c * y}{b * d / \text{LCM}}$

随后将结果进行约分，并继续计算即可。

```Java [sol2]
public class Solution {
    public String fractionAddition(String expression) {
        List < Character > sign = new ArrayList < > ();
        if (expression.charAt(0) != '-')
            sign.add('+');
        for (int i = 0; i < expression.length(); i++) {
            if (expression.charAt(i) == '+' || expression.charAt(i) == '-')
                sign.add(expression.charAt(i));
        }
        int prev_num = 0, prev_den = 1, i = 0;
        for (String sub: expression.split("(\\+)|(-)")) {
            if (sub.length() > 0) {
                String[] fraction = sub.split("/");
                int num = (Integer.parseInt(fraction[0]));
                int den = (Integer.parseInt(fraction[1]));
                int g = Math.abs(gcd(den, prev_den));
                if (sign.get(i++) == '+')
                    prev_num = prev_num * den / g + num * prev_den / g;
                else
                    prev_num = prev_num * den / g - num * prev_den / g;
                prev_den = den * prev_den / g;
                g = Math.abs(gcd(prev_den, prev_num));
                prev_num /= g;
                prev_den /= g;
            }
        }
        return prev_num + "/" + prev_den;
    }
    public int gcd(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N\log C)$，其中 $N$ 是字符串中分数的个数，$\log C$ 来源于计算最大公约数的时间复杂度，虽然在这道题中，分子和分母的范围不是很大，但需要时刻牢记计算最大公约数的时间复杂度并不是 $O(1)$。

* 空间复杂度：$O(N)$，用来存储分子，分母和符号。也可以优化到 $O(1)$。