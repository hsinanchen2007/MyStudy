class Solution:
    def addBinary(self, a,b):
        res = []
        dict = {'0': 0, '1': 1}
        flag = 0
        res1 = []
        res2 = []
        cmp = ""
        if len(a) > len(b):
            for i in range(0, len(a) - len(b)):
                res1.append('0')
            cmp = "".join(res1)
            b = cmp + b
        if len(a) < len(b):
            for i in range(0, len(b) - len(a)):
                res1.append('0')
            cmp = "".join(res1)
            a = cmp + a
        for i in range(max(len(a), len(b)) - 1, -1, -1):
            if dict[a[i]] == 1 and dict[b[i]] == 1:
                cur_num = 0 + flag
                res2.append(str(cur_num))
                flag = 1
                continue
            if dict[a[i]] == 0 and dict[b[i]] == 0:
                cur_num = 0 + flag
                res2.append(str(cur_num))
                flag = 0
                continue
            if (dict[a[i]] + dict[b[i]]) == 1:
                cur_num = 1 + flag
                if cur_num == 2:
                    res2.append('0')
                    flag == 1
                if cur_num == 1:
                    res2.append('1')
                    flag = 0
                continue
        res2.reverse()
        if flag == 1:
            return "1" + "".join(res2)
        else:
            return "".join(res2)