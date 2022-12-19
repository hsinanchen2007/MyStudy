## 思路

我们的思路是计算所有骰子点数出现的次数，然后除以总的可能数即可，总的可能性容易求出，为  `6 ^ n`，问题的关键在于求解每一个点数出现的次数。

首先很明显只有一个骰子的时候，1，2，3，4，5，6出现的次数都为1。

![](https://pic.leetcode-cn.com/ef44d0628904cd4ede428b2c85cd34974527e08a0eada944d0531eb660d2deb4.jpg)

那么如果两个骰子，出现次数为7的话，有多少种呢？应该是6种，分别是：

![](https://pic.leetcode-cn.com/3b55e1c02c9fc5c5b2aace430075b324cace7e0d75a84be2dbefab70959f03b4.jpg)

那么如果两个骰子，出现次数为8的话，有多少种呢？应该是5种，分别是：

![](https://pic.leetcode-cn.com/1bcc6523e7057edac0a3f5371541230ff1d0622048c4ba27699ef882fa45cd59.jpg)

我们发现，我们只需要用一个数组cnts，cnts[i] 表示掷出i的次数，那么cnts[i] 就等于前面六个相加，或者前面五个相加，或者。。。。

为了简单起见，我们从后往前遍历，这样我们的逻辑可以统一为 **cnts[i] 就等于前面六个cnts[j]相加**，其中j等于i - 1, i - 2, i - 3, i - 4, i - 5, i - 6。


如果使用迭代，我们只需要迭代n - 1次，每次迭代相当于一次投掷，而内层循环的逻辑就是上面提到的，我们每次投掷都去更新cnts[i]


## 迭代

Python Code:

```python
class Solution:
    def twoSum(self, n: int) -> List[float]:
        if n == 0:
            return []
        # 初始化 1 - 6 是 1次，7 - n 是 0 次。
        # 编号从1开始，这样方便写代码。  为了从1开始，我们只需要在数组前面随便push一个元素即可，比如本例的0
        cnts = [0] + [1] * 6 + [0] * (6 * n - 6)
        # 模拟投掷 n - 1 次
        for _ in range(n - 1):
            # 从后向前更新
            for i in range(6 * n, 0, -1):
                cnts[i] = sum(cnts[max(i - 6, 0): i])

        return filter(lambda a: a != 0, list(map(lambda a: a / 6 ** n, cnts)))

```

JavaScript Code:

```js
/**
 * @param {number} n
 * @return {number[]}
 */
var twoSum = function(n) {
      if (n < 1) {
        return [];
      }
      const res = [0, 1, 1, 1, 1, 1, 1];
      for (let i = 1; i < n; i++) {
        for (let j = 6 * n; j > 0; j--) {
          res[j] = res
            .slice(Math.max(0, j - 6), j)
            .reduce((acc, cur) => acc + cur, 0);
        }
      }
      return res.slice(1).map(num => num / Math.pow(6, n)).filter(Boolean);
};
```


## 递归 

Python Code:

```python
class Solution:
    def twoSum(self, n: int) -> List[float]:
        def diceCnt(n):
            if n == 1:
                return [0] + [1] * 6
            cnts = diceCnt(n - 1) + [0] * 6
            for i in range(6 * n, 0, -1):
                cnts[i] = sum(cnts[max(i - 6, 0): i])
            return cnts
        return filter(lambda a: a != 0, list(map(lambda a: a / 6 ** n, diceCnt(n))))
```

JavaScript Code:

```js
/**
 * @param {number} n
 * @return {number[]}
 */
var twoSum = function(n) {
      function diceCnt(n) {
        if (n === 1) {
            return [0, 1, 1, 1, 1, 1, 1];
        }

        cnts = diceCnt(n - 1);
        for (let i = 6 * n; i > 0; i--) {
            cnts[i] = cnts
            .slice(Math.max(i - 6, 0), i)
            .reduce((acc, cur) => acc + cur, 0);
        }

        return cnts;
        }
        return diceCnt(n)
            .map(num => num / Math.pow(6, n))
            .filter(Boolean)
};
```

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/960f0fcedb710cca012ce919c8cd275be29ce72312da2da095b0eb13b99ec60f.jpg)