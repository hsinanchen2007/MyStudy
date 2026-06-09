## 思路
+ 题目意思挺费解的，但是评论区解释得挺清楚了
### 循环含义
+ 每次外循环含义为给定上一个人报的数，求下一个人报的数
+ 每次内循环为遍历上一个人报的数
### 具体思路
+ 先设置上一人为'1'
+ 开始外循环
+ 每次外循环先置下一人为空字符串，置待处理的字符`num`为上一人的第一位，置记录出现的次数为1
+ 开始内循环，遍历上一人的数，如果数是和`num`一致，则`count`增加。
+ 若不一致，则将`count`和`num`一同添加到`next_person`报的数中，同时更新`num`和`count`
+ 别忘了更新`next_person`的最后两个数为上一个人最后一个字符以及其出现次数！
## 代码
```Python
class Solution:
    def countAndSay(self, n: int) -> str:
        prev_person = '1'
        for i in range(1,n):
            next_person, num, count = '', prev_person[0], 1
            for j in range(1,len(prev_person)):
                if prev_person[j] == num:count += 1
                else:
                    next_person += str(count) + num
                    num = prev_person[j]
                    count = 1
            next_person += str(count) + num
            prev_person = next_person
        return prev_person
```