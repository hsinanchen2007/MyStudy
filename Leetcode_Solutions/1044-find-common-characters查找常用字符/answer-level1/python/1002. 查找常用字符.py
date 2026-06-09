
```
class Solution(object):
    def commonChars(self, A):
        """
        :type A: List[str]
        :rtype: List[str]
        """
        L = []
        A = [list(word) for word in A] 
        F = A[0]
        for letter in F:
            flag = True
            for word in A[1:]:
                if letter in word:
                    word.remove(letter)
                else:
                    flag = False

            if flag == True:
                L.append(letter)     
        return L
```
