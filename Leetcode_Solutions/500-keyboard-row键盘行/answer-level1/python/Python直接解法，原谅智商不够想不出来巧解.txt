class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        word_dic = {"1":"qwertyuiopQWERTYUIOP", "2":"asdfghjklASDFGHJKL", "3":"zxcvbnmZXCVBNM"}
        count_1 = 0
        count_2 = 0
        count_3 = 0
        word_back = []
        for i in words:
            for j in i:
                if j in word_dic["1"]:
                    count_1 += 1
                elif j in word_dic["2"]:
                    count_2 += 1
                else:
                    count_3 += 1
            if count_1 == len(i) or count_2 == len(i) or count_3 == len(i):
                word_back.append(i)
            count_1 = 0
            count_2 = 0
            count_3 = 0
        return word_back