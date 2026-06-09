### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def intToRoman(self, num):#解法2
        """
        :type num: int
        :rtype: str
        """
        special={"IIII":"IV","VIIII":"IX","XXXX":"XL","LXXXX":"XC","CCCC":"CD","DCCCC":"CM"}
        wei=["I","X","C","M"]
        num=str(num)
        lenNum=len(num)
        res=""
        for w in range(lenNum):
            res+=wei[lenNum-w-1]*int(num[w])
        try:
            res=res.replace("IIIII","V").replace("XXXXX", "L").replace("CCCCC", "D")
        except:
            pass
        for key in list(special.keys())[::-1]:
            res = res.replace(key, special[key])
        return res
```