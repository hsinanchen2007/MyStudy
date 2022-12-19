### 解题思路
寻找每个字符对应的数字组成的列表中，对应当前输入数字的最大因子nearest，并确定该因子的数量k，然后将数字中剩余未表示的部分left递归调用当前函数

![整数转罗马.png](https://pic.leetcode-cn.com/4f8bc7da659090b0bbc1c7b63f5a4e7472e77a912a9d209dd41db8dc1d9a3a7b-%E6%95%B4%E6%95%B0%E8%BD%AC%E7%BD%97%E9%A9%AC.png)


### 代码

```python3
class Solution:
    def intToRoman(self, x: int) -> str:
        r = ''
        def method(num, res):
            res = ""
            if num == 0:
                return ""
            if num == 4:
                res += "IV"
                return res
            elif num == 9:
                res+="IX"
                return res
            elif num == 40:
                res+="XL"
                return res
            elif num == 90:
                res+="XC"
                return res
            elif num == 400:
                res+="CD"
                return res
            elif num == 900:
                res+="CM"
                return res
            trans_dict = {1:"I", 4:"IV", 5:"V", 9:"IX", 10:"X", 40:"XL", 50:"L", 90:"XC", 100:"C", 400:"CD", 500:"D", 900:"CM", 1000:"M"}
            nearest = 1
            for i in trans_dict:
                if num < i: break
                nearest = i
            k = num // nearest
            left = num - k*nearest
            res += k*trans_dict[nearest]
            res += method(left, res)
            return res
        return method(x, r)



```