```
class Solution:
    def intToRoman(self, num: int) -> str:
        l = []
        res = ""
        index = 0
        li=["I","V","X","L","C","D","M"]
        for i in str(num):
            l.append(int(i))
        for i in range(len(l)):
            if l[-1-i] < 4:
                res = li[index] * l[-1-i] + res
            elif l[-1-i] == 4:
                res = li[index] + li[index+1] + res
            elif l[-1-i] == 5:
                res = li[index+1] + res
            elif l[-1-i] == 9:
                res = li[index]+li[index + 2] + res
            elif l[-1-i] == 0:
                pass
            else:
                res = li[index+1] + li[index] * (l[-1-i] - 5) + res
            index += 2
        return res

```
1.把num每位数加到列表 l[]
2.部所有罗马字母加到li列表里
3.遍历l[]列表，从个位开始根据0,4,5,9,1-3，6-8，不同情况写判断语句追加罗马字母
4.每次遍历字母列表索引index加2，因为每位数有两种字母表示。。。