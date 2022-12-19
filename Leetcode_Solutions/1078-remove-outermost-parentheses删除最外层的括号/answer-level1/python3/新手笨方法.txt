
```
class Solution:
    def removeOuterParentheses(self, S):
        result=str()
        temp = 0
        count = 0
        num = 0
        for i in range(len(S)):
            if S[i] =='(':
                count+=1
            else:
                count-=1
            if count ==0:
                mid_result = str(S[temp:i+1])
                mid_result = mid_result[1:-1]
                temp = i+1
                result = str(result+mid_result)
                num= 0
        return result
            
        
if '__name__'=='__main__':
    S='(()()())()'
    solution = Solution()
    result = soluton.removeOuterParenthese(S)
    print(result)
```