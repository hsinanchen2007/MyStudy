对于一个（正）数，转换进制无非就是对目标进制数反复求模/余，将所有余数逆序拼接即可。注意`num=0`和`num`为负的情况。
```
class Solution:
    def toHex(self, num: int) -> str:
        hexi=['0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f']
        if num==0:
            return '0'
        if num<0:
            num=num+16**8
        result=[]
        while num>0:
            num,mod=divmod(num,16)
            re.append(hexi[mod])
        return ''.join(reversed(result))
```
![QQ9.png](https://pic.leetcode-cn.com/1ace2bd952ae501d5fb07a3603a31fe1ed793dd915d6fb548d06902c02099dc6-QQ9.png)
执行用时 :36 ms, 在所有 python3 提交中击败了93.88%的用户
内存消耗 :13.9 MB, 在所有 python3 提交中击败了5.06%的用户