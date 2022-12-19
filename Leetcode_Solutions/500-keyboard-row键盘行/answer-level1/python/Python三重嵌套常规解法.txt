class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        l=['QWERTYUIOPqwertyuiop','ASDFGHJKLasdfghjkl','ZXCVBNMzxcvbnm']
        s=[]
        for i in words:
            m=0
            u=0
            p=0
            for j in i:
                for f in l[0]:
                    if j ==f:
                        m=m+1
                        break
                for r in l[1]:
                    if j ==r:
                        u=u+1
                        break
                for e in l[2]:
                    if j ==e:
                        p=p+1
                        break
            if m==len(i)or p==len(i) or u==len(i):
                s.append(i)
        return s