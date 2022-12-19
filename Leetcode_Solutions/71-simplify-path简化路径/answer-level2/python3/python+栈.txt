    class Solution(object):
        def simplifyPath(self, path):
            """
            :type path: str
            :rtype: str
            """
            stack = []
            # 将path以'/'分割开，形成一个字符串list
            path = [p for p in path.split('/')]
            # 例如path = '/home/.././a/',则分割后为['','home','..','.','a','']
            for f in path:
                # list中所有字符串的可能为'','.','..'以及其他正常路径名，接下来的逻辑就很清楚了
                if f == '.' or f == '':
                    continue
                elif f == '..':
                    if stack:
                        stack.pop()
                else:
                    stack.append(f)
    
            return '/' + '/'.join(stack)
