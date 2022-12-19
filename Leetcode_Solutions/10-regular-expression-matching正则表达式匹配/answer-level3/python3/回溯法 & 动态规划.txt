
**测试用例：**

* 功能测试：
	* s = "aab" p = "c\*a\*b"
	* s = "aab" p = "c\*.\*b"
* 边界测试：
	* s = "" p = ".\*"
	* s = "a" p = ".\*"
* 负面测试：

## 方法一：回溯法

当比较到s的第i个位置和p的第j个位置时：

* IF s到尾 AND p到尾：匹配成功，True
* IF s没到尾 AND p到尾：匹配不成功，退出
* （剩下的情况保证了p一定没有到尾部）
* IF p的下一位是*：
	* IF s没到尾 AND s和p当前字符能够匹配：
		* 跳过 -> i, j+2
		* 匹配一次 -> i+1, j+2
		* 匹配多次->  i+1, j
	* ELSE（s到尾 OR s和p当前字符不能匹配）：
		* 跳过 -> i, j+2
* ELIF s没到尾 AND s和p当前字符不能匹配：
	* 下一字符 -> i+1, j+1


```python
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        global ismatch
        ismatch = False

        def backward(i, j):
            global ismatch
            if i >= len(s) and j >= len(p):
                ismatch = True
            if i < len(s) and j >= len(p):
                return
            if j < len(p) - 1 and p[j+1] == '*' : # p下一位是*
                if i < len(s) and (s[i] == p[j] or p[j] == '.'): # 匹配
                    backward(i, j+2) # 跳过
                    backward(i+1, j+2) # 1次
                    backward(i+1, j) # 多次
                else:
                    backward(i, j+2) # 跳过
            elif i < len(s) and (s[i] == p[j] or p[j] == '.'):
                backward(i+1, j+1)

        backward(0, 0)
        return ismatch
```

**复杂度分析：**

* 时间复杂度：太复杂了！
* 空间复杂度：O(1)

## 方法二：动态规划

状态：f(i, j) 表示s\[:i+1\]与p\[:j+1\]的匹配情况

状态转移矩阵生成过程：

* 初始化一个状态转移矩阵，大小为两个字符串维度相乘，分别多留一行一列
* f(0, 0) = True（空字符串之间匹配）
* 第一行：
	* IF p的第j个字符不是\*：
		* f(0, j) = False（空字符串与任何字符不匹配）
	* ELSE: 
		* f(0, j) = f(0, j-2)（前一字符出现0次是否匹配）
* 第一列：
	* f(i, 0) = False
* 其他元素：
	* IF p的第j个元素不是\*：
		* f(i, j) = True：s的第i个元素和p的第j个元素匹配，且f(i-1, j-1)=True（前一个元素也匹配）
	* ELSE：
		* f(i, j) = True：
			* 情况1：\*前的字符出现0次，观察f(i, j-2)
			* 情况2：\*前的字符出现1次，观察f(i, j-1)
			* 情况3：\*前的字符出现多次，观察s的第i个元素与p的第j-1个元素的匹配情况与f(i-1, j)
			* 如果上述三个观察有一个满足为True

![IMG_A96D70F16AD3-1.jpeg](https://pic.leetcode-cn.com/2c747511cb61934bf9dbe19aff31dfd41de4d042563af6d631e0c1492b3dc49b-IMG_A96D70F16AD3-1.jpeg)

```python
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        n1, n2 = len(s), len(p)
        dp = [[False for j in range(n2+1)] for i in range(n1+1)]
        dp[0][0] = True
        for j in range(1, n2+1):
            if p[j-1] != '*':
                dp[0][j] == False
            else:
                dp[0][j] = dp[0][j-2]
        for i in range(1, n1+1):
            for j in range(1, n2+1):
                if p[j-1] != '*':
                    if (s[i-1] == p[j-1] or p[j-1] == '.') and dp[i-1][j-1]:
                        dp[i][j] = True
                else:
                    dp[i][j] = dp[i][j-2] or dp[i][j-1] or ((s[i-1] == p[j-2] or p[j-2] == '.') and dp[i-1][j])
        return dp[-1][-1]
```

**复杂度分析：**

* 时间复杂度：O(m * n)
* 空间复杂度：O(m * n)