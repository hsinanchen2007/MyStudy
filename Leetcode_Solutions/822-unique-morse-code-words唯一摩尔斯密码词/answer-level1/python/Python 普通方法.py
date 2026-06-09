class Solution(object):
    def uniqueMorseRepresentations(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        code = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        alpha =['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
        d = {}
        for i in range(26):
            d[alpha[i]] = code[i]
        result = []
        for i in words:
            temp = ''
            for j in i:
                temp += d[j]
            result.append(temp)

        cnt = 0
        for i in range(len(result)):
            if result[i] not in result[i+1:]:
                cnt += 1
        return cnt