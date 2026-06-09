#### 方法 1：暴力 [Time Limit Exceeded]

暴力方法非常简单，我们从 $1$ 到 $num$ 遍历所有整数，对于每个数字，我们检查这个数字二进制形式是否包含连续 1。如果没有，我们增加没有连续 1 的数字数目 $count$。

为了检查某个数 $n$ 在位置 $x$ 是否存在 $1$ （从最低位开始考虑起），我们可以将 $1$ 左移 $x-1$ 次得到数字 $y$，它只在第 $x$ 位有一个 $1$，其他位都是 $0$。现在将 $n$ 和 $y$ 进行逻辑与运算，如果得到的结果非 0，那么说明 $n$ 在第 $x$ 位置是 $1$ 。

```Java []
public class Solution {
    public int findIntegers(int num) {
        int count = 0;
        for (int i = 0; i <= num; i++)
            if (check(i))
                count++;
        return count;
    }
    public boolean check(int n) {
        int i = 31;
        while (i > 0) {
            if ((n & (1 << i)) != 0 && (n & (1 << (i - 1))) != 0)
                return false;
            i--;
        }
        return true;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(32*n)$。我们需要将 $0$ 到 $n$ 的每个数字的 32 个数位都检查一遍$，这里 $n$ 是给定的数字。

* 空间复杂度：$O(1)$。只是用了常数空间。

#### 方法 2：优化的暴力 [Time Limit Exceeded]

**算法**

在上一种方法中，我们遍历了每一个数字并检查它是否包含连续的 1。与其这样做，我们可以仅生成需要的数字，也就是我们从低位到高位生成数字，比方说我们在第三位已经生成了 `110`，已经包含了连续 1，那么我们没有必要继续生成更高位的数字 `1110` 或者 `0110`。

我们从最低位开始逐位添加 `0` 或者 `1`。最开始的时候初始数字只包含一位，所以不会有任何连续的 1。接下来我们考虑前一位，如果最低位是 `0`，那么我们前一位可以是 `1` 也可以是 `0`，分别得到 `10` 和 `00`。

但如果我们最开始的一个数字是 `1`，那么我们只能在它前面加一个 `0` 产生 `01` 而不包含任何连续的 `1`。按照这个想法，我们需要记录一下最后一个添加的数字是 `0` 还是 `1`，如果是 `0`，那么前一位可以是 `0` 也可以是 `1`。以此类推，我们可以继续用 `00`，`01` 和 `10` 来产生再前一位的数字。

为了得到小于 $num$ 且不包含连续 1 的数字个数，我们基于前面的讨论，使用递归函数 `find(i, sum, num, prev)`。这个函数返回 $i$ 位没有连续 1 的二进制数的数目，这里的 $sum$ 记录当前为止产生的二进制数字。 $num$ 是给定的数字，$prev$ 是一个表示最后添加的数字是 `1` 或者 `0` 的 boolean 类型变量。

如果最后添加的字符是 `0`，我们在前面可以添加 `1` 或者 `0`，所以我们会调用函数 `find(i + 1, sum, num ,false) + find(i + 1, sum + (1<<i), num ,true)`，第一部分表示在第 $i$ 个位置添加了 `0`，所以 $prev$ 是 `false`，第二部分表示在第 $i$ 个位置添加了 `1`，所以 $prev$ 是 `true`。

如果最后添加的字符是 `1`，我们只能在前面加 `0`，所以只能调用函数 `find(i + 1, sum, num, false)`。

当前的数字 $sum$ 超过给定数字 $num$ 的时候，我们停止迭代。

![image.png](https://pic.leetcode-cn.com/43130a71552a422af22f16993ea4fb60571fefe6aa244c2bc5ded6598c89d7f0-image.png){:width=600}
{:align=center}

```Java []
public class Solution {
    public int findIntegers(int num) {
        return find(0, 0, num, false);
    }
    public int find(int i, int sum, int num, boolean prev) {
        if (sum > num)
            return 0;
        if (1<<i > num)
            return 1;
        if (prev)
            return find(i + 1, sum, num, false);
        return find(i + 1, sum, num, false) + find(i + 1, sum + (1 << i), num, true);
    }
}
```

**复杂度分析**

* 时间复杂度：$O(x)$。只会生成 $x$ 个数字，$x$ 是返回的结果。

* 空间复杂度：$O(log(max\_int)=32)$。递归树的深度最多为 $32$。

#### 方法 3：使用位操作 [Accepted]

**算法**

在我们讨论这一方法之前，我们考虑另一种简单的想法。

假设我们要找到 $n$ 位不包含连续 1 的数字，我们可以用递归的视角看待这个问题。假设 $f[i]$ 求出了 $i$ 位符合要求二进制串的数目，为了求出 $f[n]$，我们考虑如下情况。

![image.png](https://pic.leetcode-cn.com/7a6be26e5a406c8572b07d079280e6277898d9cbd5125f743817aed0529975c4-image.png){:width=600}
{:align=center}

从上图中，我们可以知道如果我们知道 $f[n-1]$ 和 $f[n-2]$ 的值，为了求出需要的 $n$ 位数字，我们可以给 $f[n-1]$ 中所有数字后面添加 `0`，这样不会产生任何不合法数字。这些数字使得 $f[n]$ 中会包含 $f[n-1]$ 的结果。但我们不能直接给所有这些数字后加 `1`，因为可能会导致有连续 1 出现。所以如果我们要在后面加 1，我们必须确保上一个位置是 0。所以我们必须一次性给 $f[n-2]$ 中的字符串最后面加 `01`。所以我们得到了递推式 $f[n] = f[n-1] + f[n-2]$。

现在我们回到解法中，我们试着通过两个简单的例子来理解背后的想法。首先我们考虑给定数字不包含任何连续 1。比方说 $num = \text{1010100}$ （7位），现在我们需要思考如何找到比 $num$ 小的无连续 1 的数字。我们从 $num$ 的最高位开始考虑，如果我们固定住最高位为 $\text{0}$，然后找 6 位没有连续 1 的数字，也就是从 $\textbf{0}\text{000000}$ 到 $\textbf{0}\text{111111}$，我们可以用上面讨论的 $f[6]$ 来得到答案。

但即使这样做了以后，要求范围内的数字并没有被全部覆盖到。现在我们固定最高位为 $\text{1}$，那么考虑的数字范围会从 $\textbf{1}\text{000000}$ 到 $\textbf{1}\text{111111}$，我们可以看出来除了要求的 $\textbf{1}\text{000000}$ 到 $\textbf{1}\text{010100}$ 以外，还包括了这个范围以外的一些数字。所以我们不能仅把最高位固定为 $1$ 然后直接考虑低 6 位的值。

为了考虑剩余范围，我们首先固定最高位为 $\text{1}$ ，然后继续处理第二高位。由于我们在 $num$ 中得到第二高位是 $\text{0}$ ，所以我们不能将它变成 $\text{1}$ ，这会导致数字超过 $num$ 。但如果我们直接把这一位设为 $\text{0}$ 并取所有更低位不包含连续 1 的话，覆盖的范围是 $\textbf{10}\text{0000}$ 到 $\textbf{10}\text{1111}$ ，再一次我们发现这些数字包括了一些范围以外的数字。所以我们需要继续考虑低 5 位的情况。

我们将第二高位固定为 $\text{0}$ 再继续考虑第三位，这次我们又遇到了 $\text{1}$，像第一位一样，我们可以将这一位固定为 $\text{1}$，并获取低 4 位没有连续 1 的数字数目，这个值可以直接通过 $f[4]$ 获得。所以现在覆盖到的数字范围是 $\textbf{100}\text{0000}$ 到 $\textbf{100}\text{1111}$。

我们将第三高位固定为 $\text{1}$ 再继续考虑第四位，又一次是 $\text{0}$，所以我们需要像第二位一样将它固定，然后考虑第五位。第五位是 $\text{1}$，我们将它固定为 $\text{0}$ 并获取剩下 2 位的所有合法序列，即 $\textbf{10101}\text{00}$ 到 $\textbf{10101}\text{11}$，然后考虑第 6 位，发现再次是 $\text{0}$，所以我们固定第六位为 $\text{0}$ 再考虑第 7 位，发现仍然是 $\text{0}$，于是也将这一位固定为 $\text{0}$。

现在，我们可以发现，基于以上过程，数字范围在 $\textbf{0}\text{000000}$ 到 $\textbf{0}\text{111111}$，$\textbf{100}\text{0000}$ 到 $\textbf{100}\text{1111}$，$\textbf{10100}\text{00}$ 到 $\textbf{10100}\text{11}$，都已经分别由 $f[6]$，$f[4]$，$f[2]$ 求出来了。现在只有 $\text{1010100}$ 需要考虑是否要包括进来。因为它不包含任何连续的 1，所以我们给最后的答案加 1，也就是答案为 $f[6] + f[4] + f[2] + 1$。

<![image.png](https://pic.leetcode-cn.com/8a8f80d60b6e77a6ce2bd1db3d3d986ff7e764fcbf90888242a31b8d196005b3-image.png),![image.png](https://pic.leetcode-cn.com/12ecf7ec69b3b2bdd46210b949836c5637ee19e429118d7d268d711d5cb0da89-image.png),![image.png](https://pic.leetcode-cn.com/f06fb55235171650bbacc7ad4df335b011be2a190a3066ee2e0e1989246d6c81-image.png),![image.png](https://pic.leetcode-cn.com/215de6150629688dc5d0e06c10aa7dcb01810863b51763bdacb518b18f9dfb6c-image.png),![image.png](https://pic.leetcode-cn.com/e4cfad5cf36faa7fb5d5f2a572be76908acb51e9f08b5521775f697c3e97276d-image.png),![image.png](https://pic.leetcode-cn.com/3cd742111ce7d4c7bd204d4198611bfcb056341529f8d13cc0e6d1d8fcb2d6de-image.png),![image.png](https://pic.leetcode-cn.com/ff9616efdada7cd1aa235afdbdaa8fbc84ba51d1bd1d1f80148c2ac7b479b9f9-image.png),![image.png](https://pic.leetcode-cn.com/6342913469ee7e1a400f778e20c1d63ae094b2d276fdccedac955d77fb1cc737-image.png),![image.png](https://pic.leetcode-cn.com/3061c83ee2f73fbab7978882697044ca6e118670cb851a981e6f8372c15987db-image.png),![image.png](https://pic.leetcode-cn.com/d66955401a3eb45ff972cf527ebb2e30d32d01d7a8673dafd7e8906ccfd66cba-image.png),![image.png](https://pic.leetcode-cn.com/7ca31e1fea17e607af41f8a2634db5d83bf936f1ff0532c408db38142b3f0299-image.png),![image.png](https://pic.leetcode-cn.com/602be134695b72548e7c29e4fce2fff05ac39c6cefa575bd8cbb42e74938a313-image.png)>

现在我们考虑一下 $num$ 中包含连续 1 的情况，基本想法与上面一致，除了遇到连续 1 的时候有所不同。比方说 $num = \text{1011010}$ ，如上所述，我们从最高位开始考虑，我们发现是 $\text{1}$ ，然后我们将它固定为 $\text{0}$ 得到范围 $\textbf{0}\text{000000}$ 到 $\textbf{0}\text{111111}$ 的合法数字。这个值同样由 $f[6]$ 给出。

现在固定最高位是 $\text{1}$ 然后考虑次高位，它是 $\text{0}$ ，所以我们没有别的选择只能将它固定为 $\text{0}$ 然后考虑第三高位。这一位是 $\text{1}$ ，所以我们可以固定这一位是 $\text{0}$ 并考虑范围在 $\textbf{100}\text{0000}$ 到 $\textbf{100}\text{1111}$ 的合法数字，可以由 $f[4]$ 求出，然后我们固定第三高位为 $\text{1}$ 考虑第四位。它仍然是 $\text{1}$ （与前一个数字 $\text{1}$ 构成了 连续 $\text{1}$）。选择我们固定这一位为 $\text{0}$ ，考虑数字范围 $\textbf{1010}\text{000}$ 到 $\textbf{1010}\text{111}$ 的合法数字，数目为 $f[3]$ 。

我们可以发现，目前为止范围在 $\textbf{0}\text{0000000}$ 到 $\textbf{0}\text{111111}$ ， $\textbf{100}\text{0000}$ 到 $\textbf{100}\text{1111}$ , $\textbf{1010}\text{000}$ 到 $\textbf{1010}\text{111}$ 的数字范围都被考虑过了，但如果我们考虑任何大于 $\text{1010111}$ 的数字，都会导致第三位和第四位有连续 1 出现。所以所有有效数字的数目为 $f[6] + f[4] + f[3]$ 。

<![image.png](https://pic.leetcode-cn.com/4d551f5d1a5c37b1eeb6200bbde4705241b874e9a09f4211e9d6ba88861b0a7c-image.png),![image.png](https://pic.leetcode-cn.com/6c2d8465fea65c7030cd9ba345eed8600502c1293f8c45adcd1edff50d2b86b2-image.png),![image.png](https://pic.leetcode-cn.com/8d91e9e1528c3127c9e6db707d84b0b956f827254438a864ea27f397f33a5b10-image.png),![image.png](https://pic.leetcode-cn.com/ba7c002a0320948c90f2f69f87b86e5558611610b60d4dd0d37126ff88d05779-image.png),![image.png](https://pic.leetcode-cn.com/6fd5af4c533c928b3770e6ebe6120c238aea1aa0fc49e3d4af7c7cdba90ad177-image.png),![image.png](https://pic.leetcode-cn.com/98e76e92064de01381538d2b9f4b64be46f14b825e12b33d6f277ed006f42cac-image.png),![image.png](https://pic.leetcode-cn.com/6716ad7f9b676ec98e86cda81a8fa5859b3ba51858c219fc622b17782d842b90-image.png),![image.png](https://pic.leetcode-cn.com/359dd86ff0513658aad53e059d7b7b1d65428bc00930e2201eb2a56c8786f0b2-image.png)>

所以，综合上面讨论的内容，我们从 $num$ 的最高位开始考虑，对于第 $i$ 个位置遇到的 $1$ （从低位序号为 0 开始考虑），我们将答案加 $f[i]$ ，对每个遇到的 $0$ ，我们不给答案加任何值。我们还要记录上一个位置的数值为多少，一旦我们发现连续的 1 ，我们将第二个 1 变成 0 的影响考虑后即停止遍历。如果我们没有遇到连续的 1 ，我们一直遍历到最低位并将最终答案加 1 ，表示 $num$ 也是合法数字，因为上述过程并没有考虑 $num$ 进去。
 
```Java []
public class Solution {
    public int findIntegers(int num) {
        int[] f = new int[32];
        f[0] = 1;
        f[1] = 2;
        for (int i = 2; i < f.length; i++)
            f[i] = f[i - 1] + f[i - 2];
        int i = 30, sum = 0, prev_bit = 0;
        while (i >= 0) {
            if ((num & (1 << i)) != 0) {
                sum += f[i];
                if (prev_bit == 1) {
                    sum--;
                    break;
                }
                prev_bit = 1;
            } else
                prev_bit = 0;
            i--;
        }
        return sum + 1;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(log_2(max\_int)=32)$。求解 $f$ 数组一次并逐一检查 $num$ 的每一位。

* 空间复杂度：$O(log_2(max\_int)=32)$。$f$ 数组大小为 32。
