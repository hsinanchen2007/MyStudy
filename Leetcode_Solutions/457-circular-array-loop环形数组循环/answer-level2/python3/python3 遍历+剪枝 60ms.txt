### 解题思路
建立一个失败者合集，存储在以前的探索中没能成功的节点，在接下来的探索中，如果指向了失败的节点，那么肯定不会成功
时间复杂度o(n),每个点只遍历一次

### 代码

```python3
class Solution:
    def circularArrayLoop(self, nums: List[int]) -> bool:
        #遍历寻找满足条件的循环
        if nums == []:
            return False
        number_used = set() #这是失败者集合，经过这些节点都失败了
        for i in range(len(nums)):
            if i in number_used:
                #如果它在已经查看过的节点，那肯定不行
                continue
            step = nums[i]
            current_positon = i
            temp = set() #temp用于检查这个点出发经过的点
            while True:
                temp.add(current_positon)
                next_position = (current_positon+nums[current_positon]) % len(nums)
                if next_position in number_used:
                    break #如果这个点在失败者合集里，那就不行
                if next_position == current_positon:
                    break #如果是自我循环，显然不行
                if nums[next_position] * step < 0:
                    break #方向相反，也不行
                if next_position in temp:
                    #回到原点了，可行
                    return True
                current_positon = next_position
            #如果上述迭代没有返回True，那么这个temp失败了
            number_used |= temp #把它放到失败者合集里面
        return False
        
```