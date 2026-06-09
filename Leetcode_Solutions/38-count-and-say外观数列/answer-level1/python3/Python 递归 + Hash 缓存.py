```python []
class Solution:
    def countAndSay(self, n: int) -> str:
        hash = {1:1,2:11}
        def say(n):
            if n in hash: return hash[n]
            last = str(say(n-1))
            temp,count,result = last[0],1,""
            for i in range(1,len(last)):
                if last[i] == temp:
                    count+=1
                else:
                    result = result + str(count) + str(temp)
                    temp,count = last[i],1
            result = result + str(count) + str(temp)
            hash[n] = result
            return result
        return str(say(n))
```
思路很简单，速度还行 28ms, 12.8MB, 99.33%, 99.45%，貌似 LeetCode 数据不是太多，所以 Hash 缓存效果不明显？？