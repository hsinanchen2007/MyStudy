写了好几种递归方法，但是效率有所不同，最好的甚至只需要最慢的时间的二分之一。。。不知道谁能解答一下不
这是最慢的，也是另一个题解的提供者powcai的代码
```
   def letterCombinations(self, digits: str):
        dic = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz"
        }
        if not digits:
            return []
        ret = []
        n = len(digits)
        def helper(i, curStr):
            nonlocal ret
            if i == n:
                ret.append(curStr)
                return
            else:
                for chara in dic[digits[i]]:
                    helper(i+1,curStr+chara)
        helper(0,"")
        return ret
```
- 
这是速度中等的
```
        if not digits:
            return []
        ret = [""]
        n = len(digits)
        def helper(i, curStr):
            nonlocal ret
            if i == n:
                return
            else:
                ret.pop()
                for chara in dic[digits[i]]:
                    ret.append(curStr+chara)
                    helper(i+1,curStr+chara)
        helper(0,"")
        return ret
```

这是最快的
```
        if not digits:
            return []
        ret = [""]
        n = len(digits)
        def helper(i, curStr):
            nonlocal ret
            if i == n:
                return
            else:
                ret.pop()
                for chara in dic[digits[i]]:
                    curStr += chara
                    ret.append(curStr)
                    helper(i+1,curStr)
                    curStr = curStr[:-1]
        helper(0,"")
        return ret
```