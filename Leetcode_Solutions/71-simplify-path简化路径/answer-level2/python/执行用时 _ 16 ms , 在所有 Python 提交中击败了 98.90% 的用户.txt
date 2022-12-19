class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        # 直接以"/"进行分割就能忽略多个"/"连在一起的影响
        list2 = path.split("/")
        res = []
        for i in list2:
            # 分割后可能会出现""
            if i not in ["", ".", ".."]:
                res.append(i)
            elif i == ".." and res:
                res.pop()
        return "/" + "/".join(res)