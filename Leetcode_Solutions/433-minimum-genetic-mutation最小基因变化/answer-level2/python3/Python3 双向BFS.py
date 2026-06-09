除去BFS和DFS还可以使用双向BFS，分别从start和end扩散，每次扩散长度小的，如果相遇了则找到变化次数。和普通BFS类似：）

#### 代码
```python3
class Solution:
    def minMutation(self, start: str, end: str, bank: List[str]) -> int:
        bank = set(bank)
        if end not in bank:
            return -1
        
        dictionary = {"A":"CGT", "C":"AGT", "G":"ACT", "T":"ACG"}
        front_queue = {start}
        end_queue = {end}
        step = 0

        while front_queue:
            step += 1
            next_front = set()

            for word in front_queue:
                for i in range(len(word)):
                    for c in dictionary.get(word[i]):
                        new_word = word[:i] + c + word[i+1:]
                        if new_word in end_queue: # 相遇
                            return step
                        if new_word in bank:
                            next_front.add(new_word)
                            bank.remove(new_word)

            front_queue = next_front

            if len(end_queue) < len(front_queue):
                front_queue, end_queue = end_queue, front_queue
        
        return -1
```
