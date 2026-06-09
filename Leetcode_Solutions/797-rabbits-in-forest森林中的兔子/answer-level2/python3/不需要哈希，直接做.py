```Python
class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        answers.sort()
        total = 0
        while answers:
            x = answers.pop(0)
            this_color = x + 1
            total += this_color
            while answers and x==answers[0] and this_color>1:
                this_color -= 1
                answers.pop(0)
        return total