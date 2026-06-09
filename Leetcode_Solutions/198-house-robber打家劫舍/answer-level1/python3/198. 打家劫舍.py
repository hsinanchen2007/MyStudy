1. 设n为房间个数，f(n)为能抢劫到的最大数额，Ai表示第i个房屋的钱数
2. 当n=1时，只有一间房子，没得选，f(1) = A1
3. 当n=2时，有两间房子，哪个的钱多抢哪个，f(2) = max(A1, A2)
4. 当n>=3时，有三个以上房子，这时候要考虑策略了，为方便理解，先看一下n=3的情况，有两种策略
5. 策略一：抢第一间和第三间房子（第二间不能抢了），用公式表示为：f(1)+A3 => f(n-2) + An
6. 策略二：抢第二间房子（第一间和第三间不能抢了），用公式表示为: f(2) => f(n-1)
7. 哪个策略钱多选哪个：f(n) = max(f(n-2) + An, f(n-1))
8. 两个策略会有两种不同的结果，可能理解为两个新房间，和第四个房间一起，又是三个房间，公式依然是 f(n) = max(f(n-2) + An, f(n-1))，以此类推

代码如下：
```
class Solution:
    def rob(self, nums: list) -> int:
        n = len(nums)
        if n == 0:
            return 0
        elif n < 3:
            return max(nums)
        else:
            rob = {}
            rob[1] = nums[0]
            rob[2] = max(nums[0], nums[1])
            for i in range(3, n+1):
                rob[i] = max(rob[i-2] + nums[i-1], rob[i-1])
            return rob[n]
```

稍作优化，去掉字典记录：

```
class Solution:
    def rob(self, nums: list) -> int:
        n = len(nums)
        if n == 0:
            return 0
        elif n < 3:
            return max(nums)
        else:
            rob = 0
            f1 = nums[0]
            f2 = max(nums[0], nums[1])
            for i in range(3, n+1):
                rob = max(f1 + nums[i-1], f2)
                f1 = f2
                f2 = rob
            return rob
```
