画画图，发现想要交叉只有三种可能：

第一种 条件为 i>=3 || x[i] >= x[i-2] || x[i-1] <= x[i-3]

![335-1.png](https://pic.leetcode-cn.com/99158f6fde8322288ae00ff5a009d96a447aa2d392dbad8fe3a55c31c9b5e3a7-335-1.png)

第二种 条件为 i> 3 || x[i-1] == x[i-3] || x[i-4] + x[i] >= x[i-2]

![335-2.png](https://pic.leetcode-cn.com/7513c614129d61bd87c6bab56e19bf8719ff11bd6048ac961adb235abb4d67ff-335-2.png)

第三种 条件为 i> 4 ||  x[i-3]-x[i-5] <= x[i-1] <= x[i-3] || x[i-2]-x[i-4] <= x[i] <= x[i-2] || x[i-2] > x[i-4]

![335-3.png](https://pic.leetcode-cn.com/2e34542c09c093ecafbe3b7ebfa59950b207fa0fe165b20d5fbd92b282497360-335-3.png)

最后补充下细节，数组小于4个时定不可能相交，等于4时，只有第一种可能。

代码如下：
```
class Solution:
    def isSelfCrossing(self, x) -> bool:
        if len(x) <  4:return False
        if len(x) == 4:return True if x[3] >= x[1] and x[2] <= x[0] else False
        for i in range(3, len(x)):
            if x[i] >= x[i-2] and x[i-1] <= x[i-3]:
                return True
            if i > 3 and x[i-1] == x[i-3] and x[i-4] + x[i] >= x[i-2]:
                return True
            if i > 4 and x[i-3]-x[i-5] <= x[i-1] <= x[i-3] and x[i-2]-x[i-4] <= x[i] <= x[i-2] and x[i-2] > x[i-4]:
                return True
        return False
```
