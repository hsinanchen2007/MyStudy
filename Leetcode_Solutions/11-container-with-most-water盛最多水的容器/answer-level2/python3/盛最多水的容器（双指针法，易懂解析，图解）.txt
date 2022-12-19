#### 思路：

- **算法流程：** 设置双指针 $i$,$j$ 分别位于容器壁两端，根据规则移动指针（后续说明），并且更新面积最大值 `res`，直到 `i == j` 时返回 `res`。

- **指针移动规则与证明：** 每次选定围成水槽两板高度 $h[i]$,$h[j]$ 中的短板，向中间收窄 $1$ 格。以下证明：
    - 设每一状态下水槽面积为 $S(i, j)$,$(0 <= i < j < n)$，由于水槽的实际高度由两板中的短板决定，则可得面积公式 $S(i, j) = min(h[i], h[j]) × (j - i)$。
    - 在每一个状态下，无论长板或短板收窄 $1$ 格，都会导致水槽 **底边宽度** $-1$：
        - 若向内移动短板，水槽的短板 $min(h[i], h[j])$ 可能变大，因此水槽面积 $S(i, j)$ 可能增大。
        - 若向内移动长板，水槽的短板 $min(h[i], h[j])$ 不变或变小，下个水槽的面积一定小于当前水槽面积。
    - 因此，向内收窄短板可以获取面积最大值。换个角度理解： 
        - 若不指定移动规则，所有移动出现的 $S(i, j)$ 的状态数为 $C(n, 2)$，即暴力枚举出所有状态。
        - 在状态 $S(i, j)$ 下向内移动短板至 $S(i + 1, j)$（假设 $h[i] < h[j]$ ），则相当于消去了 ${S(i, j - 1), S(i, j - 2), ... , S(i, i + 1)}$ 状态集合。而所有消去状态的面积一定 $<= S(i, j)$：
            - 短板高度：相比 $S(i, j)$ 相同或更短（$<= h[i]$）；
            - 底边宽度：相比 $S(i, j)$ 更短。
        - 因此**所有消去的状态的面积都** $< S(i, j)$。通俗的讲，我们每次向内移动短板，所有的消去状态都**不会导致丢失面积最大值** 。

- **复杂度分析**：
    - 时间复杂度 $O(N)$，双指针遍历一次底边宽度 $N$ 。
    - 空间复杂度 $O(1)$，指针使用常数额外空间。


<![Picture1.png](https://pic.leetcode-cn.com/a2a97349454ee3657a8a3d9db0399921894c7f581c2e9540d0e2c3df122fec95-Picture1.png),![Picture2.png](https://pic.leetcode-cn.com/239c53727f392398829ae835df2d4b8dce374954b2aac2e3745b3ff9c32d7a9f-Picture2.png),![Picture3.png](https://pic.leetcode-cn.com/45e1d202910029048aea0e36b826a469b9a03ebbbaae966f27245ac737aea300-Picture3.png),![Picture4.png](https://pic.leetcode-cn.com/bac587e94230e323ac6b50defb95f0bd0a6693d2a931e244c4770f055276bb3f-Picture4.png),![Picture5.png](https://pic.leetcode-cn.com/2859207a970b8947651042ecbe92f2b7ebf8665853dd300433fdd8b87a0bd275-Picture5.png),![Picture6.png](https://pic.leetcode-cn.com/705f584789af7dba85e058b8c7a6dadc652fa591b535c5699f825d745fb2412c-Picture6.png),![Picture7.png](https://pic.leetcode-cn.com/a6aea4baaaaf83691a260478af307668c26333e14656c3c1bbc0fe06f903d666-Picture7.png),![Picture8.png](https://pic.leetcode-cn.com/ef68ae29ae929b637c71e2108428a5010bc5e40acef7b0bd16d44f3a037b0bed-Picture8.png)>



#### 代码：

```Python []
class Solution:
    def maxArea(self, height: List[int]) -> int:
        i, j, res = 0, len(height) - 1, 0
        while i < j:
            if height[i] < height[j]:
                res = max(res, height[i] * (j - i))
                i += 1
            else:
                res = max(res, height[j] * (j - i))
                j -= 1
        return res
```
```Java []
class Solution {
    public int maxArea(int[] height) {
        int i = 0, j = height.length - 1, res = 0;
        while(i < j){
            res = height[i] < height[j] ? 
                Math.max(res, (j - i) * height[i++]): 
                Math.max(res, (j - i) * height[j--]); 
        }
        return res;
    }
}
```