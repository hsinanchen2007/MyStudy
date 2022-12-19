```
class Solution:
    def restoreIpAddresses(self, s: str):
        if s.__len__() < 4:
            return []

        # next_pos = [1, 2, 3]
        next_pos = [0,1, 2]
        now_step = 1  # 第几个节点
        now_str = s[0]  # 当前字符
        now_end = 0
        # now_end=0 #当前最终index
        list1=[]
        list1 = [(now_step, now_str + '.', now_end)]
        if s.__len__()>=2:
            tmp_str=s[0:1+1]
            if str(int(tmp_str)) == tmp_str and int(tmp_str)>=0 and int(tmp_str)<=255:
                list1.append((now_step, s[0:1+1] + '.', 1))
        if s.__len__()>=3:
            tmp_str=s[0:2+1]
            if str(int(tmp_str)) == tmp_str and int(tmp_str)>=0 and int(tmp_str)<=255:
                list1.append((now_step, s[0:2+1] + '.', 2))

        rs = []
        while list1:
            now_step, now_str, now_end = list1.pop(0)
            if now_step == 4:
                tmp = now_str[:-1]
                if tmp.replace('.', '').__len__() == s.__len__():
                    rs.append(tmp)
                else:
                    continue

            for i in next_pos:
                if now_end + 1 >= s.__len__() or now_end + 1 + i >= s.__len__():
                    continue
                tmp_str=s[now_end + 1:now_end + 1 + i+1 ]
                if int(tmp_str)<0 or int(tmp_str)>255:
                    continue
                if str(int(tmp_str))!=tmp_str:
                    continue
                next_str = now_str + tmp_str + '.'  #next注意点；s[1:1+1]约定
                next_step =now_step+ 1
                next_end = now_end + 1 + i
                left = s.__len__() - now_end
                if left < (4 - now_step):
                    continue

                list1.append((next_step, next_str, next_end))
        return rs
```