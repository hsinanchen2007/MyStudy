用两个计数器记录leftBracket个数和star个数，依次读取字符：
如果是'('：leftBracket加一，并修正star为min(star, leftBracket)
如果是'*'：star加一
如果是')'：若leftBracket非0，leftBracket减一；若star非0，star减一；否则返回False
遍历之后，返回leftBracket <= star


```
    def checkValidString1(self, s: str) -> bool:
        leftBracket, star, = 0, 0
        for e in s:
            if '(' == e:
                star = min(star, leftBracket)
                leftBracket += 1
            elif ')' == e:
                if leftBracket > 0:
                    leftBracket -= 1
                elif star > 0:
                    star -= 1
                else:
                    return False
            else:
                star += 1
        return leftBracket <= star
```
