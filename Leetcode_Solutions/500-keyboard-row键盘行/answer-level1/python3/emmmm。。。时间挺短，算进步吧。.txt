```
class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        li=[]
        list1=['q','w','e','r','t','y','u','i','o','p','Q','W','E','R','T','Y','U','I','O','P']
        list2=['a','s','d','f','g','h','j','k','l','A','S','D','F','G','H','J','K','L']
        list3=['z','x','c','v','b','n','m','Z','X','C','V','B','N','M']
        for i in words:
            if set(list(i))|set(list1) == set(list1): 
                li.append(i)
            elif set(list(i))|set(list2) == set(list2):
                li.append(i)
            elif set(list(i))|set(list3) == set(list3): 
                li.append(i)
        return li
```
