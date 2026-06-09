![443.jpg](https://pic.leetcode-cn.com/6782e1fd25bac953984cdee42780606dec22f5a79b19e63385c83e267b7c8ba3-443.jpg)
一直操作列表，所以效率不太高
```
class Solution:
    def compress(self, chars: List[str]) -> int:
        lastChar=chars[0]
        count=1
        index=1
        
        while index<len(chars):
            if chars[index]==lastChar:
                count+=1
                del chars[index]

            else:
                lastChar=chars[index]
                if count!=1:
                    for i in str(count):
                        chars.insert(index,i)
                        index+=1
                index+=1
                count=1

        if count!=1:
            chars+=str(count)

        return len(chars)
```
