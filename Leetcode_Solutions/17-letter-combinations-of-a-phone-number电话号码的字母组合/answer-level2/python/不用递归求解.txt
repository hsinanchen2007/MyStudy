取第一个号码对应的列表1，与后一个号码对应的列表2的每一项进行组合，得到新的列表，一直向后遍历号码即可。
```python
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        phone = {
            '2':['a','b','c'],
            '3':['d','e','f'],
            '4':['g','h','i'],
            '5':['j','k','l'],
            '6':['m','n','o'],
            '7':['p','q','r','s'],
            '8':['t','u','v'],
            '9':['w','x','y','z'],
        }
        output = []
        for i in range(len(digits)):
            num = digits[i]
            list = phone[num]
            if i == 0:
                output = list
            else:
                output = self.combine(output,list)
        return output

    def combine(self,output,list):
        temp = []
        for i in range(len(output)):
            t = output[i]
            for j in range(len(list)):
                temp.append(t+list[j])
        return temp
```
