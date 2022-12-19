### 解题思路
先假设有无限的糖果。假设有n个人，写出前几轮发放的糖果：
![image.png](https://pic.leetcode-cn.com/d921a0d47a69d60d349828f9842835cf814dba373fbb2ad55251f697608bd28e-image.png)

可以很明显的看出来：
1. 每一行都是一个公差为 `1` 的等差数列，首项为 `(loop - 1) * m + i`, 其中，`loop`表示发放轮数，`i`表示第`i`个人
2. 每一列都是一个公差为 `m` 的等差数列，首项为 `(loop - 1) * m + i`。

现在糖果是有限个了，如果能确定糖果发满了几轮，那么每个人通过这几整轮所得的糖果数就能通过每一列的那个等差数列求和得到了。`求和公式：S = (a0 + an) * n / 2`。
但是糖果并不一定是能整好发满 `loop` 轮的。假设 `loop` 轮之后，剩余了 `left` 个糖果，我们只需要在计算每个人最终糖果数的时候（即遍历结果数组的时候）,如果有剩余糖果，就再给这个人补发他应该得到的糖果数就行了。

### 代码

```golang
func distributeCandies(candies int, num_people int) []int {
    // 结果数组
    ans := make([]int, num_people, num_people)
    // loop 记录能发完几整轮，i表示下一轮的首项（即第一个人该发几个糖果）
    loop, i := 0, 1
    // 如果当前糖果数不小于发完这一整轮所需的糖果数，轮数就增加一轮，然后扣除发这一轮糖果的总数
    for candies-sum(i, num_people, 1) >= 0 {
        loop++
        candies -= sum(i, num_people, 1)
        i += num_people
    }
    // 上面循环结束后，candies的值就是发完 loop 轮后，还剩多少糖果。
    // 现在求每个人能拿到的糖果总数
    for i = 0; i < num_people; i++ {
        // 首先发完 loop 整轮后，每个人都能拿到的糖果数
        // 即求公差为 num_people, 首项为 i+1 的前loop项和（因为这里i是从0计数的）
        ans[i] = sum(i+1, loop, num_people)
        // 如果还有剩余的糖果，就给这个人补发他应得的糖果
        if candies > 0 {
            // ak表示这个人最多补发多少糖果，就是这一列的等差数列的第 loop+1 项
            ak := i + 1 + loop*num_people
            // 如果剩余糖果不小于 ak，第 i 个位置上再附加上ak个糖果
            if candies >= ak {
                ans[i] += ak
            } else { // 否则把剩下所有糖果分配给这个人
                ans[i] += candies
            }
            // 补发完后，扣除补发的糖果数
            candies -= ak
        }
    }
    return ans
}

func sum(a0 int, n int, p int) int {
    // 求首项为a0,公差为p的前n项和
    return (2*a0 + (n-1)*p) * n / 2
}
```