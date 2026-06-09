### 解题思路
本题用的是【面试题 04.09. 二叉搜索树序列】里面一位叫做“随便发挥”的大佬分享的解题方法【15行代码】，当时我也是研究了好久才明白大佬思路的精髓。
整体思路用在这里就十分简单了，我也是为了测试一下自己当时对这个递归循环且交替循环数组的算法是否掌握了，才打算用这个办法解题的，放上来与大家分享，也望高手不吝赐教
*从前边开始我几乎每题提交后都会尽量写一些解答，但是中间还是断了好多题，那些题我也都有做，只是对于堆栈二叉树尤其是递归遍历这些操作我实在是太生疏了，几乎都是学一天第二天凭借理解自己临摹一份，没有太多发布的价值，希望以后能更加熟练吧。
感谢各位的解题分享，最近真的是学到了好多东西

### 代码

```python
class Solution(object):
    def permutation(self, S):
        """
        :type S: str
        :rtype: List[str]
        """
        Them_All = []
        def findThemAll(S,one_of_them):
            if len(S)==0:
                Them_All.append(one_of_them)
            l = len(S)
            for i in range(l):
                S_new = S[i+1:]+S[:i]
                findThemAll(S_new,one_of_them+S[i])
        findThemAll(S,"")
        return Them_All
                
```