```
class Solution:
    def monotoneIncreasingDigits(self, N: int) -> int:
        str1 = str(N)
        n1 = len(str1)
        list1 = list(str1)
        list1.reverse()
        str3 = ""
        def change_jiu(n):
            text = ""
            for i in range(n):
                text += "9"
            return(text)
        #print(list1)
        if n1 == 1:
            return(N)
        else:
            i,j = 0,1
            while j < n1:
                if list1[i] >= list1[j]:
                    str3 += list1[i]
                else:
                    str3 += list1[i]
                    n2 = len(str3)
                    str3 = change_jiu(n2)
                    list1[j] = str(int(list1[j])-1)
                i += 1
                j += 1
            str3 += list1[i]
            str4 = str3[::-1]
            return(int(str4))
        
        
```
