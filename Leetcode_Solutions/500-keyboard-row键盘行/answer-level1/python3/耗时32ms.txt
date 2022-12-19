```
class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        s1 = "qwertyuiop"
        s2 = "asdfghjkl"
        s3 = "zxcvbnm"
        list1 = []
        for i in words:
            list2 = []
            k = i.lower()
            flg = "tr"
            for j in k:
                if j in s1:
                    if list2 == []:
                        list2.append(1)
                    else:
                        if 1 not in list2:
                            flg = "fl"
                            break
                        else:
                            pass
                elif j in s2:
                    if list2 == []:
                        list2.append(2)
                    else:
                        if 2 not in list2:
                            flg = "fl"
                            break
                elif j in s3:
                    if list2 == []:
                        list2.append(3)
                    else:
                        if 3 not in list2:
                            flg = "fl"
                            break
            if flg == "tr":
                list1.append(i)
        return(list1)
```
