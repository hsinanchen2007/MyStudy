### 解题思路
字典 + 堆栈

### 代码

```python3
class Solution:
    def killProcess(self, pid: List[int], ppid: List[int], kill: int) -> List[int]:
        pid_stack = []
        pid_stack.append(kill)

        remove_pid = []
        ppid_dict = {}
        for idx, value in enumerate(ppid):
            if value in ppid_dict.keys():
                ppid_dict[value].append(idx)
            else:
                ppid_dict[value] = [idx]

        while len(pid_stack) > 0:
            kill_pid = pid_stack.pop()
            remove_pid.append(kill_pid)
            if kill_pid in ppid_dict.keys():
                remove_pid_idx = ppid_dict[kill_pid]
                for _ in remove_pid_idx:
                    pid_stack.append(pid[_])

        return remove_pid
```

执行结果：
通过
显示详情
执行用时 :
516 ms
, 在所有 Python3 提交中击败了
83.33%
的用户
内存消耗 :
19.9 MB
, 在所有 Python3 提交中击败了
68.57%
的用户