主要思路就是把图建出来然后拓扑排序即可
用字典存储图，value为指向key的点
暴力比对字符串前缀，找到同前缀的字符顺序，然后加入字典即可
之后进行拓扑排序得出答案
```
def check(same):
    len_same = len(same)
    i = 0
    while i < len_same - 1:
        if same[i] == same[i+1]:
            del same[i+1]
            len_same -= 1
        else:
            i+=1
    if len(set(same)) != len(same):
        return True
    return False

class Solution:
    def alienOrder(self, words: List[str]) -> str:
        dic = dict()
        max_len = 0
        all_w = set()
        for i in words:
            for j in i:
                dic[j] = set()
                all_w.add(j)
            if len(i) > max_len:
                max_len = len(i)

        #建图
        for i in range(max_len):
            last = ''
            same = []
            for j in words:
                if i == 0:
                    same.append(j[0]) 
                else:
                    if last == '':
                        last = j[:i]
                        if i < len(j):
                            same.append(j[i])
                    elif j[:i] == last and i < len(j):
                            same.append(j[i])
                    elif j[:i] != last:
                        while len(same) != 0:
                            if check(same):
                                return ""
                            last_c = same.pop()
                            for ss in same:
                                if last_c != ss:
                                    dic[last_c].add(ss)
                        last = j[:i]
                        same = []
                        if i < len(j):
                            same.append(j[i])
            while len(same) != 0:
                if check(same):
                    return ""
                last_c = same.pop()
                for ss in same:
                    if last_c != ss:
                        dic[last_c].add(ss)

        #拓扑排序
        result = ""
        while True:
            flag_end = True
            have_zero = False
            del_ele = []
            for i in dic.keys():
                if len(dic[i]) == 0:
                    if result.find(i) == -1:
                        result += i
                        del_ele.append(i)
                    have_zero = True
                else:
                    flag_end = False

            if not have_zero:
                break
            for i in del_ele:
                dic.pop(i)
            for key,value in dic.items():
                for j in del_ele:
                    if j in value:
                        dic[key].remove(j)
            del_ele = []
            if flag_end:
                break
                
        return result


        
```
