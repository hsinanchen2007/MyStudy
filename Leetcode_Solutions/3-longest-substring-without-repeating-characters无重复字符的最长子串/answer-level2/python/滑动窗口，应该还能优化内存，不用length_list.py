class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        buffer = []
        length_list = []
        k = 0
        for c in s:
            if c not in buffer:
                k += 1
                buffer.append(c)
            else:
                buffer = buffer[buffer.index(c)+1:]
                buffer.append(c)
                length_list.append(k)
                k = len(buffer)
        else:
            length_list.append(k)
        return max(length_list)