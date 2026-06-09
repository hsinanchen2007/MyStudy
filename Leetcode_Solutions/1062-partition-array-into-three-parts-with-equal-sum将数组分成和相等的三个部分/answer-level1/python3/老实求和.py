```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        '''这个因为序列顺序是不发生变化的,所以求和除三，并且叠加判断就可以
        '''

        a=sum(A)
        if not a/3==int(a/3):
            return False
        else:
            sumA=0
            index=0
            while 1:
                sumA=sumA+A[index]
                index=index+1
                
                if sumA==a/3:
                    print(index)
                    break
                if index == len(A)-2 :
                    return False
            
            
            while 1:
                sumA=sumA+A[index]
                index=index+1
                if sumA==2*a/3:
                    print(index)
                    break
                if index == len(A)-1 :
                    return False
            
        return True
```
