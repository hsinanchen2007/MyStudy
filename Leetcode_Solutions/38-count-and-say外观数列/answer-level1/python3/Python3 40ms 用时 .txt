```
class Solution:
    def countAndSay(self, n: int) -> str:


        def say_str(say):
            say = say + "#" # 给输入的字符串加一个终止符号
            res = str()
            start = 0
            end = start
            while end < len(say)-1: # 遍历数组, end 指向 最后一个字符 '#'时候终止,此时 end == len(say) - 1
                while say[end] == say[start]: # 寻找连续一样的数字
                    end += 1
                temp = say[start:end]
                start = end
                res += str(len(temp)) + str(temp[0]) # 第一个字符是连续相等的个数,第二个是该数字是什么
            return res


        say = "1"
        for i in range(n-1):
            say = say_str(say) # 利用n的结果 计算 n+1的结果
        return say
```
