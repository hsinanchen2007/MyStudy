```
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        try:
            leng1 = len(words[0])
        except IndexError:
            return([])
        leng1 = len(words[0])
        leng2 = len(s)
        leng3 = len(words)
        leng4 = words.count(words[0])
        num1 = leng1 * leng3
        try:
            str_1 = s[0] * leng2
        except IndexError:
            return([])
        list1 = words[:]
        list2 = []
        flag1,flag2,flag3 = 1,1,1
        if str_1 == s:
            flag1 = 0
        if leng3 == leng4:
            flag2 = 0
        if words[0] in s:
            flag3 = 0
        if flag1 == 0 and flag2 == 0 and flag3 == 0:
            result = leng2 - num1 + 1
            list2 = list(range(result))
            return(list2)
        i = 0
        k = 0
        while True:
            j = i + leng1
            str1 = s[i:j]
            if str1 in list1:
                list1.remove(str1)
                i += leng1
                if not list1:
                    list2.append(k)
                    k += 1
                    i = k
                    list1 = words[:]
            else:
                k += 1
                i = k
                list1 = words[:]
            if i > leng2:
                return(list2)
```
