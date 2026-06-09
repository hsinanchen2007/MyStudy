```
class StringIterator:

    def __init__(self, compressedString: str):
        self.idx=0
        self.used=self.have=1
        self.s='_1'+compressedString

    def next(self) -> str:
        if self.hasNext():
            if self.used<self.have:
                self.used+=1
            else:
                self.idx+=len(str(self.have))+1
                until=self.idx+1
                while until<len(self.s) and self.s[until].isnumeric():
                    until+=1
                self.have=int(self.s[self.idx+1:until])
                self.used=1
            return self.s[self.idx]
        return ' '

    def hasNext(self) -> bool:
        return not(self.s[self.idx+1:].isnumeric() and self.used==self.have)
```
