```
class Solution(object):
    def removeComments(self, source):
        """
        :type source: List[str]
        :rtype: List[str]
        """
        dest = []
        st = 'cd'
        s = ''
        part = ''
        for s in source:
            while s:
                if st == 'cd':
                    j = s.find('//')
                    i = s.find('/*')
                    if i>=0 and j>=0:
                        if i<j:
                            j = -1
                        else:
                            i = -1
                    if j>=0:
                        if j>0:
                            dest.append(s[:j])
                    elif i>=0:
                        st = 'mc'
                        e = s.find('*/', i+2)
                        if e>0:
                            st = 'cd'
                            if i>0 or e+1<len(s)-1:
                                s = s[:i]+s[e+2:]
                                continue
                        else:
                            part = s[:i]
                    else:
                        dest.append(s)
                elif st == 'mc':
                    e = s.find('*/')
                    if e>=0:
                        st = 'cd'
                        if part or e+1<len(s)-1:
                            s = part + s[e+2:]
                            part = ''
                            continue
                break
        return dest

```
