1. python字符串转数字ord('a')=65  不可直接相减 'a'-'b' 是错误的
```
# class Solution:
#     def countCharacters(self, words: List[str], chars: str) -> int:
        # if not chars:
        #     return 0
        # res = 0
        # memo = {}
        # for char in chars:
        #     if char in memo:
        #         memo[char] += 1
        #     else:
        #         memo[char] = 1
        # import copy
        # for word in words:
        #     mem = copy.deepcopy(memo)
        #     # print(memo)
        #     valid = True
        #     for ch in word:
        #         if ch not in mem or mem[ch] == 0:
        #             valid = False
        #             break
        #         else:
        #             mem[ch] -= 1
        #     if valid:
        #         res += len(word)
        # return res   #13%
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        ans = 0
        if not chars: return ans
        arr = [0]*26
        for char in chars:
            arr[ord(char)-ord('a')] += 1
        
        for word in words:
            newarr = [0]*26
            for ch in word:
                newarr[ord(ch)-ord('a')] += 1
            if all(newarr[i] <= arr[i] for i in range(26)):
                ans += len(word)
        return ans
            

```
