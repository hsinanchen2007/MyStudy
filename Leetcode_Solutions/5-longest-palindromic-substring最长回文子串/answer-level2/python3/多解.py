一 算法
1 暴力法（3940ms）
2 中间扩展法（700-800ms）
3 中间扩展法+特殊值处理（180ms-200ms）
4 优化中间扩展法(140ms-180ms 85%-90%)
5 优化中间扩展法+ 特殊值处理(60-80ms 99%-100%)
二 python3实现
```
class Solution:
    def longestPalindrome(self, s: str) -> str:
        ## method 1 暴力法
        #n = len(s)
        #if n == 0:
        #    return ""
        #for i in range(n, 0, -1):
        #    for j in range(n-i+1):
        #        sub_str = s[j:j+i]
        #        if sub_str == sub_str[::-1]:
        #            return sub_str
        
        
        ## method3 中间扩展法+特殊值处理
        #def expand_length(L, R):
        #    while L > -1 and R < n and s[L] == s[R]:
        #        L -= 1
        #        R += 1
        #    return R-L-1
        
        #n = len(s)
        ##特殊值处理
        #if n <= 1 or s == s[::-1]:
        #    return s
        #start = 0
        #end = 0
        #for i in range(n):
        #    len1 = expand_length(i, i)
        #    len2 = expand_length(i, i+1)
        #    length = max(len1, len2)
        #    if length > end - start + 1:
        #        start = i - (length - 1 >> 1)
        #        end = i + (length >> 1)
        #return s[start:end+1]
        
        
        # method 5 优化中间扩展法+特殊值处理
        def expand_length(center):
            length = counts[center][1]
            left = center - 1
            right = center + 1
            while left > -1 and right < m:
                if counts[left][0] == counts[right][0]:
                    #if counts[left][1] != counts[right][1]:
                    #    length += (min(counts[left][1], counts[right][1]) << 1)
                    #    break
                    #else:
                    #    length += (counts[left][1] << 1)
                    #    left -= 1
                    #    right += 1
                    left_num, right_num = counts[left][1], counts[right][1]
                    if left_num != right_num:
                        length += min(left_num, right_num) << 1
                        break
                    else:
                        length += left_num << 1
                        left -= 1
                        right += 1
                else:
                    break
            return length


        n = len(s)
        if n <= 1 or s[::-1] == s:
            return s

        counts, count = [], 1
        for i in range(n - 1):
            if s[i] == s[i + 1]:
                count += 1
            else:
                counts.append((s[i], count))
                count = 1
        counts.append((s[-1], count))

        m = len(counts)
        res = 0
        c = -1
        for i in range(m):
            get_len = expand_length(i)
            if get_len > res:
                res = get_len
                c = i
        ss = 0
        for j in range(c):
            ss += counts[j][1]
        per = (res - counts[c][1]) >> 1
        start = ss - per
        return s[start:start + res]
```
