class Solution:
    def judgeCircle(self, moves: str) -> bool:
        varR = varL = varU = varD = 0
        for i in range(len(moves)):
            if moves[i] == 'R':
                varR += 1
            elif moves[i] == 'L':
                varL += 1
            elif moves[i] == 'U':
                varU += 1
            else:
                varD += 1
        if varR == varL and varU == varD:
            return True
        else:
            return False
