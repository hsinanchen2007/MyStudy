### 解题思路
思路大家都一样。
找零时简单贪心优先用面值10元的。
如果用 C++，使用 switch 语句可以简洁清晰很多。
这里下面的if else 写的不好，很臃肿。


### 代码

```python3
class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        n = len(bills)
        if n==0:
            return True
        num_5, num_10 = 0, 0
        if bills[0] == 5:
            num_5 += 1
        else:
            return False
        for x in bills[1:]:
            if x == 5:
                num_5 += 1
            if x == 10:  # 可以改为 elif
                if num_5 > 0:
                    num_5 -= 1
                    num_10 += 1
                else:
                    return False
            if x == 20:  # 可以改为 elif
                if num_10 > 0:
                    num_10 -= 1
                    if num_5 > 0:  # 可以和上面合并 (num_10>0) and (num_5>0)
                        num_5 -= 1
                    else:
                        return False
                else:
                    if num_5 > 3:
                        num_5 -= 3
                    else:
                        return False
        return True

```