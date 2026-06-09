### 解题思路
![image.png](https://pic.leetcode-cn.com/1aeb9e9af423ddac044e5a9466756195410a5cf578767c2db284700a0ef44d59-image.png)

使用python3，运用栈解决。代码有点乱，应该还可以简化。

基本思路：和人看化学式类似，从最内层括号依次展开。用一个数组存储元素种类；一个字典存储元素种类及对应个数。
从前到后遍历一次字符串(用idx记录要访问字符的索引，类似指针)，得出字典的键值对，然后排序。
定义一个栈，栈中元素形如[元素名称, 左括号个数, 缓存的元素个数]。左括号个数类似*栈匹配括号问题*。

主要思想：左括号数是为了记录原子的级别，同一级别的在一个括号里。退栈的时候只用改变括号级别，并乘以对应的倍数
遍历流程：
1. 遇到左括号，则括号级别加1。判断下一个字符。
2. 遇到有括号，则说明一对括号配对成功。找到')'括号后面的倍数；然后依次'退栈'，将栈中同括号级别的原子个数乘以倍数。再改变括号级数
3. 遇到大写字母，则指针后移，直到找到一个元素。判断下一个字符
4. 再指针后移找该原子的个数num
5. 倘若该元素第一次出现，则入列表。
    - 再判断该原子是否在括号中，若不在则直接将原子和对应数字num存入字典
    - 若在括号中，则将[原子名, 括号级别, 数字num]入栈。
6. 若该元素已经出现过
    - 如果此时的原子不在括号中，则字典里对应原子的数量直接加上num
    - 否则按照栈元素形式，入栈。


### 代码

```python3
class Solution:
    def find_num(self, formula:str, idx:int):
        '''
        从idx开始，找到'\d*'
        :param formula: 字符串
        :param idx: 开始判断的索引
        :return: num, 最后一个数字字符的索引
        '''
        num = 0
        while idx<len(formula) and formula[idx].isdigit():
            num = num * 10 + int(formula[idx])
            idx += 1
        # 如果没有数字，则说明该原子个数为1
        if num == 0:
            num = 1
        return num, idx-1


    def countOfAtoms(self, formula: str) -> str:
        idx = 0 # 化学式索引
        length = len(formula)
        atoms = [] # 存储原子的列表
        dic = {} # 记录原子及个数的字典

        left_parentheses_count = 0 # 括号个数
        stack = [] # 当有括号时，就要入栈

        while idx < length:
            # print(f'{idx}\t{formula[idx]}\nleft:{left_parentheses_count}\t'
            #       f'{atoms}\n{dic}\n{stack}\n')

            # 当当前字符是'('时，左括号数加1。判断下一个字符
            if formula[idx] == '(':
                left_parentheses_count += 1
                idx += 1
                continue
            # 当当前字符是')'时，则要将栈中的括号级数减1，并乘以倍数
            elif formula[idx] == ')':
                mult, idx = self.find_num(formula, idx+1)

                # 记录栈中待改变的原子的索引
                k_index = len(stack)
                while k_index > 0:
                    if stack[k_index-1][1] == left_parentheses_count:
                        if left_parentheses_count > 1:
                            stack[k_index-1][1] = left_parentheses_count-1
                            stack[k_index-1][2] *= mult
                        # 如果只有一对括号，就要退栈，并且要加上括号之外的个数
                        else:
                            st_atom, _, st_count = stack.pop(-1)
                            dic[st_atom] += (mult * st_count)
                        k_index -= 1
                    else:
                        break
                left_parentheses_count -= 1 # 括号数减1
                idx += 1 # 索引加1，判断下一字符
                continue

            atom = ''
            # 找到一个元素
            if formula[idx].isupper():
                atom = formula[idx]
            while idx+1 < length and formula[idx+1].islower():
                idx += 1
                atom += formula[idx]
            idx += 1 # idx是下一个要判断的字符索引

            if atom != '':
                if atom not in atoms:
                    atoms.append(atom)

                num, idx = self.find_num(formula, idx)
                idx += 1

                if left_parentheses_count>0:
                    stack.append([atom, left_parentheses_count, num])
                if atom not in dic.keys():
                    if left_parentheses_count == 0:
                        dic[atom] = num if num!=0 else 1
                    else:
                        dic[atom] = 0
                else:
                    if left_parentheses_count == 0:
                        dic[atom] += num

        # print(f'atoms = {atoms}\ndic = {dic}')
        atoms.sort()
        res = ''
        for i in atoms:
            res += i
            res += str(dic[i]) if dic[i]!=1 else ''

        return res
```