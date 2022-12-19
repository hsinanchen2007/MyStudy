公众号连载leetcode题解，欢迎关注。

![](https://pic.leetcode-cn.com/2a15d78b4b977527a4d95f2bb238db8c82b7d133878dbf168b4b972271818c58.jpg)


题目汇总： [leetcode](http://flypython.com/leetcode/) 


#### 思路
开始，我们还是先理解题意，确定是否区分大小写，是否忽略空白字符等。有了01.01题的hash计数0，1判断的经历，在这里很容易想到使用hash计数。

因为字符可以重复，需要对字符进行计数，这个时候我们会想到collections库中的Counter。于是有了下面两行代码解决了问题。

```
from collections import Counter
return Counter(s1) == Counter(s2)    
```

但是上面的方法严格来说算作弊，那我们手写吧。对每个字符进行计数操作并测试是否相等，不相等返回False，全部相等返回True。

```
class Solution:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False
 
        base = set(s1+s2)
        for b in base:
            if s1.count(b) != s2.count(b):
                return False
        return True
```

上面的代码，最容易出问题的是`base = set(s1+s2)`,需要以两个字符串集的唯一字符来进行计数，但这里引入了set。

我们测试了字符范围，发现是'a'到'z'，那么代码可以改成：

```
class Solution:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False
            
        base = [chr(i) for i in range(ord("a"),ord("z")+1)]
        for b in base:
            if s1.count(b) != s2.count(b):
                return False
        return True

```

再进一步，为了直观，我们可以引入string包，代码如下：

```
class Solution:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        import string 
        if len(s1) != len(s2):
            return False
        
        for b in string.ascii_lowercase:
            if s1.count(b) != s2.count(b):
                return False
        return True

```

当然，在这里我们也可以通过排序并比较来解决，代码非常简单:

```
class Solution:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        return sorted(s1) == sorted(s2)
```

空间复杂度O(nlogn)，相比hash计数复杂度要高一些，但是hash计数有空间复杂度。


#### 错误代码分析

在题解中看到一份代码

```
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        if(s1.length() != s2.length()) {
            return false;
        }
        int s1Sum = 0, s2Sum = 0;
        for(int i = 0; i < s1.length(); i++) {
            s1Sum += s1.charAt(i);
            s2Sum += s2.charAt(i);
        }
        return s1Sum == s2Sum;
    }
}

```
此解法主要是计算s1，s2字符和，比较字符和。这种解法的问题就是忽略了和相同，但数字并不同的情况，比如 3+7 == 2+8。

除了计算s1，s2的字符和外，计算相对位移和，加s1字符减s2字符等方法都有此问题。


#### 方案代码
  
解法:

```
class Solution:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False
            
        base = set(s1+s2)
        for b in base:
            if s1.count(b) != s2.count(b):
                return False
        return True

```

另外含高级数据结构的三种解法

解法1:

```
class Solution:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        from collections import Counter
        return Counter(s1) == Counter(s2)
        
```

解法2:

```
class Solution:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        return sorted(s1) == sorted(s2)
```

解法3:
```
class Solution:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        import string
        if len(s1) != len(s2):
            return False
            
        for b in string.ascii_lowercase:
            if s1.count(b) != s2.count(b):
                return False
        return True
```
        