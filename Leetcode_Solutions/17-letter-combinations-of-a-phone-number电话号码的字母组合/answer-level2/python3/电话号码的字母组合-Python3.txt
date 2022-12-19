#### 2步解题思路：快速递归迭代组合 + 正则
优点：易理解，通用化；
缺点：处理较复杂

（1）itertools：迭代模块
（2）re：正则表达式

- 例子1:
```
输入："23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

- 例子2:
```

输入："2468"
输出：["agmt","agmu","agmv","agnt","agnu","agnv","agot","agou","agov","ahmt","ahmu","ahmv","ahnt","ahnu","ahnv","ahot","ahou","ahov","aimt","aimu","aimv","aint","ainu","ainv","aiot","aiou","aiov","bgmt","bgmu","bgmv","bgnt","bgnu","bgnv","bgot","bgou","bgov","bhmt","bhmu","bhmv","bhnt","bhnu","bhnv","bhot","bhou","bhov","bimt","bimu","bimv","bint","binu","binv","biot","biou","biov","cgmt","cgmu","cgmv","cgnt","cgnu","cgnv","cgot","cgou","cgov","chmt","chmu","chmv","chnt","chnu","chnv","chot","chou","chov","cimt","cimu","cimv","cint","cinu","cinv","ciot","ciou","ciov"]
```

**python3代码：**

```
import itertools
import re

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if digits == "":
            return []
        else:
            myres, res = [], [""]
            dict_number = {
                            "2":["a","b","c"],
                            "3":["d","e","f"],
                            "4":["g","h","i"],
                            "5":["j","k","l"],
                            "6":["m","n","o"],
                            "7":["p","q","r","s"],
                            "8":["t","u","v"],
                            "9":["w","x","y","z"]
                            }
            for index in list(digits):
                res = itertools.product(res, dict_number[index])          # 1、快速递归迭代
            for result in res:
                myres.append("".join(re.findall(r"[a-z]", str(result))))  # 2、正则处理迭代结果
            return myres
```
