这一题思路其实很简单，总结来说就是一句话：每个站点加的油总量必须不小于到达此站点消耗的总油量。如果每个站点加的油总量和小于消耗的总油量，则肯定环绕不了一周。那么最简单的方法就是两次遍历暴力法了，即第一层遍历用来找gas加油站的站号，第二层遍历用来确认从当前站出发是否能环绕一周回到该站。
代码如下：
```Python
class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        # 如果每个站点加的油总量和小于消耗的总油量，则肯定环绕不了一周
        if sum(gas) < sum(cost):
            return -1
        for start in range(len(gas)):
            gas_copy = gas[:]
            cost_copy = cost[:]
            flag = True
            if gas[start] >= cost[start]:
                for end in range(start+1, start+len(gas)):
                    end = end % len(gas)
                    gas_copy[end] += gas_copy[end-1] - cost_copy[end-1]
                    if gas_copy[end] < cost_copy[end]:
                        flag = False
                        break
                if flag == True:
                    return start
        return -1

if __name__ == "__main__":
    gas = [2,3,4]
    cost = [3,4,3]
    location = Solution().canCompleteCircuit(gas, cost)
    print(location)
```

但是很可惜，超出时间限制了。因为时间复杂度是O(n*n)，所以时间超标，那如果我们能把时间复杂度降至O(n)，那肯定就能通过了，即把第二层遍历试着给去掉。我们可以设置一个total_sum专门来记录从站点i到站点j之间gas[i] - cost[i]的总和，只要total_sum大于0，说明从站点i到站点j小车可以一直通过，反之，则说明起点站不是站点i了，要切换成下一个站点遍历了。
代码如下：
```Python
class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        location = 0
        total_sum = 0
        # 如果每个站点加的油总量和小于消耗的总油量，则肯定环绕不了一周
        if sum(gas) < sum(cost):
            return -1
        for index in range(len(gas)):
            total_sum += gas[index] - cost[index]
            if total_sum < 0:
                location = index+1
                total_sum = 0
        return location

if __name__ == "__main__":
    gas = [5,1,2,3,4]
    cost = [4,4,1,5,1]
    location = Solution().canCompleteCircuit(gas, cost)
    print(location)
```
执行效率还算不错的，在80%左右。
![image.png](https://pic.leetcode-cn.com/51a30c7cfbfb9c66b4c77a4c67182ad238a3285f86c33c2a0f61036f84cdd351-image.png)
如果各位读者有更好的方法，还请积极留言啊！！！