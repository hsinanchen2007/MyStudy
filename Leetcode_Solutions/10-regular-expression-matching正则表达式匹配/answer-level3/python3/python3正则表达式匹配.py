### 解题思路
解题思路：
1、将连续的"\*"和".\*"合并为一个；
2、将p按顺序分割为三类字符串：定长、不定长但定字符(a-z*)、完全不定(.\*)；
3、匹配除完全不定之外各项字符串可能匹配的位置并保存起来；
4、判断获得的位置是否能串接起来并以s的长度结尾，若能则返回True，若不能则返回False。
可以优化的地方：
1、部分位置的判断可以用array方式代替list方式以加快运行速度；
2、字典中部分信息可以剔除或者用更简洁的方式表达(比如'flex'、'semiflex'和'not'可以替换为0、1、2)以减少内占用；
3、串接操作可以在每个p的定长子串匹配位置获得之后进行，若能够发现无法连接则可以提前退出减少运行时间。
4、代码可读性略差。
### 代码

```python
class Solution(object):

    # 单字匹配获得匹配地址
    def single_match(self, x, pt, n=0):
        ind_list = []
        for ind,letter in enumerate(x[n:]):
            if letter == pt:
                ind_list.append(ind+n)
        return ind_list
    
    # 后一个字符匹配
    def next_match(self, x, pt, ind_list, n):
        lx = len(x)
        if pt[n] == '.':
            return ind_list
        else:
            ind_list_new = []
            for ind in ind_list:
                if ind+n >= lx:
                    continue
                if x[ind+n] == pt[n]:
                    ind_list_new.append(ind)
            return ind_list_new
    
    # 将连续的*和.*合并为一个
    def clean(self, p):
        while p[0] == '*':
            p = p[1:]
        token = True
        while token:
            try:
                ind = p.index('**')
                p = p[0:ind]+p[ind+1:]
            except ValueError:
                token = False
        token = True
        while token:
            try:
                ind = p.index('.*.*')
                p = p[0:ind]+p[ind+2:]
            except ValueError:
                token = False
        token = True
        while token:
            try:
                ind = p.index('.*')
            except:
                break
            pass_list = [ind]
            while True:
                try:
                    ind = p.index('.*',ind+1)
                    pass_list.append(ind)
                except:
                    break
            if len(pass_list) >= 2:
                for n in range(len(pass_list)-1):
                    tk = True
                    for ind in range(pass_list[n]+2,pass_list[n+1]):
                        if p[ind] != '.':
                            tk = False
                    if tk:
                        p = p[0:pass_list[n]]+p[pass_list[n]+2:]
                        break
                    if n == len(pass_list)-2:
                        token = False
            else:
                token = False
        return p
    
    # 普通匹配
    def match_normal(self, s, pt_dict):
        ln = pt_dict['length']
        pt = pt_dict['pattern']
        n = 0
        all_dot = True
        for m in range(len(pt)):
            if pt[m] != '.':
                all_dot = False
                break
        if all_dot:
            ind_list = [('*',len(pt))]
        else:
            while pt[n] == '.':
                n += 1
            ind_list = []
            passed = n
            ind_list = self.single_match(s,pt[n],n)
            for m in range(ln-n):
                ind_list = self.next_match(s,pt[n:],ind_list,m)
            ind_list = [(x-passed,x-passed+ln) for x in ind_list]
        return ind_list
    
    # 匹配不定长项
    def match_semiflex(self, s, pt_dict):
        pt = pt_dict['pattern']
        ind_list = self.single_match(s,pt[0])
        n = 0
        ind_list = []
        lst_match = -1
        for ind in range(len(s)):
            if s[ind] == pt[n]:
                if lst_match == -1 or ind-lst_match > 1:
                    ind_list.append(ind)
                lst_match = ind
        ind_list_new = []
        for ind in ind_list:
            l = 1
            try:
                while s[ind+l] == pt[n]:
                    l += 1
            except IndexError:
                pass
            ind_list_new.append((ind,ind+l))
        return ind_list_new
    
    # 获得各分割匹配字段可能的匹配位置
    def generate_avaliable_cond(self, s, p):
        compare_list = []
        compare_all = []
        ind = 0
        compare_list = self.single_match(p,'*')
        for ind_n,ind in enumerate(compare_list):
            if ind_n == 0:
                st = 0
            if ind_n == len(compare_list)-1:
                ed = self.lp-1
            m_st = ind-1
            m_ed = ind+1
            if m_st > st:
                compare_all.append(p[st:m_st])
            compare_all.append(p[m_st:m_ed])
            if ind_n == len(compare_list)-1:
                    if m_ed <= ed:
                        compare_all.append(p[m_ed:])
            st = m_ed
        if len(compare_all) == 0:
            compare_all = [p]
                
        compare_all = dict(
            zip(range(len(compare_all)),[{'pattern':x} for x in compare_all])
        )
        for key in compare_all.keys():
            if '.*' in compare_all[key]['pattern']:
                compare_all[key]['flex'] = 'full'
            elif '*' in compare_all[key]['pattern']:
                compare_all[key]['flex'] = 'semi'
            else:
                compare_all[key]['flex'] = 'not'
            compare_all[key]['length'] = len(compare_all[key]['pattern'])

        for key in compare_all.keys():
            if compare_all[key]['flex'] == 'not':
                compare_all[key]['address'] = self.match_normal(s,compare_all[key])
                if len(compare_all[key]['address']) == 0:
                    return False,compare_all
            elif compare_all[key]['flex'] == 'semi':
                compare_all[key]['address'] = self.match_semiflex(s,compare_all[key])
        
        return True,compare_all

    # 主程序
    def isMatch(self, s, p):
        if p == s:
            return True
        elif p == '':
            return False

        self.ls = len(s)
        self.lp = len(p)

        p = self.clean(p)
        self.lp = len(p)

        boo,compare_all = self.generate_avaliable_cond(s, p)
        if boo:
            key = 0
            avaliable_adds = [0]
            while key <= len(compare_all.keys())-1:
                if compare_all[key]['flex'] == 'full':
                    avaliable_adds = list(range(min(avaliable_adds),self.ls+1))
                    key += 1
                else:
                    if compare_all[key]['flex'] == 'semi':
                        adds = []
                        for x in compare_all[key]['address']:
                            for add in avaliable_adds:
                                if add >= x[0] and add < x[1]:
                                    adds = list(set(adds).union(set(range(add,x[1]+1))))
                        avaliable_adds.extend(
                            [x for x in adds if x not in avaliable_adds]
                        )
                        key += 1
                    else:
                        if '*' not in [x[0] for x in compare_all[key]['address']]:
                            avaliable_adds = [x[1] for x in compare_all[key]['address'] if x                                               [0] in avaliable_adds]
                        else:
                            avaliable_adds = [x+compare_all[key]['address'][0][1] for x in                                                 avaliable_adds]
                        key += 1
                if len(avaliable_adds) == 0:
                    return False
            if self.ls in avaliable_adds:
                return True
            else:
                return False
        else:
            return False
```