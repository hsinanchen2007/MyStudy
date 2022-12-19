### 解题思路
用hashmap存储结果，注意题目说的满足题意的最少的兔子

### 代码

```python3
class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        if len(answers)==0:
            return 0
        hashmap ={}
        count = 0
        for i in range(len(answers)):
            if answers[i] not in hashmap:
                hashmap[answers[i]]=1
            else:
                hashmap[answers[i]]+=1
        print(hashmap)
        for i in hashmap.keys():
            count += (hashmap[i]//(i+1))*(i+1)
            if hashmap[i]%(i+1)!=0:
                count += i+1

        return count
```