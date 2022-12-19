**思路：**

寻找数学规律。我们将树种每个结点的原索引标记在结点下方，如图所示。我们会发现一个规律，在偶数行，原索引和逆序后的索引值加在一起，等于该行最小索引和最大索引的值（因为每一行都是一个等差数列），而这个值也恰好等于该行最小索引值的3倍减去1（因为下一行开始的索引是前一行开始索引的2倍）。如果我们按照原索引进行遍历，`label = 14`，那么我们需要做的操作就是每次取`label //= 2`，最终得到`[1, 3, 7, 14]`这样一个图中蓝色标记的路径，但是由于`label = 14`处于偶数行，所以逆序之后的路径是镜像的，我们就需要将路径中奇数的位置反过来，得到`[1, 3, 4, 14]`，即图中红色的路径。如果`label = 5`处于奇数行，那么我们遍历后得到`[1, 2, 5]`，由于其中偶数行是逆序的，我们就需要将路径中的偶数位置反过来，得到`[1, 3, 5]`，即图中绿色的路径。

![sol.png](https://pic.leetcode-cn.com/90a8db9885f824601ecb86b93f2ea5eaac36c8a80a678b3d589ff23b3a742d2d-sol.png)

**代码：**

```python
class Solution:
    def pathInZigZagTree(self, label: int) -> List[int]:
        if label == 1:
            return [1]
        ans = []
        while label > 0:
            ans.append(label)
            label //= 2
        ans = ans[::-1]
        base = 2
        n = len(ans)
        flg = n % 2
        for i in range(1, n):
            if i % 2 == flg:
                s = base * 3 - 1
                ans[i] = s - ans[i]
            base *= 2
        return ans
```