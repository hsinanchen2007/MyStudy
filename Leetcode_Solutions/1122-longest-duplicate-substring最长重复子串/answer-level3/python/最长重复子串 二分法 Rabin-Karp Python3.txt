### 解题思路
执行用时 :1812 ms, 在所有 Python3 提交中击败了61.62%的用户
内存消耗 :24.5 MB, 在所有 Python3 提交中击败了40.00%的用户

思路：
1. 提供备选重复子串长度L：二分法
2. 验证字符串S中是否有长度为L的重复子串：Rabin-Karp编码
        直接比较两个过长的字符串计算开销太大，因此进行了编码
        每一个编码都从头计算计算开销同样太大，这里先计算了第一个子串的编码和aL，然后向后滑动得到后续的编码
Rabin-Karp 算法是基于这样的思路：即把字符串看作是字符集长度进制的数，由数值的比较结果得出字符串的比较结果
### 代码

```python3
class Solution:
    def is_duplicate(self, L, S, n, a=26, modules=2**32):
        # 如果L小于1，直接返回不存在
        # 否则会返回1（code_s的初始化值是0 L也是0 后续的编码就都是0了）
        # 虽然输出1并不影响最后的结果 S_org[1, 1] 但总觉得怪怪的
        if L < 1:
            return -1
        # 依次截取S中L个元素
        # 先计算第一个元素和aL
        code_s = 0
        for i in range(L):
            code_s = (code_s*a + S[i]) % modules
        set_s = {code_s}
        aL = a**L % modules
        # 由第一个元素和aL依次计算其他长为L的序列编码
        for start in range(1, n-L+1):
            code_s = (code_s*a - S[start-1]*aL + S[start+L-1]) % modules
            if code_s in set_s:
                return start
            set_s.add(code_s)
        return -1
    
    def longestDupSubstring(self, S_org: str) -> str:
        S = [ord(s) - ord('a') for s in S_org]
        n = len(S)
        # 注意：为了使单个元素的数组也能进入while循环，right初始为n，而不是n-1
        # 即left指向子串第一个坐标处，right指向子串最后一个坐标后一位
        # 子串长度为right-left，不用再+1
        left, right = 0, n  
        while right - left > 0:  # 长度>0的时候进入循环
            L = (right + left) // 2  # 计算L(序列长度为偶数时L指向中间连个数字的后一个)))
            # print('left L right:', left, L, right)
            # 判断S中有没有长度为L的重复子串
            # 如果有
            if self.is_duplicate(L, S, n) != -1:
                left = L + 1
            else:
                right = L
        # 计算最后的结果
        # 由达到要求时候的跳出时候的left和right计算L
        L = left - 1
        start = self.is_duplicate(L, S, n)
        return S_org[start: start+L] if start != -1 else ""
```