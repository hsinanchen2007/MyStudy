```
class Solution(object):
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        # 排除异常的边界情况，也限定了模式串的长度
        if len(s1) > len(s2):
            return False
        s1_dic = [0] * 26
        s2_dic = [0] * 26
        window_size = len(s1)
        n  = len(s2)
        # 构建数组字典
        for i in range(window_size):
            s1_dic[ord(s1[i])-ord("a")]+=1
            s2_dic[ord(s2[i])-ord("a")]+=1
        # 开始在窗口滑动
        for i in range(window_size,n):
            if s2_dic == s1_dic:
                return True
            s2_dic[ord(s2[i])-ord("a")] += 1
            s2_dic[ord(s2[i-window_size])-ord("a")] -= 1
        # 最后还有一个窗口没有判断，但是不会进入到for循环里面了
        return s2_dic == s1_dic
        
```
