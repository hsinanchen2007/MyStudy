### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        #思路：宽搜？
        def caculate_add(num):
            #对某一个数计算它的所有数位和
            ans = 0
            while True:
                a = num // 10 #整数部分
                b = num % 10 #余数部分
                ans += b
                num = a
                if a == 0:
                    break
            return ans        
        deque = collections.deque() #宽搜队列
        memory = {(0,0)} #去过的位置
        deque.append((0,0))
        while deque:
            for _  in range(len(deque)):
                x,y = deque.pop()
                for i,j in [(x-1,y),(x+1,y),(x,y+1),(x,y-1)]:
                    if i >= 0 and i < m and j >= 0 and j < n:
                        if (i,j) not in memory:
                            if caculate_add(i) + caculate_add(j) <= k:
                                memory.add((i,j))
                                deque.appendleft((i,j))
        return len(memory)  

```