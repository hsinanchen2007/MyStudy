### 思路一：暴力

从第一个小朋友开始发，直到糖果发完。注意两个问题：

*1. 如何回到队伍起点：* 用 `give % num_people` 表示索引（$give$ 为本次应发的糖果数）；

*2. 保证最后一个人得到剩余糖果：* 取剩余糖果和应发糖果的最小值。


#### 代码

```python []
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        people = [0] * num_people
        give = 0
        while candies > 0:
            people[give % num_people] += min(give + 1, candies)
            give += 1
            candies -= give
        return people
```

```C++ []
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> people (num_people, 0);
        int give = 0;
        
        while (candies > 0){
            people[give % num_people] += min(give + 1, candies);
            give++;
            candies -= give;
        }
        return people;
    }
};
```

#### 复杂度分析
- 时间复杂度：$\mathcal{O}(max(\sqrt{G},N))$，$G$ 为糖果数量，$N$ 为人数。
- 空间复杂度：$\mathcal{O}(n)$，使用了 `peopel` 数组。

### 思路二：找规律

可以看到每一轮分的糖果总数为 $n(n+1)/2+round\times n^2$，$n$ 为人数，$round=0,1,...$

![1.png](https://pic.leetcode-cn.com/39e89cfc6f70de6f3fe0955768d015acf09d04d3549f1308216da212b24e123c-1.png)

因此我们首先计算可以完整地分几轮 $rounds$，然后一次性发放；

一次性发放时，对于每个下标为 $i$ 的小朋友，应该得到的糖果为：

$$(i+1+0)+(i+1+1\times n)+...(i+1+(rounds-1)\times n))$$

$$=(i + 1) * rounds + ((rounds - 1) \times rounds/ 2) \times n $$

最后剩下不足一轮的糖果按照思路一发完即可。

![1103.gif](https://pic.leetcode-cn.com/e629d7ccfc5b51d1578c4b8e44faf718debd7d1777acaa428c3c1b428b0e665e-1103.gif)
#### 代码
```python []
class Solution:
    def distributeCandies(self, candies: int, n: int) -> List[int]:
        # 计算能分几轮
        rounds, cur = 0, 0
        while cur + n * (n + 1) // 2 + rounds * n * n < candies:
            cur += n * (n + 1) // 2 + rounds * n * n
            rounds += 1
        # 一次发完 rounds 轮
        people = [0] * n
        for i in range(n):
            people[i] = (i + 1) * rounds + ((rounds - 1) * rounds * n) // 2
            candies -= people[i]
        # 分配剩余的糖果（思路一）
        give = n * rounds
        i = 0
        while candies > 0 and i < n:
            people[i] += min(give + 1, candies)
            give += 1
            candies -= give
            i += 1
        return people
```
#### 复杂度分析
- 时间复杂度：$\mathcal{O}(max(rounds,N))$，$rounds$ 为轮数，$N$ 为人数。
- 空间复杂度：$\mathcal{O}(n)$，使用了 `peopel` 数组。

如有问题，欢迎讨论~