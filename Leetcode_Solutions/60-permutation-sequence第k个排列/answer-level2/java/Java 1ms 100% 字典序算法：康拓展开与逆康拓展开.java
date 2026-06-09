## 1. 字典序
在数学中，字典序是基于字母顺序排列的单词按字母顺序排列的方法。 这种泛化主要在于定义有序完全有序集合（通常称为字母表）的元素的序列（通常称为计算机科学中的单词）的总顺序。

对于数字1、2、3...n组成的所有全排列，其总共有`n! * (n-1)! * ...*(2!)* 1!`种，不同排列的先后关系是从左到右逐个比较对应数字的先后关系决定的。例如，对于由1,2,3,4,5等5个数字组成的排列：12345（字典序为1），12354（字典序为2）。因此，序列12345排在序列12354之前。相似的序列54321的字典序 = `5!*4!*3!*2!*1! = 120`。

## 2. 康拓展开
康拓展开计算的是某个排列方式组成的序列在其全排列序列集合中的字典序，可以发现对于序列和它的字典序是一一对应的。我们以一个简单的例子来介绍下这个求解过程：

### 2.1 一个demo
给定一个正整数4和一个由1~4组成的排列 3214，求这个排列对应的字典序rank：

1. 排列第1个字符为3，没有已使用的字符，那么小于3且未使用的字符数目有2个，分别是1和2。则

   `rank = 2 * 3! = 12`。这里的2表示小于且未使用的字符数目，这里的3表示剩下的字符数目，如果第一位取1，那么剩下的字符是2,3,4。
2. 排列第2个字符为2，已使用的字符为3，那么小于2且未使用的字符数目有1个为1。则`rank += 1 * 2! = 14`
3. 排列的第3个字符为1，已使用的字符为2和3，那么小于1且未使用的字符数目为0。则
`rank += 0 * 1! = 14`
4. 排列的第4个字符为4，已使用的字符为1,2和3，那么小于4且未使用的字符数目为0。则
`rank += 0 * 0! = 14`

由于我的字典序是从1开始的，且上述过程我们计算的是字典序小于排列3214的排列的个数，那么排列3214最终的字典序还要加一，即`rank = rank + 1 = 15`

### 2.2 康拓展开公式
下面我们给出一个一般化的康拓展开公式，给定一个正整数n和一个由1~n组成的排列
$$
x_1x_2...x_n，其中x_i都取自[1, n]中且不重复
$$

那么
$$
rank = a_1(n-1)! + a_2(n-2)! + ... + a_{n-2}2! + a_{n-1}1! + a_{n}0! + 1，其中a_i表示小于x_i且未被使用的字符数目
$$

### 2.3 Show the code
```java
    /**
     * 康拓展开：给定一个正整数n与一个由1~n的数组成的排列x1...xn，计算这个排列的字段序rank
     * 例： 3214的rank = 15
     */
    public int calcContorIndex(int[] input) {
        int len = input.length;
        boolean[] visit = new boolean[len];
        int rank = 0;
        for (int val : input) {
            rank += calcLessUnVisited(val, visit) * calcFactorial(len - 1);
            visit[val - 1] = true;
            len--;
        }
        return rank + 1;
    }

    /**
     * 计算小于n且没被访问的数有多少个
     */
    private int calcLessUnVisited(int n, boolean[] visit) {
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            if (!visit[i]) {
                count++;
            }
        }
        return count;
    }

    /**
     * 计算一个自然数的阶乘
     */
    private int calcFactorial(int n) {
        if (n <= 1) return 1;
        int res = 1;
        for (int i = 1; i <= n; i++) {
            res *= i;
        }
        return res;
    }
```

## 3.逆康拓展开
通过上面我们知道，序列和它的字典序是一一对应的。那么给定一个整数数n和某一个排列的字典序，我们也可以求出该序列的具体值，这便是逆康拓展开。

### 3.1 又一个demo
给定一个正整数4和一个由1~4组成的排列seq的字典序rank = 15，求这个排列的具体值：

1. 字典序在这个seq之前的排列数目： rank - 1 = 14
2. seq的第一个字符，14 / 3! = 2 ... 2 (商2余2)，没有已使用的字符，第一个字符取在未使用的字符中排增序第3的即3
3. seq的第二个字符，2 / 2! = 1 ... 0，已使用的字符为3，第二个字符取在未使用的字符中增序排第2第即2
4. seq的第三个字符，0 / 1! = 0 ... 0，已使用的字符为2和3，第三个字符取在未使用的字符中增序排第1第即1
5. seq的第三个字符，0 / 0! = 0 ... 0，已使用的字符为1，2和3，第四个字符取在未使用的字符中增序排第1第即4
那么要求的这个序列为：3214。

### 3.2 逆康拓展开代码
计算阶乘的代码上面有了，就不重复贴了。[LeetCode.60 第k个排列](https://leetcode-cn.com/problems/permutation-sequence/)便是这个逆康拓展开的一个应用。
```java
    /**
     * 逆康拓展开：给定一个正整数n和由这n个正整数组成的某个排列的字典序rank，求这个排列
     */
    public String calcRevContorSeq(int n, int rank) {
        StringBuilder res = new StringBuilder();
        boolean[] visit = new boolean[n];

        int num = rank - 1;
        for (int i = n - 1; i >= 0; i--) {
            int factorial = calcFactorial(i);
            int val = calcLessKUnVisited(num / factorial + 1, visit);
            res.append(val);
            visit[val - 1] = true;
            num = num % factorial;
        }
        return res.toString();
    }

    /**
     * 计算升序第k个没使用的元素
     */
    private int calcLessKUnVisited(int k, boolean[] visit) {
        int count = 0;
        for (int i = 0; i < visit.length; i++) {
            if (!visit[i]) {
                count++;
                if (count == k) {
                    return i + 1;
                }
            }
        }

        throw new UnsupportedOperationException("Unreachable logic!");
    }
```

## 4.参考文献
1. https://baike.baidu.com/item/%E5%AD%97%E5%85%B8%E5%BA%8F
2. https://blog.csdn.net/ajaxlt/article/details/86544074

本文转载自个人掘金博客https://juejin.im/post/5e8bf0eb51882573716a9288
欢迎大佬们，点赞评论