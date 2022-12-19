### 1. 暴力法（回溯）

从`1`到`target//2`顺序遍历，向上累加：
1. 如果累加结果等于`target`，就存下结果
2. 如果累加额结果大于`target`，就继续遍历
3. 如果累加结果小于`target`，就继续累加

### 代码
```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        def backtrack(l, temp, Lis):
            if temp > target:
                return
            if temp == target and len(Lis) >= 2:
                res.append(Lis)
                return
            else:
                backtrack(l+1, temp+l+1, Lis+[l+1])
    
        res = []
        for i in range(1, target//2+1):
            backtrack(i, i, [i])
        return res
```
### 1. 双指针

设和为`s`的连续正数序列第一个元素为`start`，最后一个元素为`end`，`start`和`end`分别初始化为`1`和`2`：
那么从`start`到`end`的连续整数累加和的计算方式符合等差数列的前`N`项和，为`temp = (end-start+1)*(start+end)/2`
两个必要条件：
1. 如果`start`大于`target//2`，就没有必要继续遍历了，因为累加和一定会大于`target`
2. 另外一个限制条件是`start`必须要小于`end`

将上述两个条件作为循环的跳出条件：
- 如果累加和小于`target`，`end += 1`；
- 如果累加和等于`target`，存下结果，`end += 1`；
- 如果累加和大于`target`，`start += 1`；

### 代码
```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        start, end = 1, 2 
        temp = 0
        res = []
        while start <= target//2 and start < end:
            temp = (end-start+1)*(start+end)/2
            if temp < target:
                end += 1
            elif temp == target:
                res.append([i for i in range(start, end+1)])
                end += 1
            else:
                start += 1
        return res
```