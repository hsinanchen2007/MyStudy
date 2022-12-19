如下，逐个对比即可
class Solution:
    def game(self, guess: List[int], answer: List[int]) -> int:
        a = 0
        i = 0
        for i in range(3):
            if guess[i] == answer[i]:
                a += 1
        return a