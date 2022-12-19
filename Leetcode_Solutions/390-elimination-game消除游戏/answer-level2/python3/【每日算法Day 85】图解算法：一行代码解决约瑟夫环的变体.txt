> 关注公众号【算法码上来】，每日算法干货马上就来！

![宣传图片.jpg](https://pic.leetcode-cn.com/084c8bd856e1a93080731f9b4a9c0adea54fe0a3554a4fa434fdee029a46952b-%E5%AE%A3%E4%BC%A0%E5%9B%BE%E7%89%87.jpg)

## 题解
还记得几天前讲过的约瑟夫环问题吗？不记得了就回顾一下吧：

[韦阳的博客：【每日算法Day 74】经典面试题：约瑟夫环，我敢打赌你一定不会最后一种方法！](https://godweiyang.com/2020/03/19/leetcode-interview-62/ "韦阳的博客：【每日算法Day 74】经典面试题：约瑟夫环，我敢打赌你一定不会最后一种方法！")

[知乎专栏：【每日算法Day 74】经典面试题：约瑟夫环，我敢打赌你一定不会最后一种方法！](https://zhuanlan.zhihu.com/p/114391147 "韦阳的博客：【每日算法Day 74】经典面试题：约瑟夫环，我敢打赌你一定不会最后一种方法！")

当时我们的方法是通过编号映射来递归寻找下一轮存活的人的，那么这题也可以尝试用同样的方法。

我们分奇偶两种情况来考虑。

![1.jpg](https://pic.leetcode-cn.com/07f6f2bcd5c185b782903d54ea416543ca81f9ea646a9f3a9b38fe640f2c2213-1.jpg)

如果 $n=2k$ ，那么如上图所示，第一轮消除完了之后，剩下的数字就是绿色的偶数部分。

接着就要从右往左递归地消除了，那我们从右往左给绿色数字重新编号为 $1$ 到 $k$ ，问题就转化为了 $k$ 个数字的情况下，最后剩余的数字是几了。

假设我们用 $f(2k)$ 表示初始时 $n=2k$ 个数字最后剩下的编号，那么绿色部分重新编号后最后剩下的数字就是 $f(k)$ 。但是怎么将 $f(k)$ 重新映射回绿色的数字编号呢？

通过观察我们可以发现，绿色数字整除 $2$ ，再加上蓝色的映射后的编号，结果一定等于 $k+1$ 。所以我们就得到了映射回去的公式：
$$
f(2k) = 2(k+1-f(k))
$$

比如说你求出来 $f(k) = 2$ ，也就是蓝色部分最后剩下的数字是 $2$ ，那么映射成绿色的编号就是 $2k-2$ ，这就是最初的编号了。

![2.jpg](https://pic.leetcode-cn.com/ceb6009d7ad0c473330cebbea49c09dfa93f3b5272a9c399684317eeaead7141-2.jpg)


如果 $n=2k+1$ ，那么如上图所示，只需要在后面加个橙色的 $2k+1$ 就行了。

但是第一轮的时候它就被消除了，所以绿色的剩下的编号和之前偶数情况没有任何区别。所以最终的答案也是：
$$
f(2k+1) = 2(k+1-f(k))
$$

最后发现奇偶情况下，公式其实可以统一起来，用 $n$ 来替换 $k$ 就得到了：
$$
f(n) = 2\left(\left\lfloor\frac{n}{2}\right\rfloor-f\left(\left\lfloor\frac{n}{2}\right\rfloor\right)\right)
$$

## 代码
### c++
```cpp
class Solution {
public:
    int lastRemaining(int n) {
        return n==1 ? 1 : 2*(n/2+1-lastRemaining(n/2));
    }
};
```

### python
```python
class Solution:
    def lastRemaining(self, n: int) -> int:
        return 1 if n==1 else 2*(n//2+1-self.lastRemaining(n//2))
```