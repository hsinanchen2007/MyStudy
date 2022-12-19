

## 题解
### 逐位考虑
我们单独看二进制某一位，先不看单独的那个数，其他所有数字都出现了 3 次，所以那一位是 1 的个数一定是 3 的倍数。

再考虑这个出现一次的数，如果这一位是 1 ，那么这一位 1 的次数模 3 为 1 ，否则的话模 3 就是 0 。

那么就很简单了，统计一下有多少个数这一位上是 1 ，然后模 3 取余数，结果就是这个单独的数这一位上的值了。

遍历 32 位整数的每一位，就可以得到这个单独的数是多少了。

**推广到一般情况：**  
如果其他数都出现了 $k$ 次，一个数出现了一次。那么如果 $k$ 是偶数，还是把所有的数异或起来就行了。如果 $k$ 是奇数，那么统计每一位是 1 的个数，然后模 $k$ 取余数就能得到那个单独的数了。

### 位运算
我们还可以用自动机来做这题，根据某一位 1 的个数，我们可以得到如下的状态自动机：
![1.png](https://pic.leetcode-cn.com/0870aaae9fbdff191beb86c6bfb31a7a236c6f15a49974cbbff2453e694bcbcf-1.png)

初始的时候在状态 0 （有 0 个 1），然后如果下一个数这一位是 1，就进入状态 1（有 1 个 1），接着如果下一个数这一位是 1，就进入状态 2（有 2 个 1），接着如果下一个数这一位是 1，就进入状态 3（有 3 个 1），最后如果再来了一个数这一位还是 1，就说明是一个新的数了，等价于回到了状态 1。而每个状态如果来的数这一位是 0 ，都会保持状态不变。

当然这个自动机还可以简化，注意观察可以发现状态 3 和状态 0 是等价的（输入 0 都保持不变，输入 1 都会进入状态 1）。所以我们将状态 1 和状态 3 合并为一个状态 0 ，得到如下的状态自动机：
![2.jpg](https://pic.leetcode-cn.com/0381991a29b66a5eb4f1528c6c50cd6148a1284d1ea80320351443161cf1867c-2.jpg)


因为一共有三个状态，所以我们需要用两个变量来表示状态。用 `once` 表示是否在状态 1，用 `twice` 来表示是否在状态 2 。那么两个变量都为 0 就表示在状态 0 。然后可以得到如下的状态转移表：
![3.jpg](https://pic.leetcode-cn.com/d7fdbce1a5c3ea1cfb3bc5bce019860e8320a18151ea9b30b5ae97428aabbbd8-3.jpg)


注意观察 `once` 只有两种情况下转移后为 1 。一种是 `once=0, twice=0, x=1` ，另一种是 `once=1, twice=0, x=0` 。其他所有情况下 `once` 都转移为 0 。这两种情况都满足 `x^once=1` 并且 `twice=0` ，所以 `once` 的转移就是 `once = (x^once) & (~twice)` 。

同理，观察 `twice` 只有两种情况下转移后为 1 。一种是 `once=1, twice=0, x=1` ，另一种是 `once=0, twice=1, x=0` 。其他所有情况下 `twice` 都转移为 0 。这两种情况都满足 `x^twice=1` 并且 `once^twice=1` ，所以 `twice` 的转移就是 `twice = (x^twice) & (once^twice)` 。**但是**！！！ `once` 已经抢先一步转移过了，所以值已经变掉了，一个解决方法就是用临时变量保存一下前一个状态的 `once` 值。另一个方法就是，这两种情况下，`once` 都会转移到 0 ，所以判断条件直接用转移后的 `once=0` 就行了，随后转移就是 `twice = (x^twice) & (~once)` 。

## 代码
### 逐位考虑（c++）
```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int cnt = 0;
            for (auto x : nums) {
                cnt += (x>>i)&1;
            }
            res |= (cnt%3)<<i;
        }
        return res;
    }
};
```

### 位运算（c++）
```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int once = 0, twice = 0;
        for (auto x : nums) {
            once = (once^x)&(~twice);
            twice = (twice^x)&(~once);
        }
        return once;
    }
};
```

## 相关题目
[LeetCode 136. 只出现一次的数字](https://leetcode-cn.com/problems/single-number/ "LeetCode 136. 只出现一次的数字")
[LeetCode 面试题56 - I. 数组中数字出现的次数](https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/ "LeetCode 面试题56 - I. 数组中数字出现的次数")
[LeetCode 面试题 17.19. 消失的两个数字](https://leetcode-cn.com/problems/missing-two-lcci/ "LeetCode 面试题 17.19. 消失的两个数字")