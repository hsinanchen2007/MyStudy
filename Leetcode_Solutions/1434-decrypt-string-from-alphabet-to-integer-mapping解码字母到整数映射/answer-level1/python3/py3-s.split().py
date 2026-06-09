class Solution:
    def freqAlphabets(self, s: str) -> str:
        ls = s.split('#')
        lt = []
        for i in ls:
            if len(i)>0:
                lt = lt + [i]
        r = ''
        st = '0abcdefghijklmnopqrstuvwxyz'
        if len(ls)==1:
            for i in ls[0]:
                r = r + st[int(i)]
            print(r)
            return r
        elif int(len(ls)==2) & int(s[-1]=='#'):
            if len(ls[0])<3:
                r = r + st[int(ls[0])]
            if len(ls[0])>2:
                for j in ls[0][0:len(ls[0])-2]:
                    r = r + st[int(j)]
                c = ls[0][len(ls[0])-2]+ls[0][len(ls[0])-1]
                r = r + st[int(c)]
            print(r)
            return r
        else:
            if s[-1]=='#':
                for i in lt[::]:
                    if len(i)<3:
                        r = r + st[int(i)]
                    if len(i)>2:
                        for j in i[0:len(i)-2]:
                            r=r+st[int(j)]
                        c = i[len(i)-2]+i[len(i)-1]
                        r = r + st[int(c)]
                print(r)
                return r
            if s[-1]!='#':
                for i in lt[0:-1]:
                    if len(i)<3:
                        r = r + st[int(i)]
                    if len(i)>2:
                        for j in i[0:len(i)-2]:
                            r = r + st[int(j)]
                        c = i[len(i)-2]+i[len(i)-1]
                        r = r + st[int(c)]
                for m in lt[-1]:
                    r = r + st[int(m)]
                print(r)
                return r