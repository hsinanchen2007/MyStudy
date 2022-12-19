从这道题开始明白，小白基本都着急于寻求快速做出这个题的方法，所以思考很少，往往整成暴力解法。而大佬们真是演绎了一种解题艺术，方法巧妙并且姿势优雅。
第一次提交这个题，由前面做的题直接暴力，数组转成数字加1再转成数组。
![QQ截图20191130094841.png](https://pic.leetcode-cn.com/01c2c135035892e63cda4b9fec987aaa38b70db1f483b681dd30896826d4debb-QQ%E6%88%AA%E5%9B%BE20191130094841.png)
再阅读了题解区榜首大佬YHHZW的方法，只能手动点赞了
用大佬的方法用python写了一遍，又更加发现其中的巧妙之处
![QQ截图20191130094907.png](https://pic.leetcode-cn.com/f42b0d73c583dd3684bbd77931b6f1649d2ed055f15a5765a67f47654170eeea-QQ%E6%88%AA%E5%9B%BE20191130094907.png)
```
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        # 先加1
        for i in range(len(digits)-1, -1, -1):
            digits[i] += 1
            digits[i] = digits[i] % 10  # 如果产生进位后当前位为0
            if digits[i] != 0:  # 如果没有产生进位或者进位加1后不为0
                return digits
        # 所有位都产生进位后,即9,99,...,数组已全置为0
        digits.append(0)
        digits[0]= 1
        return digits
```
不能在暴力解法的道路越走越远了
