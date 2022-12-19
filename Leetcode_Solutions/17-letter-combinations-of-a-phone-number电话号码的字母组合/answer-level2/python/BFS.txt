对于这种全排列的题，其实DFS、BFS和所谓的暴力时间空间复杂度都是一样的。

class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if not digits:
            return []
        m = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }
        res = []
        for d in digits:
            new_res = []
            if not res:
                new_res = [c for c in m[d]]
            else:
                while res:
                    cur = res.pop()
                    for c in m[d]:
                        new_res.append(cur + c)
            res = new_res

        return res