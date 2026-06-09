class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        length = len(s)
        asist = [1]*len(s)
        temp = list(s)
        i=1 
        if(length ==0):
            return 0
        while(i < length ):
            store = 0
            for j in range(1,asist[i-1]+1):
                if(temp[i] != temp[i-j]):
                    store += 1
                else:
                    break
            asist[i] += store
            i += 1
        
        max = asist[0]
        for k in range(length):
            if(asist[k] > max):
                max = asist[k]
        return max

        


        
