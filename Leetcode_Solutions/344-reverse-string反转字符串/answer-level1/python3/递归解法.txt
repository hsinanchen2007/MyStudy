最近在刷题，有的题有思路，有的题想来想去也想不到。本来想练习一下动态规划，发现基础是递归，找了探索里的递归卡片来学习，第一个就是这个题，下面给一个递归写法。

每次基本操作就是交换一次对称位置的字符；递归结束条件是交换位置重叠或超过：i>=j

递归起始就是从0，len(s)-1的位置开始；因为需要原地交换，所以每次都要保证传入原List，同时还需要传入要交换的位置，主函数参数不够，所以需要另外定义函数来递归。主函数从起始位置开始调用递归函数。

暂时想到的递归写法就是这样，不知还有没有什么好的写法没有，后面想到或看到了，会再贴出来

```
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        self.reverseS(s, 0, len(s)-1)
    
    def reverseS(self, s, i, j):
        if i >= j:
            return
        self.reverseS(s, i+1, j-1) 
        self.swapChar(s, i, j) 
        
    def swapChar(self, s, i, j):
        tmp = s[i]
        s[i] = s[j]
        s[j] = tmp
```
