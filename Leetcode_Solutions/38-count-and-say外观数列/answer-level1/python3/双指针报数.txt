def countAndSay(n: int) -> str:
    l = ["1","11"]
    for i in range(n-2):
        s = l[-1]
        p = 0
        q = 1
        count = 1
        m = ''
        while q < len(s):
            if s[p] == s[q]:
                count += 1
            else:
                m += str(count) + s[p]
                count = 1
                p = q
            if q == len(s) - 1:
                m += str(count) + s[p]
            q += 1
        l.append(m)
    return l[n-1]