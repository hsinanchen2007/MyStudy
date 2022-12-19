```
class ValidWordAbbr:
    def ab(self,w):
        if len(w)<3:
            return w
        return w[0]+str(len(w)-2)+w[-1]

    def __init__(self, dictionary: List[str]):
        self.ab_dict=collections.defaultdict(set)
        for w in dictionary:
            self.ab_dict[self.ab(w)].add(w)
            
    def isUnique(self, word: str) -> bool:
        entry=self.ab_dict[self.ab(word)]
        return len(entry)==0 or (len(entry)==1 and word in entry)
```
