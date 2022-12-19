在阅读许多优秀题解后，总算是大概了解了单调栈在这道题中的应用。
参考题解：
https://leetcode-cn.com/problems/longest-well-performing-interval/solution/qian-zhui-he-dan-diao-zhan-python3-by-smoon1989/ 
https://leetcode-cn.com/problems/longest-well-performing-interval/solution/zhi-ji-guan-jian-dian-by-luo-hai-xian/236081/
https://leetcode-cn.com/problems/maximum-width-ramp/solution/dan-diao-di-jian-zhan-on-by-huangyt/

### 原数组转换

我们以题目所给样例 [9,9,6,0,6,6,9] 做例子，先转换为数组 arr: [1,1,-1,-1,-1,-1,1]

### 构建前缀和

然后构成前缀和数组 preSums, 注意这里的前缀和数组长度会比原数组多1，也就是 preSums[i] 表示的是 从数组头到包含i-1在内的所有元素加和。

这种前缀和表示在计算给定下标 i,j 计算 i,j 之间元素加和时候比较方便。preSums[i] - preSums[j] 就表示 [i, j) 之间的元素加和。注意 [i,j) 是左闭右开区间。举例 preSums[4] - preSums[2] 就是 arr[2] + arr[3]

依据上述 arr 可以得到前缀和数组是 preSums: [0,1,2,1,0,-1,-2,-1]，现在我们要求的就是，对于该数组中的每个元素 x，找到 **左侧比 x 小的，并且离 x 最远的位置，也就是从左到右第一个比自己小的位置**。
对于坐标 3 处的 1，符合条件的就是坐标 0

### 使用单调栈

对于上述诉求，我们采用单调栈解决，对于 preSums 的元素内容，从左到右遍历，产生单调递减索引栈，注意放入栈中的是索引，这样比较方便之后的判断。
得到栈为 [0,5,6] 对应在 preSums 中的内容是 [0,-1,-2]

接着**从右向左**遍历 preSums中的元素，如果遍历到的元素大于栈顶元素，那么利用下标更新最大宽度，同时弹栈。（可以弹栈的原因在于，我们从右向左遍历preSums，如果已经遍历到一个元素大于栈顶，那么这就是当前栈顶元素能够发挥得到的最大宽度，随着 preSums 继续遍历，即使有数字大于该栈顶，宽度也不会更大）

#### 几个问题
##### 为什么采用单调递减栈：

如果我们构造了一个单调递增栈，随意举例是 [3,5,6], 对于给定的一个元素 10，10 大于栈顶元素 6，得到了一个宽度，假设两者之间举例是 100，因为这是一个单调递增栈，那么 10 肯定还大于6 前面的 5，并且 10 和 5 之间的距离肯定大于当前得到的 100，失去意义。

而如果维护一个单调递减栈，假设是 [9,8,6]， 10 比6大并且得到距离是 100 后，栈中在 6之前的数字是大于6的，10还期望能够比这些大于 6的数字要大，从而让宽度得到增大。（宽度能够增大的原因很显然，9和8是先于6加入栈的，而此时遍历是从右往左，10与9和8的距离一定是大于100的）

##### 对于给定例子，当栈中元素还剩 [0, 5] 对应内容 [0, -1],　preSums [0,1,2,1,0,-1,-2,-1] 遍历到  下标 4, 元素 0，此时 0 大于栈顶 -1，但是其实 下标 4 已经小于 5了，这是否合理呢？

是合理的，下标 4 小于 5，所以产生的宽度是 4-5 <0，是不会更新宽度的，并且会弹栈将 -1 弹出，让 4处元素继续比较


```
class Solution:
    def longestWPI(self, hours: List[int]) -> int:
        if not hours:
            return 0        
        arr = [1 if x > 8 else -1 for x in hours]        
        size = len(arr)
        preSums = [0] * (size + 1)
        for i in range(1, size + 1):
            preSums[i] = preSums[i-1] + arr[i-1]

        descStack = []
        for i in range(size+1):
            if not descStack or preSums[i] < preSums[descStack[-1]]:
                descStack.append(i)                        
        
        maxLen = 1 if 1 in arr else 0
        for i in range(size, -1, -1):
            while descStack and preSums[i] > preSums[descStack[-1]]:
                maxLen = max(maxLen, i - descStack[-1])
                descStack.pop()
        return maxLen
```

