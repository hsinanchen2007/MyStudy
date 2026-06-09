实名吐槽评论第一的暴躁老哥解体法哈。
这破题目表达的不够明确，我拿到题目的理解是这样的；
给定一个数字 1~30，然后对这个数报数n遍。
等我写完了，再仔细看下面的例子，
输入: 4
输出: "1211"
这特么不还是从1开始数数的么。。。所以后面将input_str 改为了"1"
题目其实不难
```
class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        def convert(input_str):
            string = ""
            index = 1
            for i in range(len(input_str)):
                if i == len(input_str)-1:
                    string += str(index) + input_str[i]
                    break
                if input_str[i] != input_str[i+1]:
                    string += str(index) + input_str[i]
                    index = 1
                else:
                    index += 1
            return string

        input_str = '1'
        for i in range(n-1):
            input_str = convert(input_str)
        return input_str
```
