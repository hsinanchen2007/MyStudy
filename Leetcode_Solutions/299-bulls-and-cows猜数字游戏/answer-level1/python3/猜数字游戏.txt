### 解题思路
我的思路：这题饶了很多圈子，但还是做出来了嘿嘿，不费我千辛万苦。。。首先是判断A的个数,并用字典dicts记录secret的各个数;然后判断B时,排除掉A匹配的下标,遍历guess判断是否不是A的下标且是否数在secret中,匹配的就把dicts中键的值-1,若为0则删除.
	

复杂度分析：
	• 时间复杂度：o(N)                          
	• 空间复杂度：o(N)



### 代码

```python3
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        count_A = 0
        k_dict = {}
        secret = list(secret)
        guess = list(guess)

        for i in range(len(secret)):
            if secret[i] == guess[i]:
                count_A += 1
                k_dict[i] = 1
                secret[i] = -1
        dicts = {} # 得到secret
        for x in secret:
            if x not in dicts:
                dicts[x] = 1
            else:
                dicts[x] += 1

        count_B = 0
        for i in range(len(guess)):
            if i not in k_dict and guess[i] in dicts:
                count_B += 1
                dicts[guess[i]] -= 1
                if dicts[guess[i]] == 0:
                    del dicts[guess[i]]

        result = ''
        result += str(count_A)+'A'+str(count_B)+'B'
        return result
```