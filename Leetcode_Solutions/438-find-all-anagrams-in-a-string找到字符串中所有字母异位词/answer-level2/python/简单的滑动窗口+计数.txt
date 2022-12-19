        def func(s, p):
            ans = []
            lenp = len(p)
            count = [0] * 26
            for i in p:
                count[ord(i)-ord('a')] += 1

            print(count)
            tmp_c = [0] * 26
            l = 0
            r = 0
            while r < len(s):
                idx = ord(s[r]) - ord('a')
                if count[idx] == 0:
                    l = r + 1
                    r += 1
                    tmp_c = [0] * 26
                    continue
                tmp_c[idx] += 1
        
                if tmp_c[idx] > count[idx]:
                    while s[l] != s[r]:
                        tmp_c[ord(s[l]) - ord('a')] -= 1
                        l += 1
                    tmp_c[ord(s[l]) - ord('a')] -= 1
                    l += 1
            
                if r-l+1 == len(p) and s[l:r+1] != p:
                    ans.append(l)
                r += 1
            return ans