### 解题思路
1.
暴力法[O(a*b*c*d)]
2.
优化暴力法+哈希表(collections.defaultdict)[O(4(a+b+c+d)+e*f*g*h)]
3.
子问题+哈希表(collections.defaultdict)[O(a*b+c*d)]
4.
子问题+哈希表+单纯计数(collections.Counter)[O(a*b+c*d)]

### 代码

```python3
class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        h = collections.Counter(-a - b for a in A for b in B)
        return sum(h[c + d] for c in C for d in D)

'''
作者：tuotuoli
链接：https://leetcode-cn.com/problems/4sum-ii/solution/454-si-shu-xiang-jia-ii-cong-ji-chu-xie-fa-you-hua/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
'''
```