```python
class Solution:
    def reverseWords(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        # Time complexity  :  O(N)
        # Space complexity :  O(1)
      
        def reverse(ch_arr: List[str], l:int , r:int) -> None:
            while l < r:
                ch_arr[l], ch_arr[r] = ch_arr[r], ch_arr[l]
                l += 1
                r -= 1
        reverse(s, 0, len(s) - 1)
     
        begin = 0
        for i in range(len(s) + 1):
            if i == len(s) or s[i] == ' ' :
                reverse(s, begin, i - 1)
                begin = i + 1
```