一 算法设计
1 初始值 
n=1,返回“1”
2 两层循环递推
（1）外层循环
根据报数序列的项数n确定内层循环执行次数
（2）内层循环
根据上次所报数计算下一次所报数
基本思路：
记上次所报数为s,设置new_str=""
循环遍历上一次所报数中字符，当当前字符与下一个字符不一致时，将当前字符连续出现次数和当前
字符加入new_str，遍历结束所得new_str即为下次所报数
用new_str更新s,用于下一轮计算
二 Python3实现
```
class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        
        s = "1"
        for i in range(2, n+1):
            new_str = ""
            count = 1
            m = len(s)
            for i in range(m-1):
                if s[i] == s[i+1]:
                    count += 1
                else:
                    new_str += str(count) + s[i]
                    count = 1
            new_str += str(count) + s[-1]
            s = new_str
        return s
```
