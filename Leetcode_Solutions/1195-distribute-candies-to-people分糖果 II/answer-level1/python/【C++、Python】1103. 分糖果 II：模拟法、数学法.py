### 方法一：模拟法 ###
#### 思路 ####
- 模拟整个分发糖果的过程即可
#### 演示 ####
![1103.gif](https://pic.leetcode-cn.com/671a40786e678ef0913e811c7d5b2ca0bfe3ae278f2bb4a613a7cd74edd1c5f4-1103.gif)

#### 代码 ####
```cpp []
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        int cnt = 1;
        while (cnt <= candies) {
            res[(cnt - 1) % num_people] += cnt;
            candies -= cnt++;
        }
        res[(cnt - 1) % num_people] += candies;
        return res;
    }
};
```
```python []
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        res, cnt = [0] * num_people, 1
        while cnt <= candies:
            res[(cnt - 1) % num_people] += cnt
            candies -= cnt
            cnt += 1
        res[(cnt - 1) % num_people] += candies
        return res
```
#### 复杂度分析 ####
- 时间复杂度 $O(max(\sqrt{candies}, peoples))$
- 空间复杂度 $O(1)$
***
### 方法二：数学法 ###
#### 思路 ####
##### 计算分发糖果的操作次数 #####
- 首先求出分发糖果操作的总次数 $times$，根据**等差数列求和公式**，可得
  - 若最后一次发糖果时，恰巧还剩余 $times$ 颗，则有
  $$distributed = \frac{times(times + 1)}{2} = candies$$
  - 若剩下的糖果数不够 $times$ 颗，则**不将最后一次发糖果计入总次数**（后面作为特殊情况进行处理），有
  $$distributed =\frac{times(times + 1)}{2} < candies$$
- 综上，可得
$$distributed =\frac{times(times + 1)}{2} \le candies$$
- 根据**一元二次方程求根公式**解方程
$$ times^2 + times - 2C = 0$$
- 舍去负根，有
$$times = \sqrt{2C + \frac{1}{4}} - \frac{1}{2} $$
- 解方程直接得到的 $times$ 可能不是整数，为了保证 $distributed \le candies$，$times$ 应该向下取整
$$times = floor(\sqrt{2C + \frac{1}{4}} - \frac{1}{2})$$
- 然后，因为 $times$ 向下取整，可能剩下 $remains$ 个糖果没发完（$remains$ 一定是小于 $times + 1$ 的，因为 $distributed + times + 1 > candies$）
$$remains = candies - distributed$$
##### 计算回合数和终止位置 #####
- 从队头分发到队尾称为一个回合，我们可以根据 $times$ 和总人数 $peoples$ 计算出总的回合数 $rounds$
$$rounds = floor(\frac{times}{peoples})$$
- 最后一个小朋友的位置 $end$，可由下式计算
$$ end = times \bmod peoples$$
- 因为 $times$ 是从 $1$ 开始计数的，$end + 1$ 是 $times$ 次分发后的下一个小朋友的位置（从 $1$ 开始计数） 
##### 计算每个小朋友应得的糖果数 #####
- 对于第 $i$ 个小朋友（$i$ 从 $1$ 开始计数），$rounds$ 个完整回合应得的糖果总数为
$$res[i] = i + (i + peoples) + (i + 2peoples) + \cdots + (i + (rounds - 1)peoples)$$
- 求和得到
$$\begin{aligned} res[i] &= \frac{(i + i + (rounds - 1)peoples)rounds}{2} \\ 
&= i \times rounds + \frac{rounds(rounds - 1)}{2} \times peoples \end{aligned}$$
- 若 $i < end$，还应该加上最后的不完整回合的 $i + 1 + rounds\times peoples$ 个糖果
- 若最后还有剩余的糖果，将 $remains$ 分给第 $end + 1$ 个（从 $1$ 开始计数）小朋友
#### 算法 ####
- 初始化长度为`num_people`的全`0`数组
- 计算分配次数`times`，其值为`sqrt(2 * candies + 0.25) - 0.5`
- 计算剩余糖果数`remains`，其值为`candies - times * (times + 1) * 0.5`
- 计算回合数`rounds`和终止位置`end`，分别为`times / num_people`和`times % num_people`
- 设置`i`的初始值为`1`，循环`num_people`次，`i`每次递增`1`
  - 为`res[i]`赋值`(i + 1) * rounds + rounds * (rounds - 1) * num_people * 0.5`
  - 如果`i < end`，给`res[i]`增加`i + 1 + rounds * num_people`
- 将剩余糖果分配给`res[end]`

#### 代码 ####
```cpp []
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        int times = sqrt(2 * candies + 0.25) - 0.5, remains = candies - times * (times + 1) * 0.5;
        int rounds = times / num_people, end = times % num_people;
        for (int i = 0; i < num_people; ++i) {
            res[i] = (i + 1) * rounds + rounds * (rounds - 1) * num_people * 0.5;
            if (i < end) res[i] += i + 1 + rounds * num_people;
        }
        res[end] += remains; 
        return res;
    }
};
```
```python []
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        res = [0] * num_people
        times = int((2 * candies + 0.25) ** 0.5 - 0.5)
        remains = candies - int(times * (times + 1) * 0.5)
        rounds, end = divmod(times, num_people)
        for i in range(num_people):
            res[i] = (i + 1) * rounds + int(rounds * (rounds - 1) * 0.5) * num_people
            if i < end:
                res[i] += i + 1 + rounds * num_people
        res[end] += remains
        return res
```
#### 复杂度分析 ####
- 时间复杂度 $O(peoples)$
- 空间复杂度 $O(1)$