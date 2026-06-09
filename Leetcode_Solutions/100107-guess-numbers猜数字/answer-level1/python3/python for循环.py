class Solution:
    def game(self, guess: List[int], answer: List[int]) -> int:
        a = 0
        for i in range(3):
            if(guess[i] == answer[i]):
                a+=1
            else:
                a
        return a