主要方法：
string的count方法：计算一个子字符串在该字符串中出现的次数
string的find方法；find 如果找不到返回-1，找到了返回具体的索引值；
      判断条件以找不到比较固定，找不到LLL 就是没有大于2个连续LL的存在；



```
class Solution:
    def checkRecord(self, s: str) -> bool:
        count = s.count('A')
        
        if  count <= 1 and s.find('LLL') == -1:
            return True
        else:
            return False
```
 



详细注释版：
```
class Solution:
    def checkRecord(self, s: str) -> bool:
        count = s.count('A')

        print (s.count('A') ,s.count('A') > 1,s.find('LLL'),s.find('LLL') == -1)
        
        if  count <= 1 and s.find('LLL') == -1:
            return True
        else:
            return False

        # 如何把-1 转成false，是需要自己写方法实现吗？
        # s.find('LLL') == -1
```
