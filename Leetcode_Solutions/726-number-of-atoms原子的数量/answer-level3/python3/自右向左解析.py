![f62e20fd1f5aa54154e475cc7f2ead3.png](https://pic.leetcode-cn.com/a232948468e7f4921275eb5dcaad6c242e0b132199465f49fd7516d3b30012d8-f62e20fd1f5aa54154e475cc7f2ead3.png)

一 算法分析与设计
定义字符串变量atom_name保存读取的原子名
定义字符串变量tmp_time保存读取的倍数
定义整型变量cur_time保存因当前原子处于多个括号内而需乘的倍数
声明栈st记录依次遇到的各个右括号后的倍数，遇到左括号时退栈
自右向左解析字符串
当遇到数字时，保存数字备用
当遇到右括号")"时，利用tmp_time将右括号后边的倍数入栈，同时更新cur_time=cur_time * int(tmp_time)
当遇到左括号"("时，退栈，并利用退出值将cur_time缩小
当遇到小写字母时，将其保存到atom_name备用
遇到大写字母时，利用atom_name,tmp_time和cur_time更新字典中保存的atom_name的数量
解析完成后，将各原子及其数量合并并将各原子按字典序排列
二 算法实现
```python3 []
class Solution:
    def countOfAtoms(self, formula: str) -> str:    
        result_dict = {}
        atom_name, tmp_time, cur_time, st = "", "", 1, []
        for ch in formula[::-1]:
            if ch.isdigit():
                tmp_time = ch + tmp_time
            elif ch == ")":
                if tmp_time == "":
                    st.append(1)
                else:
                    time = int(tmp_time)
                    tmp_time = ""
                    st.append(time)
                    cur_time *= time
            elif ch == "(":
                cur_time = cur_time // st.pop()
            elif ch.islower():
                atom_name = ch + atom_name
            else:
                atom_name = ch + atom_name
                #update(atom_name, tmp_time, cur_time, result_dict)
                time = 1 if tmp_time == "" else int(tmp_time)
                result_dict[atom_name] = result_dict.setdefault(atom_name, 0) + time * cur_time
                atom_name = ""
                tmp_time = ""
        result = [(atom + ("" if result_dict[atom] == 1 else str(result_dict[atom]))) for atom in sorted(result_dict.keys())]
        return "".join(result)
```
三 复杂度分析
解析字符串时间复杂度为O(N),其中N为字符串长度。对字典中键排序时间复杂度为O(MlogM)，其中M为原子种类数。总的时间复杂度为O(max(N, MlogM))。空间复杂度为O(max(M, L)),L为括号的嵌套层次数。
