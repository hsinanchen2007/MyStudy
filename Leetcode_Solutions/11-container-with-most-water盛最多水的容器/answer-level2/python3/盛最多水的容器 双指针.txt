* [42. 接雨水](https://leetcode-cn.com/problems/trapping-rain-water/solution/jie-yu-shui-de-tu-xing-xue-da-ju-guan-by-coldme-2/)与这道题看着相似，实则不同。
    * 前者柱子宽度为1，代表高高低低的地面；后者柱子等效无宽度，是容器的内壁。
    * 但是最终两道题都能用**双指针**来解决。初始两个指针指向两头，然后向内靠近。
* 具体的算法和证明可参照的[Krahets](https://leetcode-cn.com/problems/container-with-most-water/solution/container-with-most-water-shuang-zhi-zhen-fa-yi-do/)的题解，**消去**的思路很便于理解。
* 给个例子：设数组为[2,1,3,2,1,8]，最初`left`指向`2`，`right`指向`8`，因为`2 < 8`，所以下一步`left`右移，指向`1`。而我一开始的想法是去找`left`右面比`left`大的值，即让`left`右移两位，指向`3`，毕竟指向`1`是没有意义的。我的想法是合理的，但是写起来相当繁琐。有时候，人还是要做些徒劳无功的事情啊。
* 时间复杂度 O(N); 空间复杂度 O(1)。

```python []
class Solution:
    def maxArea(self, height: List[int]) -> int:
        left, right = 0, len(height)-1
        res = 0
        while(left < right):
            if height[left] < height[right]:
                res = max(res, height[left]*(right-left))
                left += 1
            else:
                res = max(res, height[right]*(right-left))
                right -= 1
        return res
```