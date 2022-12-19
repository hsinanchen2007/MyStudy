```
class Solution:
    def sequence(self, tasks: List[str], n: int):
        # 在task中取出长度问n 的不含重复元素的序列 不满足就用0 来补上
        i = 0
        sub_tasks = []
        while i < len(tasks):
            if len(sub_tasks) == n:
                return sub_tasks
            sub_tasks.append(tasks[i])
            while i + 1 < len(tasks) and tasks[i] == tasks[i + 1]:
                i += 1
            i += 1
        return sub_tasks

    def leastInterval(self, tasks: List[str], n: int) -> int:
        if not tasks:
            return 0
        # 就是滑动窗口
        # 完成所有任务的最短时间取决于出现次数最多的任务数量。! 你说这是不是个点！
        n = n + 1
        tasks = self.sort_by_times(tasks)
        print(tasks)
        tmp = []
        while tasks:
            sub_tasks = self.sequence(tasks, n)
            # print(sub_tasks)
            tmp.append(''.join(sub_tasks))
            for single in sub_tasks:
                if single == '0':
                    break
                tasks.remove(single)
            tasks = self.sort_by_times(tasks)
        # 有点像滑动窗口的问题了...
        tasks_str = ''.join(tmp)

        ans = []
        window = []
        right = 0

        while right < len(tasks_str):
            if len(window) >= n:
                window.pop(0)
            if tasks_str[right] in window and tasks_str[right] != '0':
                ans.append('0')
                window.append('0')
            else:
                window.append(tasks_str[right])
                ans.append(tasks_str[right])
                right += 1
        print(ans)
        return len(ans)

    def sort_by_times(self, tasks) -> str:
        ##完成所有任务的最短时间取决于出现次数最多的任务数量。! 你说这是不是个点！
        dct = {}
        for item in tasks:
            if item in dct:
                dct[item] += 1
            else:
                dct[item] = 1
        dct = sorted(dct.items(), key=lambda x: x[1], reverse=True)
        # 然后在组成字符串返回
        string = []
        for item in dct:
            for _ in range(item[1]):
                string.append(item[0])
        return string
```
