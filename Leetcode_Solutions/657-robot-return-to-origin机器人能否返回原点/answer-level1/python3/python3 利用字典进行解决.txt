将上下，左右分别进行对应就行了，存在字典中，UD对应+1，-1，RL对应+2，-2，查看最终得出值是否为0.
class Solution:
    def judgeCircle(self, moves):
        '''

        :param moves: 移动的步数
        :return:
        '''
        check_dict = {
            'u': 1,
            'd': -1,
            'l': 2,
            'r': -2
        }
        result = 0
        for move in moves:
            result += check_dict[move.lower()]
        return result == 0