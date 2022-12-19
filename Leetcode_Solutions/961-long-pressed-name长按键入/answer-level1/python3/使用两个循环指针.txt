class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        """
           核心使用一个指针记录name已经匹配的标志位, 使用typed与name匹配, 如果匹配上
           那么标志位加1， 如果没匹配上, 判断是否与前一个字符相等, 如果相等接着下一个
           循环, 如果都不满足, 那么这个字符在name中就没有, 那么直接返回False
           
           最终基于j与len(name)来判断是否name中所有元素都被匹配了.
          
        """
        
        # 1. 特殊情况处理了
        if len(typed) < len(name):
            return False
        
        # 2. 正式编程
        if typed[0] == name[0]:
            j = 1
        else:
            return False
        
        for i in range(1, len(typed)):
            if j < len(name):
                if typed[i] == name[j]:
                    j += 1
                elif typed[i] == typed[i - 1]:
                    continue
                else:
                    return False
            else:
                if typed[i] == name[j - 1]:
                    continue
                else:
                    return False
        
        if j < len(name):
            return False
        else:
            return True