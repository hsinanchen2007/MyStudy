class Solution(object):
    def removeOuterParentheses(self, S):
        """
        :type S: str
        :rtype: str
        """
        a = []
        c = ''
        dict1 = {'(': 0, ')':0}
        for inx, item in enumerate(S):
            if item == '(':
                dict1['('] += 1
            else:
                dict1[')'] += 1
            if dict1['('] == dict1[')']:
                a.append(inx)
        for i in range(len(a)):
            if i == 0:
                b = S[:a[i]+1]
            elif i == len(a)-1:
                b = S[a[i-1]+1:]
            else:
                b = S[a[i-1]+1:a[i]+1]
            b = b[1:-1]
            c = c + b
        return c