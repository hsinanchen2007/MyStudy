class Solution(object):
    def game(self, guess, answer):
        """
        :type guess: List[int]
        :type answer: List[int]
        :rtype: int
        """
        sum = 0
        for i in range(len(guess)):
            
            
            if guess[i]==answer[i]:

               sum=sum+1
            else:
                pass
        return sum