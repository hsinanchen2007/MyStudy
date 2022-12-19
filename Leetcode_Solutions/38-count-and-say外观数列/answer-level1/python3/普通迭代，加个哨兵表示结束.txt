last表示上一次的数据，每次迭代都是解读last的含义；
last加个'#‘哨兵，表示结束，然后输出；省去了最后判断结尾的逻辑；
时间复杂度：O(sum(n之前的数据总长度))
```
class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        last = "1"
        for i in range(n - 1):
            last += '#'
            cur = last[0]
            cnt = 1
            process = ""
            for j in range(1, len(last)):
                if last[j] == last[j - 1]:
                    cnt += 1
                else:
                    process += str(cnt) + cur
                    cur = last[j]
                    cnt = 1
            last = process
        return last
```
