### 解题思路
此处撰写解题思路
题目输入做了限制：1-3999
因此我们只需考虑4个部分，千位的处理，百位的处理，十位的处理以及个位的处理。<br>
1.千位的处理 a1
    num//1000-> a1*"M" 整除1000的结果a1表示有a1个"M"<br>
2.百位的处理 a2
    (num - a1*1000) :表示剩下的百位部分
    a2 = (num -a1 *1000)//100 :整除100的结果a2
    此时a2需要分情况讨论：
        (1) a2 = 9时,     表示900,即"CM"
        (2) a2 = [5,9)时, 表示500-800,即"D"+"C"*(a2-5)
        (3) a2 = 4时,     表示400,即“CD”
        (4) a2 = [0,4)时, 表示0-300,即"C"*a2<br>
3.十位 a3 和个位 a4的分类同a2类似<br>
4.抽象出百位，十位，个位的情况得到：
```python3
def calStr(a, cxi,mcx,dlv):
            if(a>=5 and a<9): return dlv+cxi*(a-5)
            elif(a==4): return cxi+dlv
            elif(a==9): return cxi+mcx
            else: return cxi*a
```

### 代码

```python3
class Solution:
    def intToRoman(self, num: int) -> str:
        def calStr(a, cxi,mcx,dlv):
            if(a>=5 and a<9): return dlv+cxi*(a-5)
            elif(a==4): return cxi+dlv
            elif(a==9): return cxi+mcx
            else: return cxi*a
        res=""
        #千位整除a1:
        a1 = num//1000
        res += "M" * a1
        #百位a2:
        a2 = (num-a1*1000)//100
        res += calStr(a2, "C","M","D")
        #十位a3:
        a3 = (num-a1*1000-a2*100)//10
        res += calStr(a3,"X","C","L")
        #个位a4:
        a4 = num-a1*1000-a2*100-a3*10
        res += calStr(a4,"I","X","V")
        return res

```