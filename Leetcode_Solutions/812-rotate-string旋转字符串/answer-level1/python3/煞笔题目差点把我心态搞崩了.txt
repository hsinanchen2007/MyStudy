### 解题思路
![QQ截图20200118214309.png](https://pic.leetcode-cn.com/3a217f84dbb0abed9d87efd6effc6e7aca064cdd8ed7b70e61dd7197e6c79e83-QQ%E6%88%AA%E5%9B%BE20200118214309.png)

思路就是在A中找B的首字符所在的几个索引，分别从这几个索引处截断A并将前半部分拼到后半部分尾巴上，看看有没有相等的，
就是判定循环退出的时候有点麻烦
### 代码

```python3
class Solution:
    def rotateString(self, A: str, B: str) -> bool:
        if  len(A)!=len(B):
            return False
        if A == "" and B=="":
            return True
        which_start=A.find(B[0])
        while which_start!=-1 :
            if A[which_start:]+A[:which_start]==B:
                return True
            which = A[which_start+1:].find(B[0])
            if which==-1:
                return False
            which_start=which+1+which_start
        return False



```