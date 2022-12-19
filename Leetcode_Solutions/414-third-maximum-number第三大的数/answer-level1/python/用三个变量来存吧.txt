```
class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        import sys
        
        m_1 = -sys.maxsize
        m_2 = -sys.maxsize
        m_3 = -sys.maxsize
        
        for n in list(set(nums)):
            if n > m_1:
                m_1, m_2, m_3 = n, m_1, m_2
            elif n > m_2:
                m_2, m_3 = n, m_2
            elif n > m_3:
                m_3 = n
        
        return m_3 if m_3 != -sys.maxsize else m_1
```
