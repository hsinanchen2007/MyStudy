**本题乍一看比较复杂，需要统计每个字母出现的次数（双指针题目的惯性）**
**但实际上只需要检查typed中是否存在name即可**


        ```
    class Solution(object):
        def isLongPressedName(self, name, typed):
        """
        :type name: str
        :type typed: str
        :rtype: bool
        """
            left=0
            for j in range(len(typed)):
                #遍历typed一次
                if name[left]==typed[j]:
                    left+=1
                if left==len(name):
                    return True
            return False
        ```

