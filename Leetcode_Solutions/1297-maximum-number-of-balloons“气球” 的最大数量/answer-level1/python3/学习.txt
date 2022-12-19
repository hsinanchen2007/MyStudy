class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        num_o = 0
        num_a = 0
        num_b = 0
        num_l = 0
        num_n = 0
        for i in range(len(text)):
            if text[i] == 'a':
                num_a += 1
            if text[i] == 'b':
                num_b += 1
            if text[i] == 'l':
                num_l += 1
            if text[i] == 'n':
                num_n += 1
            if text[i] == 'o':
                num_o += 1
        
        return min(num_a, num_b, num_l//2, num_n, num_o//2)
