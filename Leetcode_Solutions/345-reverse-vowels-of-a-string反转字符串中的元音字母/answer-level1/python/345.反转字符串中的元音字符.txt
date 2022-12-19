### 解题思路
双指针，i从0开始寻找元音，j从len(s)-1开始寻找。相遇就停止。
list()函数：替换元组为列表，用于修改元素。（元组不能修改）
创造元音列表vowels，注意还有大写情况。
join()函数：以指定分隔符连接列表，元组，字符串中的元素。


### 代码

```python
class Solution(object):
    def reverseVowels(self, s):
        target = list(s)
        vowels = ["a","e","i","o","u","A","E","I","O","U"]
        i = 0
        j = len(s) - 1
        while i < j :
            if target[i] not in vowels:
                i += 1
            elif target[j] not in vowels:
                j -= 1
            else:
                target[i],target[j]=target[j],target[i]
                i += 1
                j -= 1
        return "".join(target)
```