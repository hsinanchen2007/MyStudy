## 一个挺有意思的解法
注意到这个Count and Say并没有太多python的解法，于是提交一个抛砖引玉~  
要点：
    * 为了解决队尾循环下标越界的问题，在队尾加上了一个特殊元素“s”
···
class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return '1'
        else:
            r = ''
            l = self.countAndSay(n - 1) + 's' 
            co =1
            for i in range(len(l)-1):
                if l[i] == l[i + 1]:
                    co += 1
                else:
                    r += str(co) + l[i]
                    co = 1
            return r
···