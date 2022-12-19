
先看看[工业实现](https://docs.python.org/2/library/itertools.html#itertools.product)：


def product(*args, **kwds):
    # product('ABCD', 'xy') --> Ax Ay Bx By Cx Cy Dx Dy
    # product(range(2), repeat=3) --> 000 001 010 011 100 101 110 111
    pools = map(tuple, args) * kwds.get('repeat', 1)
    result = [[]]
    for pool in pools:
        result = [x+[y] for x in result for y in pool]
    for prod in result:
        yield tuple(prod)

本题的话大约如下：
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if not digits:
            return []
        map = [0, 1, 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
        result = ['']
        final_result = []
        l = len(digits)
        for temp_result in result:
            for w in map[int(digits[len(temp_result)])]:
                product = temp_result + w
                if len(product) == l:
                    final_result.append(product)
                else:
                    result.append(product)
        return final_result