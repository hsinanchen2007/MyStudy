此题可以用递归方式进行求解，即countAndSay(n)处理的是countAndSay(n-1)的结果。
递归思路如下

def countAndSay(n)
- 如果n=1，返回字符串'1'
- 得到countAndSay(n-1)的字符串， 从字符串的第一位开始处理，辅助一个计数值count_num：表示重复的字符数，以及num：前一位的字符
   如果当前位与前一位一样，那么count_num加一；
   如果当前位于前一位不一样，那么需要把前面的字符输出，即追加 count_num+num的字符串；
最后，为了保证最后一位的信息也添加进去，增加了一步：strs+= count_num + char的操作。
- 最后，返回字符串strs即可。

代码如下：
```
class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return '1'
        count_num = 0
        num = ''
        strs = ''
        for char in self.countAndSay(n-1):
            if char != num:
                if count_num > 0:
                    strs += str(count_num) + num
                count_num = 1
                num = char
            else:
                count_num += 1
        strs += str(count_num) + char
        return strs
```