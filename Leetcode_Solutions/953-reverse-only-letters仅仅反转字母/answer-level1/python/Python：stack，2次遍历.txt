```
class Solution(object):
    def reverseOnlyLetters(self, S):
        """
        :type S: str
        :rtype: str
        """
        stack = ''
        new_str = ''
        for s in S:
            if s.isalpha():
                stack += s
        stack = stack[::-1]
      
        i = 0
        for s in S:
            if s.isalpha():
                new_str += stack[i]
            else:
                new_str += s
                i -= 1
            i += 1
        return new_str

```
时间复杂度：O(?)
空间复杂度：O(?)
