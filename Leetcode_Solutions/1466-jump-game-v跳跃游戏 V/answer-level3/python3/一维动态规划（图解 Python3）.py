### 解题思路
我们记录每个下标 `i` 可以最多访问的下标个数，返回最大值就行了。

如何记录每个下标的最多访问个数呢？我们使用一维动态规划数组 `dp` 。**dp[i] 表示下标 i 的最多可访问次数**，我们按照高度从低到高的顺序遍历每个下标，**在可跳范围内**，我们更新 `dp[i]` 的值。状态方程为 $dp[i] = max(dp[idx] + 1, cur)$ ,建议查看下方图片理解状态方程。

<![幻灯片1.JPG](https://pic.leetcode-cn.com/9ba4f6826ab79b14da8daa4a74260715c84767b44e78875952bc49313a48f7bd-%E5%B9%BB%E7%81%AF%E7%89%871.JPG),![幻灯片2.JPG](https://pic.leetcode-cn.com/7527e72793eaec122c05266c709aca313fe13eb301af330bb337f2e79f772472-%E5%B9%BB%E7%81%AF%E7%89%872.JPG),![幻灯片3.JPG](https://pic.leetcode-cn.com/33ca0a7a7a621989766be51c1ffb598e412736f5b294a759fa5ffc7bece32f31-%E5%B9%BB%E7%81%AF%E7%89%873.JPG),![幻灯片4.JPG](https://pic.leetcode-cn.com/a5d6a0dc23648ffee4054422a5f84673b5a5d9a32483eaeb05bb40cf478eb91d-%E5%B9%BB%E7%81%AF%E7%89%874.JPG),![幻灯片5.JPG](https://pic.leetcode-cn.com/b5386835471b32e1462af54d6259160ecbdfd3ffd338631f835dc1fa28059d71-%E5%B9%BB%E7%81%AF%E7%89%875.JPG),![幻灯片6.JPG](https://pic.leetcode-cn.com/10b63025e479fff2995ffe22eb132dcfcacda9c9a1c8d7fad23fe370ea33c4b5-%E5%B9%BB%E7%81%AF%E7%89%876.JPG),![幻灯片7.JPG](https://pic.leetcode-cn.com/0d5a0dc7e4fb2931a724be782a14202f19085257a2ce30a41b8269d3143f53ef-%E5%B9%BB%E7%81%AF%E7%89%877.JPG),![幻灯片8.JPG](https://pic.leetcode-cn.com/9ce671407bed6672c617d874673762d1ad357007a826750b3e479cece28c1260-%E5%B9%BB%E7%81%AF%E7%89%878.JPG),![幻灯片9.JPG](https://pic.leetcode-cn.com/e04528e008654e3f1fe0e4791b8fc1d74d72c6d7f5cbb7671c60db7bf897f3eb-%E5%B9%BB%E7%81%AF%E7%89%879.JPG),![幻灯片10.JPG](https://pic.leetcode-cn.com/fd4dc4b4838ca5b1065518e3d1575b2f89e806276ff680ff2a37e9e34f9e91e0-%E5%B9%BB%E7%81%AF%E7%89%8710.JPG),![幻灯片11.JPG](https://pic.leetcode-cn.com/3ebfe8fcca0f06502142215267c184bd4af2d584e4d299d994ac07285ee3ada1-%E5%B9%BB%E7%81%AF%E7%89%8711.JPG),![幻灯片12.JPG](https://pic.leetcode-cn.com/dff2b99b79d09598e459ef36be82022e0b1b75468dc5d350fc69909f1f2b5c3d-%E5%B9%BB%E7%81%AF%E7%89%8712.JPG),![幻灯片13.JPG](https://pic.leetcode-cn.com/b725a410e35525a5f4e50e0b38bef9420124ae93c3afbc83a26ecf19be9de34e-%E5%B9%BB%E7%81%AF%E7%89%8713.JPG),![幻灯片14.JPG](https://pic.leetcode-cn.com/01e761caa6beb9f1790b369f4f34d75886f5173ee72c6765fa31a1a49239908b-%E5%B9%BB%E7%81%AF%E7%89%8714.JPG),![幻灯片15.JPG](https://pic.leetcode-cn.com/4abbb89de9975d5738d861d23c8bf289e27b86183b12f248d7498bfe59aa8b58-%E5%B9%BB%E7%81%AF%E7%89%8715.JPG),![幻灯片16.JPG](https://pic.leetcode-cn.com/a75726f91f227fea5075d17b3f4e7624295e7fdc332d4a5a783120ba0923dfd1-%E5%B9%BB%E7%81%AF%E7%89%8716.JPG),![幻灯片17.JPG](https://pic.leetcode-cn.com/a5d90dfe18c205992a79b0e15d64aca9523926af805b873c00881a7f737157ec-%E5%B9%BB%E7%81%AF%E7%89%8717.JPG),![幻灯片18.JPG](https://pic.leetcode-cn.com/08c8682f9ed0710cad0768b1662f5ca9196c6bc8af38b977d2bef254f644e673-%E5%B9%BB%E7%81%AF%E7%89%8718.JPG),![幻灯片19.JPG](https://pic.leetcode-cn.com/388b7d23f66611fe64b28e5f2c1c285a1d636a956bd1306c9691ec3582709a18-%E5%B9%BB%E7%81%AF%E7%89%8719.JPG),![幻灯片20.JPG](https://pic.leetcode-cn.com/ad5ac2f053e55c3ad0df46a384e14effac07cf09b790961ce0b80a7f0697db35-%E5%B9%BB%E7%81%AF%E7%89%8720.JPG)>


### 代码

```python
class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        L = [(arr[i], i) for i in range(len(arr))]
        L = sorted(L, key=lambda x:x[0])
        n = len(arr)
        dp = [1] * n
        for h, i in L:
            cur = 1
            # 向左跳
            for idx in range(i - 1, max(0, i - d)-1, -1):
                if arr[idx] >= h:
                    break
                cur = max(dp[idx]+1,cur)
            # 向右跳
            for idx in range(i + 1, min(n, i + d + 1)):
                if arr[idx] >= h:
                    break
                cur = max(dp[idx] + 1, cur)
            dp[i] = cur
        return(max(dp))
```
### 复杂度分析
- 时间复杂度：$O(NlogN)$。我们遍历了一遍数组，复杂度为 $O(N)$，再最坏条件下，$d = N$，对于每个下标的时间复杂度为 $O(logN)$，因此时间复杂度为 $O(NlogN)$。
- 空间复杂度：$O(N)$。使用了 `L` 和 `dp`。

如有问题，欢迎讨论~