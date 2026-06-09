任何的序列均可以通过一个简单的赋值语句解压并赋值给多个变量，唯一的前提是变量的数量必须跟序列中元素的数量一致

class Solution(object):
    def game(self, guess, answer):
        """
        :type guess: List[int]
        :type answer: List[int]
        :rtype: int
        """
        g_one, g_two, g_three = guess
        a_one, a_two, a_three = answer
        return int(g_one==a_one) + int(g_two==a_two) + int(g_three==a_three)
