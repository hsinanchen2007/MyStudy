```
'''
LeetCode 829 连续整数求和
Given a positive integer N, how many ways can we write it as a sum of consecutive positive integers?
Example 1:
Input: 5
Output: 2
Explanation: 5 = 5 = 2 + 3
Example 2:
Input: 9
Output: 3
Explanation: 9 = 9 = 4 + 5 = 2 + 3 + 4
Example 3:
Input: 15
Output: 4
Explanation: 15 = 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
Note: 1 <= N <= 10 ^ 9.

题目大意：
给定一个正整数 N，试求有多少组连续正整数满足所有数字之和为 N?
示例 1:
输入: 5
输出: 2
解释: 5 = 5 = 2 + 3，共有两组连续整数([5],[2,3])求和后为 5。
示例 2:
输入: 9
输出: 3
解释: 9 = 9 = 4 + 5 = 2 + 3 + 4
示例 3:
输入: 15
输出: 4
解释: 15 = 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
说明: 1 <= N <= 10 ^ 9

解题思路：
这道题比较简单，拿来一道题，上来直接把自己当计算机模拟一遍，你去解怎么解答，我是这样想
方法1：暴力法（考试面试是不行的哈）
方法一：枚举 [超出时间限制]
我们枚举连续正整数的开始值 start，并进行累加，直到结果大于等于 N。如果结果刚好等于 N，我们就找到了一组答案。
例如当 N = 6 时，若开始值为 1，我们会累加得到 1 + 2 + 3 = 6，得到一组答案；
若开始值为 2，我们会累加得到 2 + 3 + 4 = 9，超出了 6。以此类推，直到开始值超过 N。
这种方法会超出时间限制，直接上代码，时间复杂度N*根号N
class Solution(object):
    def consecutiveNumbersSum(self, N):
        ans = 0
        for start in range(1, N+1):
            target = N
            while target > 0:
                target -= start
                start += 1
            if target == 0:
                ans += 1
        return ans
方法二：简单数学简化
假设 k 个连续正整数的和为 N，即N=(x+1)+(x+2)+⋯+(x+k)，其中x≥0，k≥1。上式经过拆分可以得到N=kx+1/2*k(k+1)，即 2N=k(2x+k+1)。
我们可以枚举 k，根据上面的等式，k 的取值范围为1≤k≤2N。
对于每一个 k，我们计算出 x = 1/2 * （2N/k - k -1），通过遍历1-2N范围内当k，只要发现x为正数，就是符合条件的。
时间复杂度N
class Solution(object):
    def consecutiveNumbersSum(self, N):
        # 2N = k(2x + k + 1)
        ans = 0
        for k in xrange(1, 2*N + 1):
            if 2*N % k == 0: # 首先就得保证局部可以整除
                x = 2 * N / k - k - 1
                if x % 2 == 0 and x >= 0:
                    ans += 1
        return ans
方法三：进一步优化
在 2N = k(2x+k+1) 中，我们可以发现k<2x+k+1，因此有 k < 根号2N，即我们只需要枚举1～根号2N
我们还可以继续挖掘一些性质。由于 k 和 2x+k+1 的奇偶性不同，此时将 2N 写成 2^a* M的形式，即2N有偶次幂*一个奇数
对于 M 的一种拆分 M = a * b, 因此拆分2N我们可以简化为拆分M，具体看代码。
class Solution(object):
    def consecutiveNumbersSum(self, N):
        while N & 1 == 0: # 偶数的时候，将2的a次幂分离，此时转化为拆分M
            N >>= 1

        ans = 1
        d = 3 # 因为M是个奇数，且初始ans为1，包括了1*自身，所以d从3开始
        while d * d <= N: # 分解因子当然不超过根号n，分配方式后面*2即可
            e = 0 # 统计有多少个因子
            while N % d == 0: # 此时的d是一个因子
                N /= d # 因为是计算全部因子，所以统计d为因子后，就把他除去
                e += 1 # 计数+1
            ans *= e + 1 # 因为是求的因子分配结合情况，因此对于每一个d，分配情况为当前结果*剩下的因子数+1种
            # 比如M=45=3*15，d=3时候，剩下的15还可以分配为3和5，肯定是后面3和5都可以和前面的d=3结合，因此累计乘法，因为N是累计/d的
            d += 2 # 因为是奇数，因子为奇数


        if N > 1: # M=a*b，除去上面统计过的因子后，仍然大于1，交换a和b也是分配方法，不大于1代表a=b，不可以*2
            ans *= 2
        return ans
方法四：看到了一个网上的办法，但是没有方法三快
class Solution(object):
    def consecutiveNumbersSum(self, N: int) -> int:
        # 1个数时，必然有一个数可构成N
        # 2个数若要构成N，第2个数与第1个数差为1，N减掉这个1能整除2则能由商与商+1构成N
        # 3个数若要构成N，第2个数与第1个数差为1，第3个数与第1个数的差为2，N减掉1再减掉2能整除3则能由商、商+1与商+2构成N
        # 依次内推，当商即第1个数小于等于0时结束
        res, i = 0, 1 # i代表，只有i个数的时候
        while N > 0:
            if N % i == 0: # 有i个数就要被i整除
                res += 1
            N -= i # # 这是传递下来的差值，比如由3个数构成，比由2个数构成多减了一个2，有这句前面的减1就可以省略，因为3个数构成既要-1，也要-2
            i += 1 # 递增
        return res

'''
class Solution(object):
    def consecutiveNumbersSum(self, N):
        while N & 1 == 0: # 偶数的时候，将2的a次幂分离，此时转化为拆分M
            N >>= 1

        ans = 1
        d = 3 # 因为M是个奇数，且初始ans为1，包括了1*自身，所以d从3开始
        while d * d <= N: # 分解因子当然不超过根号n，分配方式后面*2即可
            e = 0 # 统计有多少个因子
            while N % d == 0: # 此时的d是一个因子
                N /= d # 因为是计算全部因子，所以统计d为因子后，就把他除去
                e += 1 # 计数+1
            ans *= e + 1 # 因为是求的因子分配结合情况，因此对于每一个d，分配情况为当前结果*剩下的因子数+1种
            # 比如M=45=3*15，d=3时候，剩下的15还可以分配为3和5，肯定是后面3和5都可以和前面的d=3结合，因此累计乘法，因为N是累计/d的
            d += 2 # 因为是奇数，因子为奇数


        if N > 1: # M=a*b，除去上面统计过的因子后，仍然大于1，交换a和b也是分配方法，不大于1代表a=b，不可以*2
            ans *= 2
        return ans
if __name__ == "__main__":
    N = 9
    s = Solution()
    print(s.consecutiveNumbersSum(N))
```
