        i, L= -1, 0
        flag = True
        try:
            while 1:
                if s[i]!=' ':
                    L += 1
                    flag = False
                if s[i]==' ' and flag:
                    i -= 1
                    continue
                elif s[i]==' ' and not flag:
                    break
                i -= 1
        except:
            return L
        return L