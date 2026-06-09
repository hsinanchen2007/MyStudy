```
class Solution:
    # 递归回溯 python
    def minMutation(self, start: str, end: str, bank) -> int:
        if end not in bank: return -1
        if not start or not end: return -1

        bank = set(bank)
        change = {
            'A':'GCT',
            'G':'ACT',
            'C':'AGT',
            'T':'AGC'
        }

        def helper(node, count, _bank):
            # terminator
            if node == end: counts.append(count)
            if not _bank: return
            # process 
            for i, s in enumerate(node):
                for c in change[s]:
                    new = node[:i] + c + node[i + 1:]
                    if new in _bank:
                        _bank.remove(new)
                        # drill down 进入下一层的探索
                        helper(new, count + 1, _bank)
                        # reverse state 恢复现场 探索这层的其他分支
                        _bank.add(new)

        counts = []
        helper(start, 0, bank) 
        if not counts: return -1
        else: return min(counts)
```
遍历开始基因的所有可能变化，通过回溯不断探索基因在基因库中变化的可能。
取变化次数最小的值。
p.s 欢迎小伙伴来抛个砖，对个暗号