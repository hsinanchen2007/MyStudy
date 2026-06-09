本来一开始也是想从左到右解析的, 
但是 __从右侧开始解析__ , 解析起来比较简单

1. 遇到数字则为倍数, 需要乘以保留的倍数
2. 如果遇到')', 则保存倍数, 如果遇到'(', 则删除倍数
3. 遇到小写字母代表原子名开头, 遇到大写字母则为原子结束, 更新原子个数

```
class Solution:
    # 更新结果
    def update(self,atom_name,tmp_times,cur_times, result_dit):
        if tmp_times == "":
            tmp_times = 1
        else:
            tmp_times = int(tmp_times)
        num = tmp_times * cur_times
        if atom_name in result_dit:
            result_dit[atom_name] = result_dit[atom_name] + int(num)
        else:
            result_dit[atom_name] = int(num)
        
    def countOfAtoms(self, formula: str) -> str:
        result_dit = {}
        if formula[0] != "(":
            formula = "("+formula+")"
        tmp_atom_name, tmp_times, cur_times, times = "", "", 1, []
        for char in formula[::-1]:#从右边开始, 遇到数字保存倍数, 遇到大写字母,则更新个数
            if char.isdigit():#数值
                tmp_times = char + tmp_times
            elif char == ")":#加倍数
                if tmp_times == "":
                    times.append(1)
                else:
                    times.append(int(tmp_times))
                    tmp_times = ""
                    cur_times = times[-1] * cur_times
            elif char == "(":#减倍数
                cur_times = cur_times / times.pop()
            elif char.islower():#原子名开始
                tmp_atom_name = char + tmp_atom_name
            elif char.isupper():#原子名结束
                tmp_atom_name = char + tmp_atom_name
                self.update(tmp_atom_name,tmp_times,cur_times, result_dit)
                tmp_atom_name, tmp_times = "", ""
        
        result = [ atom_name+("" if result_dit[atom_name] ==1 else str(result_dit[atom_name])) for atom_name in result_dit.keys()]
        result.sort()
        return "".join(result)
```