```
class Solution:
    def strToInt(self, str: str) -> int:
      if not str:
        return 0
      flag = 0 ####flag代表两层意思：1出现了 + - 或数字 2 代表正负
      numS = ""
      for char in str:
        if numS == "" and char == " " and flag == 0:####"- 234"
          continue#"  42"
        elif numS == "" and char in "+-" and flag == 0:
          flag = 1 if char == "+" else -1
        elif char in "0123456789":
          numS += char
        else:break
      
      if not numS:return 0 ####"+"
      flag = flag if flag else 1 ####"12345"flag要从0变为1
      ans = flag * int(numS)
      if -2**31 <= ans <= 2**31 -1:
        return ans
      else:
        return -2**31 if ans < 0 else 2 ** 31 -1
```
