首先根据如上定义可知，如果一个数为丑数，则有如下性质：

```java
/*  将这个数首先除以二直到除不尽，然后除以三直到除不尽，最后除以五直到除不尽：
        如果最终只剩1，那么这个数便为丑数
*/
while (num % 2 == 0)    num /= 2;
while (num % 3 == 0)    num /= 3;
while (num % 5 == 0)    num /= 5;
```

#### 解法一

所以求第 `n` 个丑数，只需要暴力循环，直到循环至第 `n` 个丑数为止即可，代码如下：

```java
class Solution {
    public int nthUglyNumber(int n) {
        int count = 1;
        int ret = 1;
        
        while (count < n) {
            ret++;
            if (isUgly(ret)) count++;
        }
        return ret;
    }
    
    private boolean isUgly(int num) {
        while (num % 2 == 0)    num /= 2;
        while (num % 3 == 0)    num /= 3;
        while (num % 5 == 0)    num /= 5;
        return num == 1;
    }
}
```

**运行结果：** 超时。

#### 解法二

可以看到，上面的运算有许多重复步骤，为了不重复判断，我们可以只对丑数进行扩展，即将一个丑数乘 `2`, `3` 或者 `5`便可以得到一个新丑数。这样，就产生了几个问题：

- 丑数乘 `2`, `3` 或者 `5`可能会与之前的丑数重复

我又使用了暴力循环，每次只将最小的新丑数收入丑数集中：

```java
class Solution {
    public int nthUglyNumber(int n) {
        List<Integer> list = new ArrayList<>();
        int[] factor = {2, 3, 5};
        list.add(1);
        
        while (list.size() < n) {
            // 将最小的新丑数收入丑数集中
            int min = Integer.MAX_VALUE;
            for (int i:list) {
                for (int j : factor) {
                    int tmp = i*j;
                    if (tmp < min && tmp > list.get(list.size()-1))  min = tmp;
                }
            }
            list.add(min);
        }
        return list.get(n-1);
    }
}
```

**但是，看似无懈可击的代码出现了解答错误**，我有点懵，经过二分查找错误的源头，我发现了苗头：第`1458`个丑数出现了问题，导致后面全部出错。

经检验，我发现丑数 `1074954240` 与 `5` 相乘会产生一个神奇的结果 `1079803904` ，没错，爆 `int` 了，而且恰好卡在了这个位，于是为了防止这种情况，我在上面代码中又加了一层保险，将`if (tmp < min && tmp > list.get(list.size()-1))`改为了 `if (tmp < min && tmp > list.get(list.size()-1) && tmp / i == j)`。

**运行结果：** 397ms

#### 解法三

上面的解法依旧暴力，但其实写这个解法的时候我其实有了一个很模糊的思路，即每次需要加一个相对最小的丑数，但是如何优化，使寻找最小丑数的方法最为简单，我就死活都想不出了。

**看了别人的解答之后，我才明白过来。**

| 第n个丑数 |  i2  |  i3  |  i5  |      新丑数      |
| :-------: | :--: | :--: | :--: | :--------------: |
|     1     |  0   |  0   |  0   | $1\times i2 = 2$ |
|     2     |  1   |  0   |  0   | $1\times i3 = 3$ |
|     3     |  1   |  1   |  0   | $2\times i2 = 4$ |
|     4     |  2   |  1   |  0   | $1\times i5 = 5$ |
|     5     |  2   |  1   |  1   | $3\times i2 = 6$ |
|     6     |  3   |  1   |  1   |        …         |

可以看到，每次只需要比较 `2 3 5` 的索引处的值分别对应与 `2 3 5` 的乘积，选取最小值即可，并将选中的那个索引加一。【索引：对应在所有丑数中的值】

于是，代码如下：

```java
class Solution {
    public int nthUglyNumber(int n) {
        /*
            动态规划：min{ list(i2) * 2,
                          list(i3) * 3, 
                          list(i5) * 5}
        */
        List<Integer> list = new ArrayList<Integer>();
        list.add(1);
        int i2 = 0, i3 = 0, i5 = 0;
        
        while (list.size() < n) {
            int next2 = list.get(i2)*2;
            int next3 = list.get(i3)*3;
            int next5 = list.get(i5)*5;
            
            int min = Math.min(next2, Math.min(next3, next5));
            if (min == next2) i2++;
            if (min == next3) i3++;
            if (min == next5) i5++;
            
            list.add(min);
        }
        return list.get(list.size()-1);
    }
}
```

**运行结果：** 14ms

#### 解法四

题解中很多人写的那种暴力解法的优化版，即将保存所有丑数的值的列表设置为`static`,那么就不用每次调用都重新在计算一遍了。

```java
class Solution {
    static ArrayList<Integer> list = new ArrayList<>();
    public int nthUglyNumber(int n) {
        if (list.size() == 0) {
            for (long i = 1; i <= Integer.MAX_VALUE; i *= 2)
                for (long j = i; j <= Integer.MAX_VALUE; j *= 3)
                    for (long k = j; k <= Integer.MAX_VALUE; k *= 5)
                        list.add((int)k);
        }
        Collections.sort(list);
        return list.get(n-1);
    }
}
```

**运行结果：** 9ms

说明：后两种解法参考了[花花酱讲leetcode](https://www.bilibili.com/video/av31571137/)