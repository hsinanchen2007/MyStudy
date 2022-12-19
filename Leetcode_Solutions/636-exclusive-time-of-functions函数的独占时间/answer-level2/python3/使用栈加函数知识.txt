```
class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        """
           这里面隐含了： 如果遇到某个end, 那么栈顶元素肯定是同一个id的start操作, 此时将栈顶元素出栈
        """
        from collections import defaultdict
        func_cnt = [0 for _ in range(n)]
        stack = []

        stack.append(int(logs[0].split(":")[0]))
        i = 1
        pre_time = int(logs[0].split(":")[-1])
        while i < len(logs):
            lg_arr = logs[i].split(":")
            if lg_arr[1] == "start":
                # 入栈, 计算当前栈顶的时间, 并且修改pre_time
                if stack:
                    func_cnt[stack[-1]] += int(lg_arr[-1]) - pre_time
                stack.append(int(lg_arr[0]))
                pre_time = int(lg_arr[-1])
            else:
                # 如果是end, 那么之前必然存在同时该id的start, 此时要pop出来
                func_cnt[stack[-1]] += int(lg_arr[-1]) - pre_time + 1
                stack.pop()
                pre_time = int(lg_arr[-1]) + 1
            
            i += 1
        

        return func_cnt
```
