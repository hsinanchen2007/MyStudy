        # tell whether str1 and str2 have common string
        if str1+str2!=str2+str1:
            return ''

        # find the greatest common divisor of strings
        n1, n2= len(str1), len(str2)
        m = max(n1,n2)
        n = min(n1,n2)
        while (m%n!=0):
            res = m%n
            m = n
            n = res

        return str(str1[:n])