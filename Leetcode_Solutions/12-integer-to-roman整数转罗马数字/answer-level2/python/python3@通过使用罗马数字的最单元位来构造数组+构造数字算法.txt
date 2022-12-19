## 题目描述

罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。

### 解题思路
由题意可知，从整数转化为罗马数字的时候，每个位上的数字（0~9）都是由四种类型的罗马数字组成的
比如个位数：
- `'(null)'`
- `I`
- `V`
- `X`

通过此思路，我们可以构造一个二维list。
```
self.Glossary = [
            ['I','V','X'],
            ['X','L','C'],
            ['C','D','M'],
            ['M'],
        ]
```

**傲娇脸**（感觉这种思路更深一点）


> 相比其他巨佬（我是菜鸡）的题解中构造的数组，比如[@liweiwei1419](/u/liweiwei1419/)的[题解](https://leetcode-cn.com/problems/integer-to-roman/solution/tan-xin-suan-fa-by-liweiwei1419/)：
>```
> nums = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
> romans = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
>```
> 这种思路相当于是将每个位数（比如个位数）的1-4-5-9给单独列出来了。其中1 5 10 是构造数字的单元（最底层）的单元字符，而因为4和9的构造规则和123 678的规则不一样，所以题主将1-4-5-9单独列出来再进行算法匹配，就更顺畅。这位巨佬的每个位数需要构造4个字符，但是上述的构造方法只需要定义三个单元字符。

> [在评论区也看到以为巨佬用的这种构造方法](https://leetcode-cn.com/problems/integer-to-roman/comments/3765)：
> ```
> m = [
>             ['', 'M', 'MM', 'MMM'],
>             ['', 'C', 'CC', 'CCC', 'CD', 'D', 'DC', 'DCC', 'DCCC', 'CM'],
>             ['', 'X', 'XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC'],
>             ['', 'I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX']
>         ]
> ```
> 可能大家看到这种的时候会想，这么直接的吗，把每个位数的1-9全部列出来了，但是我感觉这种方法相比上面第一个巨佬的方法更好一些，因为这种方法的思路比较清晰：我分位数来构造数组，将每个位的所有出现的情况全部列出来，这种方式就相当于我们先花最大的空间来构造我们需要的（类似哈希表吧），然后再用复杂度比较低的算法来进行简单的匹配。
> ```
> class Solution:
>     def intToRoman(self, num):
>         m = [
>             ['', 'M', 'MM', 'MMM'],
>             ['', 'C', 'CC', 'CCC', 'CD', 'D', 'DC', 'DCC', 'DCCC', 'CM'],
>             ['', 'X', 'XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC'],
>             ['', 'I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX']
>         ]
>         d = [1000, 100, 10, 1]
>         r = ''
>         for k, v in enumerate(d):
>             r += m[k][int(num/v)]
>             num = num % v
>         return r
> ```
> 妙啊，点个赞。（这种思路将算法最简单化，但是空间的使用也是最大的）

好了，上述引用的两个大佬，我真的觉得很牛逼，将空间略微复杂化了然后使用最巧妙地算法。

那使用这种最底层地单元化地构造方法：
```
self.Glossary = [
            ['I','V','X'],
            ['X','L','C'],
            ['C','D','M'],
            ['M'],
        ]
```
 
如何来写算法呢


罗马数字地构造思路：
在每一个（十分）位上
- 用1单元位来叠加构造1-3 
    - 比如I,II,III 或者X,XX,XXX
- 用1和5单元位来构造4 
    - 比如IV 或者XL
- 用5来直接使用 
    - 比如V 或者L
- 用1和5来构造6-8 
    - 比如VI,VII,VIII或者LX,LXX,LXXX
- 用1和10来构造9 
    - 比如IX 或者XC

说到这里其实，罗马数字是一种5进制地数，（个人认为哈）。

但是由于我们地整数时10进制地，所以4和9地构造相当于就是两种不同地构造方法（用此十分位的1和5来构造、用此此十分位的1和下个十分位的10来构造）

那我们需要将这几个特例拿出来：
```
while _<x:
    res+=v[0]
    _+=1
    if _==4:
        res=v[0]+v[1]
    elif _==5:
        res=v[1]
    elif _==9:
        res=v[0]+v[2]
```

具体代码如下：
```
    def viaDict(self, num:int) -> str:
        resl,nlist=[],list(str(num))
        for k,v in enumerate(self.Glossary):
            try:
                _,res,x=0,'',int(nlist.pop())
                while _<x:
                    res+=v[0]
                    _+=1
                    if _==4:
                        res=v[0]+v[1]
                    elif _==5:
                        res=v[1]
                    elif _==9:
                        res=v[0]+v[2]
                resl.insert(0,res)
            except (StopIteration,IndexError):
                # 遇到StopIteration就退出循环
                break
        return "".join(resl)
 ```

### 代码

```python3
#
# @lc app=leetcode.cn id=12 lang=python3
#
# [12] 整数转罗马数字
#

# @lc code=start
class Solution:
    def __init__(self):
        self.Glossary = [
            ['I','V','X'],
            ['X','L','C'],
            ['C','D','M'],
            ['M'],
        ]
    def viaDict(self, num:int) -> str:
        resl=[]
        # get the Iterator Object first:
        nlist = list(str(num))
        for k,v in enumerate(self.Glossary):
            try:
                _=0
                res=''
                x=int(nlist.pop())
                while _<x:
                    res+=v[0]
                    _+=1
                    if _==4:
                        res=v[0]+v[1]
                    elif _==5:
                        res=v[1]
                    elif _==9:
                        res=v[0]+v[2]
                resl.insert(0,res)
            except (StopIteration,IndexError):
                # 遇到StopIteration就退出循环
                break
        return "".join(resl)
    def intToRoman(self, num: int) -> str:
        return {
            1:lambda num:self.viaDict(num),
        }[1](num)
# @lc code=end

if __name__ == "__main__":
    solve = Solution()
    # print(solve.Glossary.items())
    print(solve.intToRoman(444))
```
运行效果：
```
Accepted
3999/3999 cases passed (52 ms)
Your runtime beats 78.07 % of python3 submissions
Your memory usage beats 51.92 % of python3 submissions (13.2 MB)
```

一百个人读哈姆雷特就有一百个哈姆雷特。

## leetcode
leetcode解题得的源码，解题思路在代码的注释里。
- 我的leetcode主页<https://leetcode-cn.com/u/boywithacoin_cn/>
- 我的个人博客<https://boywithacoin.cn/>
- github_所有源码网址<https://github.com/Freen247/leetcode>