```
'''
LeetCode 871 最低加油次数
A car travels from a starting position to a destination which is target miles east of the starting position.
Along the way, there are gas stations.  Each station[i] represents a gas station
that is station[i][0] miles east of the starting position, and has station[i][1] liters of gas.
The car starts with an infinite tank of gas, which initially has startFuel liters of fuel in it. 
It uses 1 liter of gas per 1 mile that it drives.
When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.
What is the least number of refueling stops the car must make in order to reach its destination? 
If it cannot reach the destination, return -1.
Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there. 
If the car reaches the destination with 0 fuel left, it is still considered to have arrived.
Example 1:
Input: target = 1, startFuel = 1, stations = []
Output: 0
Explanation: We can reach the target without refueling.
Example 2:
Input: target = 100, startFuel = 1, stations = [[10,100]]
Output: -1
Explanation: We can't reach the target (or even the first gas station).
Example 3:
Input: target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
Output: 2
Explanation:
We start with 10 liters of fuel.
We drive to position 10, expending 10 liters of fuel.  We refuel from 0 liters to 60 liters of gas.
Then, we drive from position 10 to position 60 (expending 50 liters of fuel),
and refuel from 10 liters to 50 liters of gas.  We then drive to and reach the target.
We made 2 refueling stops along the way, so we return 2.
Note:
1 <= target, startFuel, stations[i][1] <= 10^9
0 <= stations.length <= 500
0 < stations[0][0] < stations[1][0] < ... < stations[stations.length-1][0] < target

题目大意：
汽车从起点出发驶向目的地，该目的地位于出发位置东面 target 英里处。
沿途有加油站，每个 station[i] 代表一个加油站，它位于出发位置东面 station[i][0] 英里处，并且有 station[i][1] 升汽油。
假设汽车油箱的容量是无限的，其中最初有 startFuel 升燃料。它每行驶 1 英里就会用掉 1 升汽油。
当汽车到达加油站时，它可能停下来加油，将所有汽油从加油站转移到汽车中。
为了到达目的地，汽车所必要的最低加油次数是多少？如果无法到达目的地，则返回 -1 。
注意：如果汽车到达加油站时剩余燃料为 0，它仍然可以在那里加油。如果汽车到达目的地时剩余燃料为 0，仍然认为它已经到达目的地。
示例 1：
输入：target = 1, startFuel = 1, stations = []
输出：0
解释：我们可以在不加油的情况下到达目的地。
示例 2：
输入：target = 100, startFuel = 1, stations = [[10,100]]
输出：-1
解释：我们无法抵达目的地，甚至无法到达第一个加油站。
示例 3：
输入：target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
输出：2
解释：
我们出发时有 10 升燃料。
我们开车来到距起点 10 英里处的加油站，消耗 10 升燃料。将汽油从 0 升加到 60 升。
然后，我们从 10 英里处的加油站开到 60 英里处的加油站（消耗 50 升燃料），
并将汽油从 10 升加到 50 升。然后我们开车抵达目的地。
我们沿途在1两个加油站停靠，所以返回 2 。
提示：
1 <= target, startFuel, stations[i][1] <= 10^9
0 <= stations.length <= 500
0 < stations[0][0] < stations[1][0] < ... < stations[stations.length-1][0] < target

解题思路：
动态规划的方法，但这里需要做个转换，原题是求加油的最少的次数，其实可以转换为在有n个加油站的情况下，
加i次油（i<=n）的情况下，车子能走的最长路径，算法的时间复杂度是O(n^2)。
dp三要素：
1，状态定义：dp[i] 为加 i 次油能走的最远距离，题目结果就是满足 dp[i] >= target 的最小 i。
2，边界就是dp[0] = startFuel
3,状态转移方程：
依次计算每个 dp[i]，对于 dp[0]，就只用初始的油量 startFuel 看能走多远。
每多一个加油站 station[i] = (location, capacity)，
如果之前可以通过加 t 次油到达这个加油站，现在就可以通过加 t+1 次油得到 capcity 的油量。
举个例子，原本加一次油可以行驶的最远距离为 15，现在位置 10 有一个加油站，有 30 升油量储备，那么显然现在可以加两次油行驶 45 距离。
这里注意一个点，对于每一个加油站，也就是更新dp[t+1]时候，由于新加了一个加油站，后面的加油站会影响前面的，因此只能从后往前遍历
如果从前往后更新，就错了，你好好想一下这个问题。

更详细解释：
算法核心在于抽象问题，也就是建模，大白话说，就是简化问题到另外一种形式
动态规划的算法核心是根据上一个状态求出下一个状态，一次性求解出全部状态的答案，然后返回你需要的，有的返回dp0有的返回dp-1
对于这道题，首先我们使用dp状态定义，简化问题，设dpi状态表示，加i次油最远可达距离，返会结果当然是dpi大于target时候的最小i
至此，all u need to think is what's dp[i], not the original question
然后边界就太简单了，dp0就是不加油最远跑到哪，当然就是初始油量
最后一个就是解决状态转移，如何从dp0转移到dp1，当然是能到达的情况下（dp[t] >= location），加油后更新为当前最大值
但是注意一点，更新dpi的时候，是不是前面i-1的加油站都要考虑进去？
i通过i-1得到，i-1也会由i-2得到，也就是说后面会影响前面的，因此需要从后面向前更新每个位置的最大值
'''
class Solution(object):
    def minRefuelStops(self, target, startFuel, stations):
        dp = [startFuel] + [0] * len(stations)
        for i, (location, capacity) in enumerate(stations):
            for t in range(i, -1, -1):
                if dp[t] >= location:
                    dp[t+1] = max(dp[t+1], dp[t] + capacity)  # 更新为更大值

        for i, d in enumerate(dp):
            if d >= target: return i # 就是返回能到达终点的最小i
        return -1
'''
if __name__ == "__main__":
    target = 100
    startFuel = 10
    stations = [[10,60],[20,30],[30,30],[60,40]]
    s = Solution()
    print(s.minRefuelStops(target, startFuel, stations))
'''
```
