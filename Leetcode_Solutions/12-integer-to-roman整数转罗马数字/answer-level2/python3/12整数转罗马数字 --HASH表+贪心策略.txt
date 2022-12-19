### 解题思路
贪心策略：大问题分解为小问题，每次求得局部最优解，将局部最优解合并当作全局的最优解。这里每次取尽量大的数表示。
1.HASH表键按从大到小排序
2.先用1000（M）表示，剩下的数字再用900（CM）表示，依次向下，最后剩下的数为0，则返回。

### 代码

```python3
class Solution:
    def intToRoman(self, num: int) -> str:
        #贪心策略：每次取尽量大的数表示
        HT={1000:'M',900:'CM',500:'D',400:'CD',100:'C',90:'XC',50:'L',40:'XL',10:'X',9:'IX',5:'V',4:'IV',1:'I'}
        res=''
        for key in HT:#遍历键列表
            if num==0:break#当数字为0时不用再循环
            ti=num//key#需要重复的次数
            num=num%key#剩余要计算的数
            res+=HT[key]*ti
        return res

```