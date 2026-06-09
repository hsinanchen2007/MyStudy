首先这道题目表述有歧义，表达的准确意思应该是:
判定数组中某个值第N次出现和第N+1次出现的间隔是否不大于k。
这样的题目首先想到的就是哈希表了：
### 哈希映射方法一：
先遍历全部数组，得到每个值的索引列表，然后每个列表求差分（后一个减前一个），判定差分是否不大于k。
```
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        visited = {}
        for i,v in enumerate(nums):
            try:visited[v].append(i)
            except:visited[v] = [i]
        def diff(x):
            a,b=x[:-1],x[1:]
            return sum([y-x<=k for x,y in zip(a,b)])
        rst = [diff(y) for y in visited.values() if len(y)>1]
        return sum(rst)
```
### 哈希映射方法二：
上述方法一的核心是求某个值第N次出现和第N+1次出现的距离。这样可以只记录当前出现的索引，下次出现时先比较，若<=k则返回。简化代码如下：
```
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        visited = {}
        for i,v in enumerate(nums):
            try:
                if i-visited[v]<=k:
                    return True                
            except:
                visited[v] = i
            else:
                visited[v] = i
        return False
        ## 执行用时 :116 ms, 在所有 python3 提交中击败了90.14%的用户
        ## 内存消耗 :21.6 MB, 在所有 python3 提交中击败了10.12%的用户
```
另外，换个思路，这题也可看成在一个长度k的窗口内是否有重复的值出现。于是就有了下面的方法：
### 滑动窗口方法一：
长度k的窗口划过数组，判断窗口内数据是否唯一：
```
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        if len(nums[:k+1])>len(set(nums[:k+1])):
            return True
        for i in range(k,len(nums)):
            a=nums[i-k:i+1]
            if len(set(a))<len(a):
                return True
        return False
```
遗憾的是由于切片效率太低，直接超时报错了。
### 滑动窗口方法二：
这是精选题解里的方法，思路巧妙：
维护一个哈希集合，里面始终最多包含 k 个元素，当出现重复值时则说明在 k 距离内存在重复元素
每次遍历一个元素则将其加入哈希表中，如果哈希表的大小大于 k，则移除最前面的数字
复杂度与哈希映射方法二相同。
```
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        windows = set()
        for i in range(len(nums)):
            if nums[i] in windows:
                return True
            windows.add(nums[i])
            if len(windows) > k:
                windows.remove(nums[i-k])
        return False
```