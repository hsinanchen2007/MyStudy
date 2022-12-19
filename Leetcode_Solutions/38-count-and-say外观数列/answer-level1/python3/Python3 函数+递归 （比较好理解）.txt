**思路：先定义一个“读”函数来生成附和格式的字符序列；然后设置递归出口。每次的结果都是对上一次结果的“读取”**```
缺点是时间复杂度和空间复杂度比较一般；但理解起来相对比较容易

代码块
```class Solution:
    def countAndSay(self, n: int) -> str:
        ## 设置“读”函数
        def explain(string):
            sample = string[0]
            time = 0
            desc = ''
            for i in string:
                if i == sample:
                    time += 1
                else:
                    desc += str(time) + sample
                    sample = i
                    time = 1
            desc += str(time) + sample
            return desc

        ## 构建递归
        if n == 1:
            return '1'
        else:
            return explain(self.countAndSay(n-1))
