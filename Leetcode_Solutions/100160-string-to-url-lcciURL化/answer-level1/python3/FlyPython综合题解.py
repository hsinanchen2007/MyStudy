公众号连载leetcode题解，欢迎关注。

![](https://pic.leetcode-cn.com/2a15d78b4b977527a4d95f2bb238db8c82b7d133878dbf168b4b972271818c58.jpg)


题目汇总： [leetcode](http://flypython.com/leetcode/) 


#### 思路

这个是一个字符串操作题，常见的做法是从字符串尾部开始编辑，从后往前反向操作。因为字符串尾部有额外的缓冲，可以直接修改，不必担心会覆写原有数据

这题可以先对空格进行计数，然后从应该的末尾开始挪字符到应该的位置，见到空格就替换，到头部字符为止。

不过这题用Python来做，可以不用这样。比如，可以转为list，遍历一次，直接替换。

```
class Solution:
    def replaceSpaces(self, S: str, length: int) -> str:
        l = list(S)
        for p in range(length):
            if l[p] == ' ': 
                l[p] = '%20'
        
        return ''.join(l[:length])
```

既然都转成了list，那split是否更好一点？

```
class Solution:
    def replaceSpaces(self, S: str, length: int) -> str:
        return "%20".join(S[:length].split(" "))
```

split都用了，那replace岂不是更好，非常清晰。

```
class Solution:
    def replaceSpaces(self, S: str, length: int) -> str:
        return S[0:length].replace(" ", "%20")

```


#### 方案代码

解法：

```
class Solution:
    def replaceSpaces(self, S: str, length: int) -> str:
        return S[0:length].replace(" ", "%20")

```

还有另外两种解法：

解法1：
```
class Solution:
    def replaceSpaces(self, S: str, length: int) -> str:
        return "%20".join(S[:length].split(" "))
```

解法2：
```
class Solution:
    def replaceSpaces(self, S: str, length: int) -> str:
        l = list(S)
        for p in range(length):
            if l[p] == ' ': 
                l[p] = '%20'
        
        return ''.join(l[:length])
```