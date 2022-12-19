思路简述：
定义两个指针，从头开始对比，遇到“X”直接跳过，因为根据题意，X可以和R，L交换位置。
1.当两个指针分别遇到第一个非X的字符时，对比，如果不同，不存在移动操作，因为LR是不能互相换位的。
2.两指针都遇到R字符时，如果start字符串的指针位置比end靠后，不存在，因为移动操作只能使R右移。
3.两指针都遇到L字符时，如果start字符串的指针位置比end靠前，不存在，因为移动操作只能使L左移。

```
class Solution:
    def canTransform(self, start: str, end: str) -> bool:
        i,j=0,0
        while i<len(start) and j<len(end) :

            while i<len(start)-1 and start[i]=='X':
                i+=1

            while j<len(end)-1 and end[j]=='X':
                j+=1

            #LR不能互相穿过
            if start[i]!=end[j]:
                return False

            #R只能右移
            if start[i]=='R' and end[j]=='R':
                if i>j:
                    return False


            #L只能左移
            if start[i]=='L' and end[j]=='L':
                if i<j:
                    return False

            i+=1
            j+=1
        return True
```
