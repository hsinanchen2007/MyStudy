class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        
        o = text.count("o")
        l = text.count("l")
       
        if l % 2 != 0:
            l -= 1
        if o % 2 != 0:
            o -= 1
        return int(min(0.5 * o , 0.5 * l , text.count("b") , text.count("a") , text.count("n")))