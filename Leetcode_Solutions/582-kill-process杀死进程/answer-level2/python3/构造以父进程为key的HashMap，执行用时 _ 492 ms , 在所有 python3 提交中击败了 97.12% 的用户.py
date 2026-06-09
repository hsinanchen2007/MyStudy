```
class Solution:
    def killProcess(self, pid: List[int], ppid: List[int], kill: int) -> List[int]:
        pidl = len(pid)
        ppidl = len(ppid)
        if pidl != ppidl and pidl and ppidl :
            return None
        
        node_dict = {}
        result = []
        for i in range(pidl) :
            node_dict.setdefault(ppid[i], []).append(i)     #添加的value为其子进程在pid中的index
        try :
            curr = pid.index(kill)
        except :
            return pid
        self.kill(curr, pid, node_dict, result)
        return result

    
    def kill(self, curr: int, pid: List[int], node_dict, result) :
        result.append(pid[curr])
        if node_dict.get(pid[curr]) :
            for i in node_dict.get(pid[curr]) :
                self.kill(i, pid, node_dict, result)
```