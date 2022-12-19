### 代码
很简单

### 代码

```python3
class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        T = []
        list1 = list(set('qwertyuiop'))
        list2 = list(set('asdfghjkl'))
        list3 = list(set('zxcvbnm'))
        def match(list0,str1):
            str1 = list(set(str1.lower()))
            for i in range(len(str1)):
                if str1[i] not in list0:
                    return False
            return True
        for i in range(len(words)):
           if match(list1,words[i]) == True or match(list2,words[i]) == True or match(list3,words[i]) == True:
               T.append(words[i])
        return T

```