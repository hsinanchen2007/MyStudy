![FireShot Capture 026 - 42. 接雨水 - 力扣（LeetCode） - leetcode-cn.com.png](https://pic.leetcode-cn.com/504c659851669954e5e6b5034be0a2fad9270e80f5009f2325d7f79a78df846f-FireShot%20Capture%20026%20-%2042.%20%E6%8E%A5%E9%9B%A8%E6%B0%B4%20-%20%E5%8A%9B%E6%89%A3%EF%BC%88LeetCode%EF%BC%89%20-%20leetcode-cn.com.png)


## 解题思路
    1.当n<3时，不可能出现闭合的区域 结果肯定为0
    2.首先要找到第一个出现的不为0的高度：
        若这个高度出现在倒数第二个或倒数第一个位置上或者根本就没有不为0的高度 说明没有闭合区域  结果也肯定为0
        设置当前可能接到水的候选高度candidate = 0
        设置cur_height_i = 第一个高度位置cur_start
        设置一个比cur_start位置的高度小的最大高度maxheight（后边就知道它的妙处了）
        从cur_height_i的下一个位置开始寻找（记为cur_i）：（寻找比cur_height_i位置的高度大的位置形成闭合区域）
            若当前高度小于cur_start位置的高度:（还未找到闭合的空间）
                更新candidate：candidate += height[cur_height_i] - height[cur_i]
                更新maxheight
            否则（即找到了闭合的区域）:
                将candidate与结果相加 更新结果
                重置candidate为0
                更新cur_height_i为当前的高度位置 继续寻找闭合空间
    
    3.喂！上面啰里啰嗦烦不烦人！（奈何笔者语文功底差！不说多点讲不清楚啊！）
      OK！接下来到重点了！：（递归回溯开始）
        把整个数组遍历完之后  有可能没有找到与cur_height_i位置相匹配的闭合空间 
        说明它太“高”了，没办法找到后边比他更高的元素产生闭合空间！
        也就是说 他高出的一部分是“无用的”！
        那就把无用的那部分给它“砍掉”：height[cur_height_i] = maxheight
        将砍完之后再将cur_height_i当做cur_start开始执行步骤2（即递归回溯的过程）




## 举例理解
![题目.png](https://pic.leetcode-cn.com/393391d86e9d50ab27756330dbff39215f3d30bd9cce632e52f25d60ec467f96-%E9%A2%98%E7%9B%AE.png)
就比如说所给示例的第8个位置后没办法找到比该位置更高位置形成闭合空间，那就把它“砍”成高度为2，与第9个位置就形成了闭合区域（虽然该闭合区域并没有接到水doge.png，但这保证了程序的完美执行）

 
## 代码
```
class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """


        def _trap(height, cur_start, res):
            if cur_start >= len(height)-1:
                return res

            candidate = 0
            cur_height_i = cur_start
            maxheight = 0
            for cur_i in range(cur_start+1, len(height)):
                if height[cur_i] < height[cur_height_i]:
                    candidate += height[cur_height_i] - height[cur_i]
                    if maxheight < height[cur_i]:
                        maxheight = height[cur_i]

                else:
                    res += candidate
                    candidate = 0
                    cur_height_i = cur_i

            height[cur_height_i] = maxheight
            return _trap(height, cur_height_i, res)

        n = len(height)
        if n < 3:
            return 0

        i = 0
        while i < n and height[i] == 0:
            i += 1

        if i == n-1 or i == n-2 or i == n :
            return 0

        res = _trap(height, i, 0)

        return res
```

PS:第一次写题解，啰里啰嗦希望大家能看的懂，望大家多多指正！
