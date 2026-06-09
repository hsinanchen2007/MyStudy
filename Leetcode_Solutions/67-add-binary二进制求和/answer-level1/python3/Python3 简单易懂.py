### 解题思路
执行用时 :40 ms, 在所有 python3 提交中击败了81.13%的用户
内存消耗 :12.7 MB, 在所有 python3 提交中击败了99.69%的用户

来菜鸡互啄呀~~~~
### 代码

```python3
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        la = len(a)-1   #指向a的元素，从后往前
        lb = len(b)-1   #指向b的元素，从后往前
        carry = 0       #进位
        res = ''
        while la>=0 or lb>=0:   #只要a或b有一个没有算完，就执行循环b
            va = a[la] if la>=0 else 0  #如果a的长度比较小，补0
            vb = b[lb] if lb>=0 else 0  #如果b的长度比较小，补0
            s = (int(va) + int(vb) + carry) % 2 #求和
            carry = 1 if (int(va)+int(vb)+carry>=2) else 0 
            la -= 1 #每次算完之后指向a的箭头往前移一位
            lb -= 1
            res = str(s)+res    #把每次算出的结果左插入到最终输出
        if carry == 1:
            res = '1' + res #算完后如果最高位还要进位，就加一个‘1’
        return res

```