### 解题思路
1. 三种金额，5美元，10美元，20美元，相对应的只有三种找零，不找零，找五美元，找十五美元。
2. 找十五美元有两种情况，5+10和5+5+5，可着5+10先进行判断。
3. 根据以上几种情况写if else就好了。

### 代码

```python3
class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        five, ten = 0, 0

        for item in bills:
            if item == 5:  # 如果是5美元，不用找零，5美元增加一张
                five += 1
            elif item == 10:  # 如果是10美元
                if not five: return False  # 如果没有5美元，返回False
                five -= 1  # 如果有，减少一张5美元，增加一张10美元
                ten += 1
            else:  # 如果是20美元
                if five and ten:  # 如果5和10都有，分别减去一张
                    five -= 1
                    ten -= 1
                elif five > 2:  # 如果5美元多于两张，5美元减去三张
                    five -= 3
                else:
                    return False  # 如果不符合以上两种情况，返回False
        
        return True


   
```