### 解题思路
首先参考的是这位大哥的视频：https://www.youtube.com/watch?v=DqhPJ8MzDKM
1.先初始化二维数组或哈希表的第一排第一列，除了两个空字符串的[0,0]之外都是False
2.一列一列填表
3.s[i]==p[j] or p[j]=='.':值为左上角的值
4.p[j]=='*'：
    如果p上一个值为s现在的值或则为'.':值为往上两排的值 or 左边一列的值
    如果p上一个值不等于s现在的值:值为往上两排的值
5.p[j]!=s[i]:False
6.表右下角为答案
某个例子的图：
![image.png](https://pic.leetcode-cn.com/d2df6e092227d7b00c401ab4309f543dc1edb5bbb0ed35817c4d8a39ea3c4cae-image.png)

星号老是显示不出来，放图了：
![image.png](https://pic.leetcode-cn.com/11364a1e8fb04b599e17c44efd20deba2b9de9e2789d790279bbeaf52fb0383a-image.png)


4的第一种情况不太好理解，要多康康
![image.png](https://pic.leetcode-cn.com/ded0794239d3170f5c0b4b297ab5f29f5e7315b103c1a3dbab442a75b3403025-image.png)

### 代码

```python
class Solution(object):
    def isMatch(self, s, p):
        count={}
        count[(0,0)]=True
        for i in range(len(p)):
            if p[i]=='*':
                count[(i+1,0)]=count[(i-1,0)]
            else:count[(i+1,0)]=False
        for i in range(len(s)):
            count[(0,i+1)]=False
        for i in range(len(s)):
            for j in range(len(p)):
                if s[i]==p[j] or p[j]=='.': count[(j+1,i+1)]=count[(j,i)]
                elif p[j]=='*':
                    if p[j-1]==s[i] or p[j-1]=='.':
                        count[(j + 1, i + 1)]=count[(j-1,i+1)] or count[(j+1,i)]
                    else:
                        count[(j+1,i+1)]=count[(j-1,i+1)]
                else: count[(j+1,i+1)]=False
        return count[(len(p),len(s))]


```