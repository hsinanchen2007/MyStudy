```class Solution:
    def singleNumber(self, nums: List[int]) -> int:
       

        '''
         one = three & item | one & ~item
         two = one & item | two & ~item
         three = two  & item | three & ~item
        '''
        one, two, three = 0,0, ~0
        for item in nums:
            tmp = three
            three = two  & item | three & ~item
            two = one & item | two & ~item
            one = tmp & item | one & ~item
        return one
```
