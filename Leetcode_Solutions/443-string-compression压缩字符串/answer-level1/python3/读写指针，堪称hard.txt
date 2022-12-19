```
class Solution:
    def compress(self, chars: List[str]) -> int:
        if not chars:
            return 0

        read,write=1,1
        count=1
        while read<len(chars):
            if chars[read]==chars[read-1]:
                count+=1
            else:
                if count>1:
                    for s in str(count):
                        chars[write]=s
                        write+=1
                    count=1
                chars[write]=chars[read]    #前面的count写完了，当前字符要更新
                write+=1    #当前字符的count或者下一个字符写在这里
            read+=1

        if count>1:
            for s in str(count):
                chars[write]=s
                write+=1
        
        while write<len(chars):
            del chars[write]
```
