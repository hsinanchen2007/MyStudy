### 解题思路
感觉思路比较难想，看题解想了半天才想明白，整理一下思路备忘

以 n = 5,m = 3 为例子想思路
准备：
    1、  设f(n,m) 为所求答案，即返回最后剩下的数字
    2、  手动模拟一下得到
            n = 5,m = 3 时答案为3  即 f(5,3) = 3
            n = 4,m = 3 时答案为0  即 f(4,3) = 0

情景模拟：
![image.png](https://pic.leetcode-cn.com/5a84b85788ec5c9a9b43b5e307ebc6396a14c6fd707407e564336eb084215387-image.png)


为了进行递归，要找到 f(n,m) 和 f(n-1,m) 之间的规律

可以看到 n = 5 时，进行第一步操作，删除第一个数字 2 后
将剩下 4 个数字重排, f(5,3) 和 f(4,3)的答案就到了同一位置

通过这个位置相同的规律来建立 f(n,m) 和 f(n-1,m) 的等式，即可进行递归

第一个删除的数字是 m % n ; 为了方便用 k 表示
则将上述规律一般化，得到下图：

![image.png](https://pic.leetcode-cn.com/d069ceebb6fda19660fccad66a8c18e81dcf298f508578cf3708491cfb5f3522-image.png)


根据图可以写出等式：

    f(n-1,m) = ( f(n,m) + 1 ) + n -(k + 1)  

化简：

    f(n,m) = ( f(n-1,m) + k ) % n

把 m % n 代回 k ：

    f(n,m) = ( f(n-1,m) + m % n ) % n = ( f(n-1,m) + m ) % n



### 代码

```python
class Solution(object):
    def lastRemaining(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
        if n == 0 : return 0
        return (self.lastRemaining(n - 1, m) + m) % n
```

至于这个规律怎么证明。。暂时是不太理解的
随便说一下

回到最开始的情景模拟，把f(5,3)中的range(5)数列换成（a,b,c,d,e）来看

甚至是换成乱序的数列来看
![image.png](https://pic.leetcode-cn.com/4c02738130220588f352b9da986f7ae385b4a23c7d2b403a1bc4558bf1237b0d-image.png)
可以发现，数列长度n和每步长度m决定了最后留下的是哪个位置里面的东西

而在题目中，f(n-1,m)的值与其所在的位置是相同的
因此，只要找到每一次删除一个数之后重排得到的（n-1）数列的值与位置的对应关系即可

换个 f(4,3)最后留下的是第0个位置中的值（这里是0）
而 f(5,3) 删除掉一个数并重排之后，就会变成一个乱序的 f(4,3)
而这个乱序的f(4,3)最后会留下的，仍然是第0个位置中的值