#### 方法一：拒绝采样
**【历史重难点题目】**
* [历史重难点题目总结](https://mp.weixin.qq.com/mp/homepage?__biz=MzI4Njc4MzMwMw==&hid=1&sn=58bf8e995138b26984c05fd51f198196)

**【核心思想】**
* 合理调用rand7()来生成rand10()
* 先举一个简单的例子，如何用rand7()来生成rand5()呢？用rand7()产生一个随机数，如果随机数是`1,2,3,4,5`就取，是`6,7`就重新生成。因为rand7()生成`1,2,3,4,5`的概率时一样的，都是$\frac{1}{7}$，所以rand5()也是均分分布的。


**【思路】**
* 把rand7()想象成一个7面的骰子🎲，现在我们有两个骰子
* 第一次如果掷出`1,2,3,4,5,6`就掷下一个骰子；如果掷出`7`，就继续掷这个骰子，直到不是7为止
* 第二次如果掷出`1,2,3,4,5`就结束；如果掷出`6,7`，就继续掷这个骰子，直到不是`6,7`为止
* 如果第一次掷出`1,2,3`，则first记为0；如果第一次掷出`4,5,6`，则记first为5；记第二次掷出的为second
* 最后返回`first+second`

验证一下是否是均匀分布:

first为0的概率=第一次掷出`1,2,3`的概率=$\frac{3}{7}$
first为5的概率=第一次掷出`4,5,6`的概率=$\frac{3}{7}$
second为`1,2,3,4,5`的概率都相等=$\frac{1}{7}$
那么`first+second`为`1,2,3,4,5,6,7,8,9,10`的概率都相等$=\frac{3}{7}*\frac{1}{7}=\frac{3}{49}$

**【代码】**
```java
class Solution extends SolBase {
    public int rand10() {
        int first=rand7();
        int second=rand7();
        while(first==7)
            first=rand7();
        while(second>5)
            second=rand7();
        return (first/4==0?0:5)+second;    
    }
}
```

**【备注】**
* 拒绝采样还有好多方法，比如下面这一种，我们调用两次 Rand7()，那么可以生成 [1, 49] 之间的随机整数，我们只用到其中的 40 个，用来实现 Rand10()，而拒绝剩下的 9 个数
* 如下图，[1,10]都是等概率的
* 其他的方法这里就不一一列举了
![](https://pic.leetcode-cn.com/5a09ef9456dd9e97ac55e2e1779063a0266888e15c48ee393f22a664833a25ba.png)
```java
class Solution extends SolBase {
    public int rand10() {
        int row, col, idx;
        do {
            row = rand7();
            col = rand7();
            idx = col + (row - 1) * 7;
        } while (idx > 40);
        return 1 + (idx - 1) % 10;
    }
}

```



#### 方法二：拒绝采样的优化
**【核心思想】**
* 前面的方法是舍弃了一部分采样得到的值，但是我们也可以通过合理地使用被拒绝的采样，从而对之前的方法进行优化。


**【思路】**

* 用两个rand7()生成 [1, 49] 的随机数，若生成的随机数 x 在 [41, 49] 中，我们则拒绝 x。然而在 x 被拒绝的情况下，我们得到了一个 [1, 9] 的随机数
* 再调用一次 rand7()，那么就可以生成 [1, 63] 的随机数（9*7=63）
* 保留 [1, 60] 并拒绝 [61, 63]，在 x 被拒绝的情况下，得到了 [1, 3] 的随机数
* 继续调用 rand7()，生成 [1, 21] 的随机数（3*7=21），保留 [1, 20] 并拒绝 [1]。此时 [1] 已经没有任何用处，若出现了拒绝 1 的情况，我们就重新开始生成 [1, 49] 的随机数。



**【代码】**
```java
class Solution extends SolBase {
    public int rand10() {
        while (true) {
            int index = rand7() + (rand7() - 1) * 7;
            if (index <= 40) {
                return 1 + (index - 1) % 10;
            }

            index = rand7() + (index - 40 - 1) * 7;
            if (index <= 60) {
                return 1 + (index - 1) % 10;
            }

            index = rand7() + (index - 60 - 1) * 7;
            if (index <= 20) {
                return 1 + (index - 1) % 10;
            }
        }
    }
}
```

**【备注】**
* 这道题其实还有很多方案，大家还有别的解法吗，都可以告诉我们
* 有一个问题很有意思，就是这道题提交是如何通过的？如何检测代码对不对呢？有朋友有想法吗？


**【关注微信公众号，带你拿大厂offer】**
![logo_gif.gif](https://pic.leetcode-cn.com/0c87a295279bc59a2b99e3a24ec9cefead10ec5d2be4430fb8346125ff0bd117-logo_gif.gif)
