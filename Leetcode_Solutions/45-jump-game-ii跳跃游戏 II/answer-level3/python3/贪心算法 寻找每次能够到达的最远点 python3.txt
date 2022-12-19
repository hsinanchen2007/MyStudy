![屏幕截图(7).png](https://pic.leetcode-cn.com/3d516eb4c3b847170fb96b437af99cf584edbefc16643af075334aa545a92701-%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE\(7\).png)

available中存储着当前可以跳跃到的点，step用来计数（当前步数），在每次迭代时，把从当前所有点开始能跳到的最远的位置存储下来（即farthest）。
因为只要farthest可以到达，farthest之前的点都可以用不多于当前步数+1的步数到达，所以只需要保存之后能到达的最远点即可。

以[2,3,1,1,4]为例。最初我们从坐标为0的点开始，于是我们将available初始化为[0]，之后计算从0开始能跳跃的最远点。此时可以到达的点为1和2。我们把available赋值为[1,2]，进行下一次迭代。从[1,2]开始，我们在第二步分别最远可以到达索引为4和3的点，这时的最远点为4，我们把available赋值为[3,4]。这时不满足迭代条件了，意味着已经可以到达最后一个点，结束循环，输出step步数。
```
class Solution:
    def jump(self, nums: List[int]) -> int:
        size = len(nums)
        if size==1:
            return 0 
        available = [0]
        step = 0
        while size-1 not in available:
            start = available[-1]+1
            span = [i+nums[i] for i in available] #从当前每个点出发，最远能到达的位置
            farthest = max(span) #挑出最远能到达的点的索引
            available = list(range(start,farthest+1))
            step += 1
        return step
```
