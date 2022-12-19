博客原文：[从一道简单的 subStr 题目引出来的 KMP 算法](https://zoharyip.club/2019/10/07/The-Knuth-Morris-Pratt-Algorithm/)

## KMP 算法

### 1 是什么

KMP 算法是一种字符串匹配算法，由 D.E.Knuth，J.H.Morris 和 V.R.Pratt 提出的，因此人们称它为克努特—莫里斯—普拉特算法（简称KMP算法）。

### 2 为什么

KMP 为什么会是改进后的查找匹配算法呢？

我们先来看看暴力法的问题所在：

![viloence-solve.gif](https://pic.leetcode-cn.com/3b0c3a61534754d1176647a1bf7ce10df00c21bf19284f675b7b4ace56f361a7-file_1570527731105 "https://zoharyip.club")

在暴力匹配中，我们在 txt 中从 `i` 开始与 `pattern` 串匹配至 `i + pattern.length()`，一旦匹配失败，则从 `i + 1` 子串重新匹配。此时我们**抛弃了前面的匹配信息**，因为我们知道前面匹配中遇到了 `四`，而 pattern 中并无 `四` ，应该从 `四` 后面的 `一` 开始重新匹配。

而 KMP 算法目的就是：**在出错时，利用原有的匹配信息，尽量减少重新匹配的次数。**

所以应当是这样的：

![kmp2.gif](https://pic.leetcode-cn.com/c43d65b60e24b1a4abd6b3593a7c2dd413107fa045e900d4f204b3ce049a133a-file_1570527731109 "https://zoharyip.club")

或者是其他情况：

![kmp1.gif](https://pic.leetcode-cn.com/a4950ffd0c1371cf712e20634c656185de485f611352fa9713503aae291da731-file_1570527731112 "https://zoharyip.club")


在两种方法的对比中，可以看到 KMP 算法的主串下标永不后退，而暴力算法一旦出错，则回退至匹配起始的下一个下标重头开始。

### 3 怎么做

那么我们该如何利用已有的出错信息呢？

**原匹配信息有：**
  * txt 串的已遍历字符，长度太长，缓存一份自然是不现实的，舍去；
  * pattern 串的已匹配字符，长度小，与 txt 串最近几个字符是已匹配的。

因此，已匹配信息指 pattern 串的已匹配字符；且完整的 pattern 串是已知的，因此，我们一直掌握着一个信息：**Pattern 串的匹配程度**，也就是 **Pattern 串的已匹配状态**。

#### 3.1 状态

例如：

$$ \mathsf{txt:} \qquad \mathbf{...\ \overline{A\ A\ B\ A}\ A\ C\ ...} $$
$$ \mathsf{pattern:} \qquad \mathbf{\overline{A\ A\ B\ A}\ B\ C} $$

对比 | 匹配状态 | 匹配字符 | 目标状态 | 匹配结果
:-: |:-: | :-: | :-: | :-
计划 | `AABA` | `B` | `AABAB` | 成功，继续匹配
现实 | `AABA` | `A` | `AABAA` | 失败，重新匹配

`A`、`AA`、`AAB`、`AABA` 都是 pattern 的前缀，再回顾匹配失败的信息： `AABAA`，发现 `AA` 是 pattern 的前缀之一，那我们可以调整至 `AA` 继续匹配，而不用回退 txt 的指针；我们可以将这些已匹配的信息成为 pattern 的**匹配状态**：

$$ \mathbf{nowStatus} \ +\ \mathbf{char} \ =\ \mathbf{targetStatus}  $$

* `nowStatus` 为当前状态，这是已知的
* `char` 为待匹配的字符 ，这也是已知的
* `targetStatus` 表示目标状态，可能是升状态也可能是降状态，这是我们可以推导出来的

即：pattern 处于某个匹配状态时，遇到特定的字符会变成另一种状态（重置的话就是回到初始状态）；

因此，我们可以把 所有的状态（X轴） + 所有的字符（Y轴） 存储成一张表结构，而目标状态就是（X, Y）的值，我们每读取一个 txt 的字符，就查阅表即可知道会进入什么状态，如果进入最终状态，即表示完成匹配。这样一张表我们称为**确定有限状态机**。

#### 3.2 确定有限状态机

例如，对于待匹配字符串为 `ababc` 的 pattern 串，我们可以手动推导出这张表：

字符\状态 | ` `(0) | `a`(1) | `ab`(2) | `aba`(3) | `abab`(4)
 :-: | :-: | :-: | :-: | :-: | :-:
a | 1 | 1 | 3 | 1 | 3
b | 0 | 2 | 0 | 4 | 0
c | 0 | 0 | 0 | 0 | **5**
... | 0 | 0 | 0 | 0 | 0

根据这张表，利用 `nowStatus(x轴) + char(y轴) => targetStatus(值)` 这条规则我们可以推导出 `abab` 状态下如果匹配到 `a` 可以返回到 `aba` 状态，而不是重新匹配：

![ababa.png](https://pic.leetcode-cn.com/a87863bf33557faab84dee624f2d473d0ecfbec886c21b12d3aa798d1d7a3a42-ababa.png "zoharyip.club")

#### 3.3 使用有限状态机

假如我们已经构建好刚才的表 FSM（指 Finite State Machine，有限状态机简称），我们可以直接这样用：

```
int state = 0; // 匹配状态
for (int i = 0; i < strLen; i++) {
    state = FSM[state][haystack.charAt(i)];
    // 判断是否匹配到最终状态，是则返回结果
    if (state == subLen) {
        return i - subLen + 1;
    }
}
```

#### 3.4 构建有限状态机

在 3.2（确定有限状态机）中，我们依据 **当前状态 + 匹配字符 = 目标状态** 推导出整张表，既然能手动推导，弄清楚原理让它自动生成了，所以我们来一步步搞清楚原理

>`abab` 遇到 `a` 无法升级，但是却可以把 `abab` 看成是 `ab`，遇到 `a` 可以变成 `aba`，因此不需要重置，可以降级为 `aba` 状态。

能这样做的原因是：`abab` 这个已匹配串中的前缀 `ab` 与后缀 `ab` 内容相同而不相等（不是同一个子字符串），就像 `aba` 可以视为 `a`，因为包含的内容相同而不相等的前后缀 `a`！我称这种情况为**孪生词缀，即前后缀内容相同而不相等**，而 `a` 这个前缀/后缀就叫做**当前状态的孪生词缀状态**，因此有：

**当前状态 + 匹配失败字符 = 孪生词缀状态 + 匹配字符 = 目标状态（降级或重置）**

所以，为构建状态机，我们需要为每一个状态找到相应的孪生词缀状态（设 X 代表孪生词缀状态），然后借助 X 判断匹配失败后是重置还是降级。

那该怎么找到每个状态的 X 状态呢？别急，我们通过构建状态机的代码来说明怎么找 X 状态；

1. 声明状态机和 X；因为还没读取 pattern 串，所以默认所有目标状态都为 0；

    ```java
    int X = 0；//最初所有状态的孪生词缀状态是未知的，所以默认为 0；
    // 除去最终状态，状态机有 pattern.length() 种输入状态，默认遇到 256 个字符。表格所有成员初始值为 0
    int[][] FSM = new int[pattern.length()][256];
    ```

2. 更新状态机的每一列和更新每一个状态的孪生词缀状态。
  我们先默认所有字符都匹配失败，再用唯一正确的字符进行修改。

    ```java
    for (int i = 0; i < pattern.length(); i++){
        int match = (int)pattern.charAt(i); // 当前能成功匹配的字符
        for (int c = 0; c < 256; c++) {
            // 当前状态 + 匹配失败字符 = 孪生词缀状态 + 匹配字符 = 目标状态
            FSM[i][c] = FSM[X][c]; 
        }
        // 当前状态 + 匹配成功字符 = 升级状态
        FSM[i][match] = i + 1;

        if (i > 0) {
            /* 
             * 零或一状态是不可能有孪生词缀，因此不更新 0 状态的孪生词缀状态，
             * 但 1 状态匹配出错，匹配到第一个字符会回到 1 状态，因此需要更新。
             * 
             * 当前状态有孪生词缀状态的话，X 状态就是当前状态的前缀和后缀，
             * 当前状态遇到 match 会升级到下一个状态，X + match 一定是下一状态的后缀，
             * 
             * 如果 X 遇到 match 能升级，就表示 X + match 一定是下一个状态的前缀，那么 X + match 是下一状态的孪生词缀状态；
             * abab = aba + b；X(ab) = X(a) + b;
             * 如果无法升级，就表示 X + match 不是下一个状态的前缀，那么 X + match 就要降级或者重置状态了；
             * ababc = abab + c; X(0) = X(ab) + c;
             * 
             * 所以： 下一状态的孪生词缀状态 = 当前状态的孪生词缀状态 + 当前状态的更新字符
            */
            X = FSM[X][match];
        }
    }
    ```
    更新要点：X 状态肯定是比当前状态低的状态，X 遇到 match 也能升级的话，升级后的 X 依旧是当前状态的前缀，更是下一状态的前缀；
    感谢 @Ethan，帮我改正了一个小错误，谢谢你。

### 4 KMP 实现

由上文的推理，我们能够使用和构建状态机，因此可以直接实现 KMP 算法：

```java
public int strStr(String haystack, String needle) {
    int strLen = haystack.length(), subLen = needle.length();
    if (subLen == 0) return 0;
    if (strLen == 0) return -1;
    // 构建状态机
    int[][] FSM = new int[subLen][256];
    int X = 0, match = 0;
    for (int i = 0; i < subLen; i++) {
        match = (int) needle.charAt(i);
        for (int j = 0; j < 256; j++) {
            // 当前状态 + 匹配失败字符 = 孪生词缀状态 + 匹配字符
            FSM[i][j] = FSM[X][j]; 
        }
        FSM[i][match] = i + 1;
        if (i > 1) {
            // 下一孪生前缀状态 = X + match
            X = FSM[X][match];
        }
    }
    // 匹配子串
    int state = 0;
    for (int i = 0; i < strLen; i++) {
        state = FSM[state][haystack.charAt(i)];
        if (state == subLen) {
            return i - subLen + 1;
        }
    }
    return -1;
}
```

### 5 KMP 算法评价

KMP 属于典型的牺牲空间换取时间的算法，要评价它的好坏，得判断这些牺牲的空间值不值。

1. 目的：减少重新匹配的次数，让主串遍历永不回头

2. 方法：通过利用已有的匹配信息，借助已匹配串的前缀与后缀关系，在重新匹配时跳过已有的前缀
3. 适用：从它的方法原理我们可以看出，pattern 串的中间必须出现与其前缀相同的内容，这个算法才能够派上用场，出现重复的越多，就越有价值，因此像匹配 `橡胶橡胶`、`chop-chop`、`恍恍惚惚`、`win-win` 这种叠词较为适合，而最为适合的情景是**匹配二进制串**（都是 0101 的重复）；
4. 缺陷：现实中，中间内容与前缀相同的单词、词汇并不多见，而长句更是除了排比句之外就很少见了，因此，在花费时间空间生成了有限状态机之后，很有可能会出现一直都是重置状态而很少降价状态的情况出现。对于长句而言，状态机所占用的空间是巨大的，而并不高效，相反纯暴力解法对于短 pattern 串。而言，总体运行时间却并不比它慢😂。

![image.png](https://pic.leetcode-cn.com/5eb038f5b86128318c862b926d8a904db96e21166af7d20acaea80bb41b6ec17-image.png)

第2次提交我使用的是暴力解法，显而易见，第3、4次提交用的是 KMP 算法，实践效率并不算高，这与 leetCode 的测试用例有很大的关系，显然以叠词作为 pattern 串的情况并不多见，因此我们可以在匹配开始之前判断 pattern 是否是符合 KMP 优势的待匹配串，是的话再调用本方法即可。

很多地方都说 KMP 很快，但其实整体来说它并不快，它是难。但我们看别人演示看起来都很快，是因为演示时都是拿 `ABAC` 这些字符类型少而重复多的字符串，甚至是 `0101011100110101`，匹配这些串的话，本来就是 KMP 的优势所在。

因此，对于字符串匹配而言，KMP 算法并不能算是最优的算法，还有更多优秀的算法如 BM 算法、Sunday 算法等，需要我们去学习和比较；Keep moving！

> Sunday 动图

![GIF.gif](https://pic.leetcode-cn.com/5ba04cb81e82923eacfc0deaf6ca609d140ce5cfc833ca86e8cf1551d433317f-GIF.gif)
