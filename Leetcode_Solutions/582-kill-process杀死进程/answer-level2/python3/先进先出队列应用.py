### 解题思路
1、首先将父节点和子节点的关系用字典存储起来
2、利用先进先出的栈结构，不断的将节点出队，并将其子节点入队，直到队列为空。

### 代码

```python3

from queue import Queue

class Solution:

    def killProcess(self, pid: List[int], ppid: List[int], kill: int) -> List[int]:

        dic_pid = self.create_dic(pid, ppid)
        ppid_queue = Queue(0)
        ppid_queue.put(kill)
        result = []
        while not ppid_queue.empty():

            # 将父节点压入栈
            temp_pid = ppid_queue.get(kill)
            result.append(temp_pid)

            # 获取父节点的子节点,并将子节点入队
            if temp_pid in dic_pid:
                pid_list = dic_pid.get(temp_pid)

                # 将子节点入队
                for pid in pid_list:
                    ppid_queue.put(pid)
        return result

    def create_dic(self, pid, ppid):
        dic = {}
        for i, j in enumerate(ppid):
            if j not in dic:
                dic[j] = [pid[i]]
            else:
                dic[j].append(pid[i])
        return dic
```