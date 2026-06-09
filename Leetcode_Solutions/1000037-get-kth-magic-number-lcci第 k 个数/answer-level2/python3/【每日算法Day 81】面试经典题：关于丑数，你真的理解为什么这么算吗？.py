> 关注公众号【算法码上来】，每日算法干货马上就来！

![宣传图片.jpg](https://pic.leetcode-cn.com/d0e2138882ace0f904d7a0b36f0827a63d738c64164c79383c82e14b2c0772da-%E5%AE%A3%E4%BC%A0%E5%9B%BE%E7%89%87.jpg)


## 题目链接
[LeetCode 面试题 17.09. 第 k 个数](https://leetcode-cn.com/problems/get-kth-magic-number-lcci/ "LeetCode 面试题 17.09. 第 k 个数")

## 题目描述
有些数的素因子只有 3，5，7，请设计一个算法找出第 k 个数。注意，不是必须有这些素因子，而是必须不包含其他的素因子。例如，前几个数按顺序应该是 1，3，5，7，9，15，21。

**示例1**
```text
输入：
k = 5
输出：
9
```

## 题解
这题和主站的**LeetCode 264. 丑数 II**是一个意思：   
[https://leetcode-cn.com/problems/ugly-number-ii/](https://leetcode-cn.com/problems/ugly-number-ii/)

最直观的想法就是，假设已经生成了 $n$ 个丑数，那么我们把每个丑数都乘上 3，5，7，得到的结果中大于已经生成的所有丑数并且最小的那个就是下一个丑数。

但是这样会产生很多重复的丑数，所以也可以用一个优先队列，将已经生成的丑数从小到大保存下来。然后取出队首最小的那个丑数，给它乘上 3，5，7，将新的三个数入队，并且队首的这个数出队，这样就不会再产生重复的数了。

上面这种方法已经可以过这道题了，但是还有更简单的方法。

假设我们用一个数组 $f$ 来从小到大保存每一个丑数，那么 $f[0]$ 就保存着最小的丑数 1 。用三个指针 $p_3, p_5, p_7$ 分别指着最小的那个可以和 $3,5,7$ 相乘的丑数。那么初始的时候都是 0，因为 $f[0]$ 可以和三个因子相乘。

然后判断 $3f[p_3], 5f[p_5], 7f[p_7]$ 三个数谁最小，哪个新丑数最小，就让那个指针往后加 1 ，同时把那个新丑数作为下一个更大的丑数。

这么做为什么是对的呢？我们将 $f$ 数组写成三行相同的形式：

![1.jpg](https://pic.leetcode-cn.com/7f5ceb8a06a1faf4377ef2a66658787eeb37feacd7dc7c0ab3d114565b9fd47e-1.jpg)


那么每一行的指针就表示了有资格和 3，5，7 相乘的最小的丑数。比如 $p_3=3$ ，那就说明只有 $f[3]$ 才有资格和 3 相乘，生成新的丑数，而之前的 $f[2]$ 早就和 3 乘过了，再乘就重复了没有意义。但是可能这时 $p_5=2$，也就是 $f[2]$ 还没和 5 乘过，所以还是有资格乘 5 生成新的丑数的。

本质上相当于用了三个优先队列，来存储已生成的丑数。但是因为已生成的丑数是递增的，所以就用普通的队列也就是数组+指针就行了。每次三个队首元素乘上对应因子比较一下，取最小的那个出队，并且三个队列都要入队新丑数。


## 代码
### c++
```cpp
class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<int> res(k, 1);
        int idx3 = 0, idx5 = 0, idx7 = 0;
        for (int i = 1; i < k; ++i) {
            res[i] = min(res[idx3]*3, min(res[idx5]*5, res[idx7]*7));
            if (res[i] == res[idx3]*3) idx3++;
            if (res[i] == res[idx5]*5) idx5++;
            if (res[i] == res[idx7]*7) idx7++;
        }
        return res[k-1];
    }
};
```


### python
```python
class Solution:
    def getKthMagicNumber(self, k: int) -> int:
        res = [1] * k
        idx3, idx5, idx7 = 0, 0, 0
        for i in range(1, k):
            res[i] = min(res[idx3]*3, res[idx5]*5, res[idx7]*7)
            if res[i] == res[idx3]*3: idx3 += 1
            if res[i] == res[idx5]*5: idx5 += 1
            if res[i] == res[idx7]*7: idx7 += 1
        return res[k-1]
```