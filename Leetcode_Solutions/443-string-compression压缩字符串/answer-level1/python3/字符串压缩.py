### 解题思路

* 这道题还蛮值得总结的，一是很体现数组思想，二是三指针容易考虑不周。
* python作为高层语言，不能体现指针、数组连续内存等等的实质。不过没关系，为了刷题方便，依旧用python写了这道题。
* 最初的思路是，建立3个指针,`start` `end` 和 `anchor`。前两者标识同一字符的起始和终止位置，后者是字符串的写入位置。然后分类讨论了一下，长度为1和长度大于2。
* 提交后报错多次，包括忘记在case1中修改chars、没有考虑到>9的情况等等。
* 看了官方题解后，发现算法可以继续简化。
    * 没必要新加`res`变量，因为`end`就足以表示了。
    * 外层循环移动`end`指针，而不是`start`指针。思路会绕弯，但是写起来简单。

### 代码

```python []
class Solution:
    def compress(self, chars: List[str]) -> int:
        res = 0
        start = 0
        anchor = 0
        while(start < len(chars)):
            end = start + 1
            # case 1: single character
            if end == len(chars) or chars[end] != chars[start]:
                chars[anchor] = chars[start]
                start += 1
                anchor += 1
                res += 1
                continue
            # case 2: frequency >= 2
            while(end < len(chars) and chars[start] == chars[end]):
                end += 1
            num = str(end - start)
            chars[anchor] = chars[start]
            for i in range(len(num)):
                chars[anchor+i+1] = num[i]
            start = end
            anchor += len(num) + 1
            res += len(num) + 1
        return res
```

```python []
class Solution:
    def compress(self, chars: List[str]) -> int:
        start, end, anchor = 0, 0, 0
        for end in range(len(chars)):
            if end == len(chars)-1 or chars[end] != chars[end+1]:
                chars[anchor] = chars[start]
                anchor += 1
                if end > start:
                    num = str(end-start+1)
                    for i in range(len(num)):
                        chars[anchor] = num[i]
                        anchor += 1
                start = end + 1
        return anchor
```
