![38.jpg](https://pic.leetcode-cn.com/07b49c579ba3ec681976d68071ffa24e8ef6794ce43a3d928794799cf2e2b7cd-38.jpg)

```
def genHelper(n):
    if n:
        gen=genHelper(n-1)
        lastDigit=gen.__next__()
        count=1

        for i in gen:
            if i==lastDigit:
                count+=1
            else:
                yield count
                yield lastDigit
                lastDigit=i
                count=1
        
        yield count
        yield lastDigit
        

    else:
        yield 1
        

class Solution:
    def countAndSay(self, n: int) -> str:
        return ''.join(map(str,genHelper(n-1)))
```
