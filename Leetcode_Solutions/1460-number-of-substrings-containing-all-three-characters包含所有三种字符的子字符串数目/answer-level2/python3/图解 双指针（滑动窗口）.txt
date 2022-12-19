### 解题思路
我们使用首尾指针维护一个滑动窗口。
- 如果窗口内没有 $a$，$b$，$c$，尾指针右移来寻找字符直到窗口内包含 $a$，$b$，$c$；
- 如果窗口内包含 $a$，$b$，$c$，当窗口继续向右拉开时肯定仍然包含 $a$，$b$，$c$，所以直接加上窗口右侧到末尾的距离；
- 然后左侧指针右移，每移动一步进行以上两种情况的判读即可。
#### 算法
- 初始化 `head = 0`，`tail = 2`，$n$ 为字符串长度；
- 当 `head < n - 2`时：
    - 如果窗口里包含 $a$，$b$，$c$，结果加上 `n - tail`，且 `head` 指针右移；
    - 如果窗口里没有 $a$，$b$，$c$，`tail` 右移直到末尾；




<![幻灯片1.JPG](https://pic.leetcode-cn.com/9b4f26b1f66d5f37c470eb692989bd3b0f6a34a3f28ab50e4d943dfe857226d7-%E5%B9%BB%E7%81%AF%E7%89%871.JPG),![幻灯片2.JPG](https://pic.leetcode-cn.com/42425e9e86adee0b67377c55460853fafb636edef3e327ad0595bedfa4396873-%E5%B9%BB%E7%81%AF%E7%89%872.JPG),![幻灯片3.JPG](https://pic.leetcode-cn.com/2335855b18d69a93121d5483085567a79bd07f9b9b2059bd1d9a1e97eb08a01a-%E5%B9%BB%E7%81%AF%E7%89%873.JPG),![幻灯片4.JPG](https://pic.leetcode-cn.com/90ba5b0274be5d19e3a1b799ece3acedf8fe25e137084ba8cfd43086e02014ea-%E5%B9%BB%E7%81%AF%E7%89%874.JPG),![幻灯片5.JPG](https://pic.leetcode-cn.com/9413b821f831647ee3fb8b2b1d18810f8c7d55d0ab6dd73a8a6d5f0e04dac7be-%E5%B9%BB%E7%81%AF%E7%89%875.JPG),![幻灯片6.JPG](https://pic.leetcode-cn.com/3897856415446536cdfd27326716821a3077a45a4e6b4942b721e7ec791b30ab-%E5%B9%BB%E7%81%AF%E7%89%876.JPG),![幻灯片7.JPG](https://pic.leetcode-cn.com/d31eebc60a5d271a77fc45c79e1b7cba350cb6c613b57d3cb250cddb06d7ffaf-%E5%B9%BB%E7%81%AF%E7%89%877.JPG),![幻灯片8.JPG](https://pic.leetcode-cn.com/bf5bf8214c68981f62c7a3a8d57cde02b57d9674ec35961a69f35bb818807150-%E5%B9%BB%E7%81%AF%E7%89%878.JPG)>

#### 代码
```python []
class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        if len(s) < 3: return 0

        head, tail = 0, 2
        n = len(s)
        ans = 0
        while head < n - 2:
            tmp = s[head: tail + 1]
            if 'a' in tmp and 'b' in tmp and 'c' in tmp:
                ans += n - tail
                head += 1
            else:
                tail += 1
                if tail == n: break
        return ans
```
#### 复杂度分析
- 时间复杂度：${\mathcal{O}}(N)$，首尾指针各遍历一遍字符，需要 ${\mathcal{O}}(2N)$。
- 空间复杂度：${\mathcal{O}}(N)$，使用了 `tmp`。

欢迎提供c++代码
如有问题，欢迎讨论~