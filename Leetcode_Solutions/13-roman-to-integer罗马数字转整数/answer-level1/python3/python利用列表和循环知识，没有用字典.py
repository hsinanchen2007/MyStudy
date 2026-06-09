### 解题思路
小白一枚
1.先将所有输入的罗马字转化为阿拉伯数字存在列表
2.判断列表长度，如果唯一直接输出对应的阿拉伯数字
3.如果列表长度大于1，始终判断列表的首位与第二位的数值大小，当首位数值大，存入下一个列表。
4.弹出首元素，如果一直是首位比第二位大则一直弹出，此处说明一下，当最后列表只剩一个元素时，由于我写的是首元素与下一个相比，那么就会超出列表范围，这时候我们就要利用之前写的判断列表长度，转到如果为1的时候，在后面面把最后一个元素追加（说的有点乱哈，理解一下，如有大佬能够再指正一下更好的写法，感激不尽）
5.当首位比第二小的时候，就是应该是此题关键，弹出两个元素，进行相减，之后再存入ANS列表中
6.最后将列表的值做个循环加在一起
### 代码

```python
class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        li = list(s)
        ans = list()
        ANS = list()
        answer = 0
        po = 0
        i = 0 
        while li:
            xx = li.pop(0)
            if xx == 'I':
                ans.append(1)
            elif xx == 'V':
                ans.append(5)
            elif xx =='X':
                ans.append(10)
            elif xx =='L':
                ans.append(50)
            elif xx =='C':
                ans.append(100)
            elif xx == 'D':
                ans.append(500)
            elif xx == 'M':
                ans.append(1000)

        while len(ans)>1:
            if ans[i] >= ans[i+1]:
                bo = ans.pop(0)
                ANS.append(bo)
            else:
                po1 = ans.pop(0)
                po2 = ans.pop(0)
                po = po2-po1
                ANS.append(po)
        if len(ans)==1:
            ANS.append(ans[i])
        else:
            pass
        for i in range(len(ANS)):
            answer += ANS[i]
        return answer
```