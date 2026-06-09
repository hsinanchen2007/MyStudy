思路一
```python
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n=len(gas)
        for i in range(n):
            gas_cont=gas[i]
            gas_cont-=cost[i]
            index=(i+1)%n
            # index=i+1
            while index!=i:
                if gas_cont<0:
                    break
                gas_cont+=gas[index]
                gas_cont-=cost[index]
                index=(index+1)%n
            if gas_cont>=0 and index==i:
                return i
        return -1
```

 1. 首先按照题目描述编一下，对以每一个点为开始的进行一个遍历。遇到可以的就直接return 
 2. 这里对于他的处理利用了类似循环队列的处理方式
 ## 思路二

```python
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n=len(gas)
        temp=[]
        for i in range(n):
            temp.append(gas[i]-cost[i])
            #front+=temp
        x1=0
        x2=0
        start=0
        for i in range(n):
            x1+=temp[i]
            x2+=temp[i]
            if x2<0:
                x2=0
                start=i+1
        return start if x1>=0 else -1
```

 1. 接下来我们考虑能不能优化一下尽量在O(n)的时间复杂度下来处理
 2. 首先其实我们可以吧这个加油的问题抽象成就是给你一个数组，让你求一个点开始加一圈，然后每一步都保证加的结果是一个正的值。
 3. 然后其是这个问题我们可以先把数据分成两部分，一部分是在start之前的，一部分是start之后的
 
 			1. 我们先来讨论后面的那一部分，首先我们维护一个变量x2来描述start后面的的数字之和，当在遍历到一个数字的时候发现x2变的小于零了，那说明之前他还是大于零的（，我们可以把之前的一堆之和大于零的数字看成一个，这点后面会利用到），但关于这一步我们我们已经不满足条件了，所以要换一个新的start，和x2来统计新的start后面的数字之和。
 			2. 接下来我们来一起考虑前面的那一部分，按照前面的思维我们可以把前面的数看成几个大块，每一个大块由一堆加起来是正数的数字还有一个负数组成，每一个大块的总合都是负数。
 			3. 所以对于到底是不是满足条件问题就很好判断了，最后到底是不是正数其实就是一个后面得到的正数来依次减前面的负数，假如减到最后还为负，则说明满足条件。
 4.  通过这样我们遇到x2变小于零就更新start来找到题目要求的解，
 5. 可能有的同学会问为什么一定只能是遇到x2变负的才更新，因为x2没变负之前前面的x2是一个正数组合其合肯定比你更新后的合要大，但题目中说了只有唯一组合，所以该情况我们不用考虑。
 

```python
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n=len(gas)
        x1=0
        x2=0
        start=0
        for i in range(n):
            x1+=gas[i]-cost[i]
            x2+=gas[i]-cost[i]
            if x2<0:
                x2=0
                start=i+1
        return start if x1>=0 else -1
```

 这前面的想通了之后其实temp就没必要单独遍历一边生成他了。
