class Solution(object):
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        return True if moves.count('U') == moves.count('D') and moves.count('L') == moves.count('R') else False