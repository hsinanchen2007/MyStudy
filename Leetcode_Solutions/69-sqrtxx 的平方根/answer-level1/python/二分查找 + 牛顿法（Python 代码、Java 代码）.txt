二分查找法应用于搜索平方根的思想很简单，其实就是“猜”，但是是有策略的“猜”，用“排除法”在有限的区间里，一次排除一半的区间元素，最后只剩下一个数，这个数就是题目要求的向下取整的平方根整数。

牛顿法最初提出的时候，是用于求解方程的根，它的基本思想是“以直代曲”，在迭代中搜索得到方程的近似解。


### 方法一：二分法

**思路分析**：使用二分法搜索平方根的思想很简单，就类似于小时候我们看的电视节目中的“猜价格”游戏，高了就往低了猜，低了就往高了猜，范围越来越小。因此，使用二分法猜算术平方根就很自然。

一个数的平方根肯定不会超过它自己，不过直觉还告诉我们，一个数的平方根最多不会超过它的一半，例如 $8$ 的平方根，$8$ 的一半是 $4$，$4^2=16>8$，如果这个数越大越是如此，因此我们要计算一下，这个边界是多少。为此，解如下不等式：

$$\left(\cfrac{a}{2}\right)^2 \ge a$$

意即：如果一个数的一半的平方大于它自己，那么这个数的取值范围。解以上不等式得 $a \ge 4$ 或者 $a \le 0$。

于是边界值就是 $4$，那么对 $0$、$1$、$2$、$3$ 分别计算结果，很容易知道，这 $4$ 个数的平方根依次是 $0$、$1$、$1$、$1$。

**注意**：这 $4$ 个特值如果没有考虑到，有可能导致你设置的搜索边界不正确。在使用二分法寻找平方根的时候，要特别注意边界值的选择，以下给出两个参考代码。

**参考代码 1**：所有的数都放在一起考虑，为了照顾到 $0$ 把左边界设置为 $0$，为了照顾到 $1$ 把右边界设置为 `x // 2 + 1`。

```Python []
class Solution:
    def mySqrt(self, x: int) -> int:
        # 为了照顾到 0 把左边界设置为 0
        left = 0
        # 为了照顾到 1 把右边界设置为 x // 2 + 1
        right = x // 2 + 1
        while left < right:
            # 注意：这里一定取右中位数，如果取左中位数，代码可能会进入死循环
            # mid = left + (right - left + 1) // 2
            mid = (left + right + 1) >> 1
            square = mid * mid

            if square > x:
                right = mid - 1
            else:
                left = mid
        # 因为一定存在，因此无需后处理
        return left
```
```Java []
public class Solution {

    public int mySqrt(int x) {
        // 注意：针对特殊测试用例，例如 2147395599
        // 要把搜索的范围设置成长整型
        // 为了照顾到 0 把左边界设置为 0
        long left = 0;
        // # 为了照顾到 1 把右边界设置为 x // 2 + 1
        long right = x / 2 + 1;
        while (left < right) {
            // 注意：这里一定取右中位数，如果取左中位数，代码会进入死循环
            // long mid = left + (right - left + 1) / 2;
            long mid = (left + right + 1) >>> 1;
            long square = mid * mid;
            if (square > x) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        // 因为一定存在，因此无需后处理
        return (int) left;
    }

}
```

Java 代码要注意到：如果中点 `mid` 声明为 `int` 类型，针对大整型测试用例通不过，因此变量需要声明为 `long` 类型，下同。

**参考代码 2**：事实上，只要单独照顾一下 $0$ 这个特例就可以了。

```Python []
class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0:
            return 0

        left = 1
        right = x // 2

        while left < right:
            # 注意：这里一定取右中位数，如果取左中位数，代码可能会进入死循环
            # mid = left + (right - left + 1) // 2
            mid = (left + right + 1) >> 1
            square = mid * mid

            if square > x:
                right = mid - 1
            else:
                left = mid
        # 因为一定存在，因此无需后处理
        return left
```
```Java []
public class Solution {

    public int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        // 注意：针对特殊测试用例，例如 2147395599
        // 要把搜索的范围设置成长整型
        long left = 1;
        long right = x / 2;
        while (left < right) {
            // 注意：这里一定取右中位数，如果取左中位数，代码会进入死循环
            // long mid = left + (right - left + 1) / 2;
            long mid = (left + right + 1) >>> 1;
            long square = mid * mid;
            if (square > x) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        // 因为一定存在，因此无需后处理
        return (int) left;
    }

}
```

**注意：** 这里二分法的使用是有技巧的（如果你没有意识到，这里很可能是个“坑”），下面我就上面注释中提到的：

> 注意：这里一定取右中位数，如果取左中位数，代码可能会进入死循环。

做一些解释。当 `x = 9` 的时候，我们不妨给“错误的”代码加上一些调试语句，这样你就会更清晰地发现死循环在什么时候出现，例如：

Python 代码：

```python
class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0:
            return 0

        left = 1
        right = x // 2
        while left < right:
            # 调试代码开始：为了仔细观察区间左右端点，我们每进入一次循环，让线程休眠 1 秒
            import time
            time.sleep(1)
            print('调试代码，观察区间左右端点、中位数，和进入的分支： left = {} , right = {} , '.format(left, right), end='')
            # 调试代码结束

            # 错误代码，在分支左区间不发生收缩的情况下，中位数应该取右中位数
            # mid = left + (right - left) // 2
            mid = (left + right) >> 1
            # 调试代码
            print('mid = {} ,'.format(mid), end=' ')
            square = mid * mid

            if square > x:
                # 调试代码
                print('进入 right = mid - 1 这个分支。')
                right = mid - 1
            else:
                # 调试代码
                print('进入 left = mid 这个分支。')
                left = mid
        return left


if __name__ == '__main__':
    # 当 x = 8 的时候，代码能得出正确答案
    x = 9
    solution = Solution()
    res = solution.mySqrt(x)
    print(res)
```

控制台输出：

```angelscript
调试代码，观察区间左右端点、中位数，和进入的分支： left = 2 , right = 4 , mid = 3 , 进入 left = mid 这个分支。
调试代码，观察区间左右端点、中位数，和进入的分支： left = 3 , right = 4 , mid = 3 , 进入 left = mid 这个分支。
调试代码，观察区间左右端点、中位数，和进入的分支： left = 3 , right = 4 , mid = 3 , 进入 left = mid 这个分支。
调试代码，观察区间左右端点、中位数，和进入的分支： left = 3 , right = 4 , mid = 3 , 进入 left = mid 这个分支。
调试代码，观察区间左右端点、中位数，和进入的分支： left = 3 , right = 4 , mid = 3 , 进入 left = mid 这个分支。
Traceback (most recent call last):
  File "/Users/liwei/（按照惯例这里不让你们看，虽然真的没有什么秘密，就是皮一下子很开心啊有木有）/LeetCode-Solution-Python/17-二分查找/0069-x 的平方根-2（平方根）.py", line 37, in <module>
    res = solution.mySqrt(x)
  File "/Users/liwei/（按照惯例这里不让你们看，虽然真的没有什么秘密，就是皮一下子很开心啊有木有）/LeetCode-Solution-Python/17-二分查找/0069-x 的平方根-2（平方根）.py", line 11, in mySqrt
    time.sleep(1)
KeyboardInterrupt
```

分析：如果取中点为左中位数，你看到死循环发生在 `left = 3`， `right = 4` 的时候，此时**区间只有 2 个元素**。这是为什么呢？

此时索引区间 `[3, 4]` 的中位数为左中位数，即 `mid = 3` ，此时 `square = 9 < 9` 不成立，进入 `left = mid` 这个分支，你发现问题了吗，区间不发生收缩，即下一轮循环的索引区间还是  `[3, 4]`，此时中位数还取左中位数，即 `mid = 3` ，`square = 9 < 9` 不成立，又进入 `left = mid` 这个分支，死循环就是这样产生的。

接着，请你把 `mid = left + (right - left) // 2` 改成 `mid = left + (right - left + 1) // 2` ，即选择右中位数，再观察一下控制台输出，就知道此时为什么要选右中位数了。

这个二分法模板我用了很久，感觉非常好用。于是我专门把这个二分法模板好用的地方、使用它的技巧和注意事项整理在了「力扣 」第 35 题：搜索插入位置的题解[《特别好用的二分查找法模板（Python 代码、Java 代码）》](https://leetcode-cn.com/problems/search-insert-position/solution/te-bie-hao-yong-de-er-fen-cha-fa-fa-mo-ban-python-/)，希望能对大家有所帮助。


**复杂度分析：**

+ 时间复杂度：$O(\log N)$，二分法的时间复杂度是对数级别的。
+ 空间复杂度：$O(1)$，使用了常数个数的辅助空间用于存储和比较。


**总结：** 使用二分查找法搜索，注意特值对搜索边界的影响。

以下这部分内容是根据与用户 [@lukas](/u/18482187634) 在本题解下的讨论而添加的。

在这里补充一下，如果你实在不太想分析 `a` 的平方根可能的上界，之前说了，它肯定不会超过 `a` 自己，即使你把上界写成一个很大的数，例如 $999999$，这个数必须得是力扣的测试用例都达不到的数，在二分查找的过程中，不符合要求的数每次会被很快砍掉一半。

**参考代码 3**：干脆我不讨论 `a` 的边界，让二分法去排除不符合的区间吧，对数级别的时间复杂度对性能不会有很大影响。

```Python []
class Solution:

    def mySqrt(self, x):
        left = 0
        right = 999999
        while left < right:
            # 这种取中位数的方法又快又好，是我刚学会的，原因在下面这篇文章的评论区
            # https://www.liwei.party/2019/06/17/leetcode-solution-new/search-insert-position/
            mid = (left + right + 1) >> 1
            square = mid * mid
            if square > x:
                right = mid - 1
            else:
                left = mid

        return left
```
```Java []
public class Solution {

    public int mySqrt(int x) {
        long left = 0;
        long right = Integer.MAX_VALUE;
        while (left < right) {
            // 这种取中位数的方法又快又好，是我刚学会的，原因在下面这篇文章的评论区
            // https://www.liwei.party/2019/06/17/leetcode-solution-new/search-insert-position/
            // 注意：这里得用无符号右移
            long mid = (left + right + 1) >>> 1;
            long square = mid * mid;
            if (square > x) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        return (int) left;
    }
}
```

### 方法二：牛顿法

使用牛顿法可以得到一个正实数的算术平方根，因为题目中说“结果只保留整数部分”，因此，我们把使用牛顿法得到的浮点数转换为整数即可。

这里给出牛顿法的思想：

> 在迭代过程中，**以直线代替曲线**，用一阶泰勒展式（即在当前点的切线）代替原曲线，求直线与 $x$ 轴的交点，重复这个过程直到收敛。

![image.png](https://pic.leetcode-cn.com/e6550b4a77fbe722a9a4634619ece70e8b7e60ef7eb2e5b7af7bba3037308879-file_1563817671864)



说明：
1、以上图片来自[《牛顿法与拟牛顿法》](https://blog.csdn.net/batuwuhanpei/article/details/51979831)；

2、@LOAFER 的题解[《牛顿迭代法》](https://leetcode-cn.com/problems/sqrtx/solution/niu-dun-die-dai-fa-by-loafer/) 的图和文字说明更好，而知乎问答[《如何通俗易懂地讲解牛顿迭代法求开方？数值分析？》](https://www.zhihu.com/question/20690553)里面干货就更多了，建议大家出门左转观看，我这篇题解只是展示一下迭代公式如何计算。

![image.png](https://pic.leetcode-cn.com/36b76d291e8c934a5f1826f52f9f4f8b20c47e301e7c408123a43486a8c4e3dc-image.png){:width=550}
{:align=center}

注意：**牛顿法得到的是平方根的浮点型精确值**（可能会有一定误差），根据题目中的要求，把最后得到的这个数转换为 `int` 型，即去掉小数部分即可。

对“牛顿法”感兴趣的朋友们可以查一下牛顿法的应用：一个是求方程的根，另一个是求解最优化问题，在这里就不展开了。

**参考代码 4**：


```Python []
class Solution:

    def mySqrt(self, x):
        if x < 0:
            raise Exception('不能输入负数')
        if x == 0:
            return 0
        # 起始的时候在 1 ，这可以比较随意设置
        cur = 1
        while True:
            pre = cur
            cur = (cur + x / cur) / 2
            if abs(cur - pre) < 1e-6:
                return int(cur)
```
```Java []
public class Solution {

    public int mySqrt(int a) {
        long x = a;
        while (x * x > a) {
            x = (x + a / x) / 2;
        }
        return (int) x;
    }
}
```


说明：`1e-6` 是科学计数法，表示 $1$ 乘以 $10$ 的负 $6$ 次方，也就是 $0.000001$。有的地方使用 `epsilon`（$\epsilon$）表示 `1e-6` ，用来抵消浮点运算中因为误差造成的相等无法判断的情况，它通常是一个非常小的数字，具体多小要根据你的精度需求来设置。

**复杂度分析：**

+ 时间复杂度：（待讨论，反正很快很快就是了 ^_^，调皮一下显示我的无知）。
+ 空间复杂度：$O(1)$，使用了常数个数的辅助空间用于存储和比较。