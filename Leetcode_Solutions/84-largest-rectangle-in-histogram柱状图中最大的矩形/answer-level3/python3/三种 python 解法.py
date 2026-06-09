### 第一种解法来自于 
https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/zhao-liang-bian-di-yi-ge-xiao-yu-ta-de-zhi-by-powc/ 的思路，也是比较浅显易懂的思路，遍历给定的 arr，对于每个 idx，分别找到 左边第一个 高度低于 arr[idx] 的 下标 ，以及 右边第一个 高度低于 arr[idx] 的 下标，当前 idx 对应的最大 area 就求出来了，在分别向左向右求的时候，维护两个 list 用来加快查找
```
def largestRectangleArea(self, heights: List[int]) -> int:
    if not heights:
        return 0
    size = len(heights)
    left_i = [-1] + [0 for i in range(size -1)] 
    right_i = [0 for i in range(size -1)] + [size] 
    for i in range(1, size):
        firstLeftSmallerThanIIdx = i - 1
        while firstLeftSmallerThanIIdx != -1 and heights[firstLeftSmallerThanIIdx] >= heights[i]:
            firstLeftSmallerThanIIdx = left_i[firstLeftSmallerThanIIdx]
        left_i[i] = firstLeftSmallerThanIIdx
    
    for i in range(size-2, -1, -1):
        firstRightSmallerThanIIdx = i + 1
        while firstRightSmallerThanIIdx != size and heights[firstRightSmallerThanIIdx] >= heights[i]:
            firstRightSmallerThanIIdx = right_i[firstRightSmallerThanIIdx]
        right_i[i] = firstRightSmallerThanIIdx

    maxArea = 0

    for i in range(size):
        maxArea = max(maxArea, (right_i[i] - left_i[i] - 1)*heights[i])

    return maxArea

```

### 第二种解法
维护一个单调栈，栈中存储 (最左可以延伸到的下标，当前下标)

```
def largestRectangleArea(self, heights: List[int]) -> int:
    if not heights:
        return 0
    # stack 中存储 (最左可以抵达的 idx，当前 idx)
    stack = [(0,0)]
    size = len(heights)
    maxArea = 0
    for i in range(1, size):                   
        if  not stack or heights[i] >= heights[stack[-1][1]]:
            stack.append((i,i))
        else:
            leftIdx = stack[-1][0]
            while stack and heights[i] < heights[stack[-1][1]]:
                peekPair = stack.pop()
                # 这里一定要注意 leftIdx 是stack pop 后左边的那个 idx
                leftIdx = peekPair[0]
                maxArea = max(maxArea, (i - leftIdx) * heights[peekPair[1]])
            stack.append((leftIdx, i))
    
    # 栈中剩下元素表示这些 idx 对应的 height 可以构建矩形到最末尾
    while stack:
        peekPair = stack.pop()            
        maxArea = max(maxArea, (size - peekPair[0]) * heights[peekPair[1]])                     
    return maxArea
```

### 第三种解法就是网上最多的方法啦
```
def largestRectangleArea(self, heights: List[int]) -> int:    
    if not heights:
        return 0
    stack = [-1]
    size = len(heights)
    maxArea = 0
    for i in range(0, size):                   
        if stack[-1] == -1 or heights[i] >= heights[stack[-1]]:
            stack.append(i)
        else:
            while stack[-1] != -1 and heights[i] < heights[stack[-1]]:
                peekIdx = stack.pop()
                # 这里一定要注意 leftIdx 是stack pop 后左边的那个 idx
                leftIdx = stack[-1]
                maxArea = max(maxArea, (i - leftIdx -1) * heights[peekIdx])
            stack.append(i)
    
    # 栈中剩下元素表示这些 idx 对应的 height 可以构建矩形到最末尾
    while stack[-1] != -1:
        peekIdx = stack.pop()
        leftIdx = stack[-1]
        maxArea = max(maxArea, (size - leftIdx -1) * heights[peekIdx])                     
    return maxArea
```
