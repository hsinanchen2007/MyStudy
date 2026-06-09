```
class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """

        # calculate the shift matrix
        def calShiftMatrix(st):
            dic = {}
            slen = len(st)

            for i in range(slen-1, -1, -1):
                if not dic.get(st[i]):
                    dic[st[i]] = slen - i
            dic['ot'] = slen + 1
            
            return dic

        # special cases:
        if len(needle) > len(haystack): return -1
        if needle == "": return 0

        # get shift matrix
        dic = calShiftMatrix(needle)
        idx = 0

        while idx + len(needle) <= len(haystack):
            str_cut = haystack[idx:idx+len(needle)]
            if str_cut == needle:
                return idx
            else:
                if idx+len(needle) >= len(haystack):
                    return -1
                cur_c = haystack[idx+len(needle)]
                if dic.get(cur_c):
                    idx += dic[cur_c]
                else:
                    idx += dic['ot']

        return -1 if idx+len(needle) >= len(haystack) else idx

```
