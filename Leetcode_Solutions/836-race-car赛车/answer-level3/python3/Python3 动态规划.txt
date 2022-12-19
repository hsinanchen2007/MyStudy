### 解题思路
`dp[i]`：车子从0行驶到i的最短指令长度，起始速度是1，和target方向相同。
`dp[0] = 0`，我们要求的是`dp[target]`。

因为每次转向，车速会变为1，所以我们可以利用这个特性来复用之前在dp里存的值，即可以找到重复子问题。每次车子转向了，车速变为1，如果这时的速度方向也是朝向target，那就和起初状态相同了，可以用dp了！所以，我们需要找到这种情况，就可以分解成子问题了。

我们能用的是A和R，但我们不知道中途会用多少次A和R。假设我们先A了k次，在k次加速后的位置是：`pos = 2^k - 1`

- 如果`pos < target`：要先A若干次再R（这时行驶方向和target相反了）再若干次A再R。
**AA…ARA…AR**
在这两次R之间 假设A了q次，这时的位置在 `pos - (2^q - 1)`。
然后这时候是第二次的R，speed = 1，方向和target相同。这个就等于从0走到`target - (pos - (2^q - 1))`，这个步骤的最短指令集长度就是`dp[target - (pos - (2^q - 1))]`。
所以，这个情况的全部指令集长度是 `k （先A了k次） + 1 （R） + q  （再A了q次） + 1 （R） + dp[target - (pos - (2^q - 1))]`。
`dp[i] = min(dp[i], k + 1 + q + 1 + dp[target - (pos - 2^q - 1)])`

- 如果`pos == target`：可以直接一直A到target。
**AA…A**
这时最短指令集长度就是k，不用任何转向。为啥是最短？因为如果能直接A到，也不用任何转向就是最少的指令了。
`dp[i] = k`

- 如果`pos > target`：需要一次R，使车子现在朝向target。
**AA…ARAA…A**
R过之后，现在需要达到target的距离是 pos - target，速度为1，等同于原来从正方向驶向target的指令集长度。再加上之前的k次A和一次R，所以总的指令集长度为 `k + 1 + dp[pos - target]`。
`dp[i] = k + 1 + dp[pos - target]`

### 代码
```python
class Solution:
    def racecar(self, target: int) -> int:
        dp = [float('inf')] * (target + 1)

        for i in range(1, target + 1):
            k = 1 # A的次数
            pos = 1

            while pos < i:  # pos < target
                q = 0 # R过一次后A的次数
                while ((1 << q) - 1) < pos:
                    dp[i] = min(dp[i], k+1+q+1+dp[i-(pos-((1 << q) - 1))])
                    q += 1
                k += 1
                pos = (1 << k) - 1
            
            if i == pos: # pos == target
                dp[i] = k
            else: # pos > target
                dp[i] = min(dp[i], k + 1 + dp[pos-i])
        
        return dp[target]
```