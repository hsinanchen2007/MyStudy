```python
# 主要是用栈维护当前占用的函数
class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        
        record = {}
        stack = []
        stack1 = []
        pre_time = 0
        for cur in logs:
            #print(stack)
            cur_id,cur_status,cur_time = cur.split(':')
            #print(pre_time,cur_time)
            if cur_status == 'start':
                if stack:
                    record[stack[-1][0]] = record.get(stack[-1][0],0)+int(cur_time)-pre_time
                stack.append((cur_id,cur_time))
            else:
                record[stack[-1][0]] = record.get(stack[-1][0],0)+int(cur_time)-pre_time+1
                while stack[-1][0] != cur_id:
                    stack1.append(stack.pop(-1))
                stack.pop(-1)
                while stack1:
                    stack.append(stack1.pop(-1))
            pre_time = int(cur_time)
            if cur_status == 'end':
                pre_time += 1
            #print(record)
        return [record.get(str(i),0) for i in range(n)]
```