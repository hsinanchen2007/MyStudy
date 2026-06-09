题目中给定了保证可以转化为原始的数字，即数字转化为英文后的各个字母的数量一定严格等于给定字符串各个字母的数量。

可以转化为一组线性方程组，形式如下（图来自wiki）

![image.png](https://pic.leetcode-cn.com/dcd3393891e8883b50f1b7c91952839c37efdf7312e72c6886530e4ea1d49165-image.png)

其中等号左边 a11 表示第一个单词(zero)字母 a 出现的次数，a21 表示字母b出现的次数，依次类推；a12 则是表示第二个单词 one 字母 a 出现的次数，依次类推。x1-xn 表示 0-9 每个单词出现了多少次。等式右边b1-bn 表示给定的字符串中各个字母出现的次数。

上式通过线性代数转化为矩阵等式 $AX = B$，用第三方库就可以求解了。

PS:只是提供一种思路，运行速度由于需要求解矩阵等式比较慢。


```python
import numpy as np

class Solution:
    def originalDigits(self, s: str) -> str:
        mapping = {0: "zero", 1: "one", 2: "two", 3: "three", 4: "four", 
                   5: "five", 6: "six", 7: "seven", 8: "eight", 9: "nine"}
        
        def count(string):
            arr = [0 for _ in range(26)]
            for c in string:
                arr[ord(c) - 97] += 1
            return arr
        
        B = np.array(count(s)).reshape(-1, 1)
        A = np.array([count(mapping[i]) for i in range(10)]).T
        res = ""
        for i, cnt in enumerate(np.linalg.lstsq(A, B)[0]):
            res += str(i) * int(round(cnt[0]))
        return res
```
