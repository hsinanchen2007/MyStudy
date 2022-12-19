```
class Solution:
    def longestWord(self, words: List[str]) -> str:
        mydict = {}
        for word in words:
            if len(word) not in mydict:
                newlist = []
                newlist.append(word)
                mydict[len(word)] = newlist
            else:
                rawlist = mydict[len(word)]
                rawlist.append(word)
                mydict[len(word)] = rawlist
        init = 1
        initlist = mydict.get(1)
        while init+1 in mydict:
            thlist = [m for m in mydict.get(init+1) if m[:-1] in initlist]
            if not thlist:
                break
            else:
                initlist = thlist
                init = init + 1
        if not initlist:
            return ""
        else:
            initlist.sort()
            return initlist[0]
```
