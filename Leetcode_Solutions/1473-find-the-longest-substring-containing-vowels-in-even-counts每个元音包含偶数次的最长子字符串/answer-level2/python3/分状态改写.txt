### 解题思路
模仿人家的思路，自己写了段python代码，还是很简单的。
### 代码

```python3
class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        list_vowel = ['a', 'e', 'i', 'o', 'u']
        def num2state(num, list_vowel):
            # list_vowel = ['a', 'e', 'i', 'o', 'u']
            ind = 4
            re = {'a':0, 'e':0, 'i':0, 'o':0, 'u':0}
            while num:
                re[list_vowel[ind]] = num%2
                num = int(num/2)
                ind -= 1
            return re
        
        def state2num(m, list_vowel):
            # list_vowel = ['a', 'e', 'i', 'o', 'u']
            re = 0
            for i in range(5):
                re = re*2 + m[list_vowel[i]]
            return re
        # print((not 1)*2)
        state_list = [0]*len(s)
        state = {}
        for i in range(pow(2, 5)):
            state[i] = []
        state[0] = [-1]#init the empty str        
        for i, v in enumerate(s):
            if v in list_vowel:
                tmp_state = num2state(state_list[i-1], list_vowel)
                tmp_state[v] = not tmp_state[v]
                state_list[i] = state2num(tmp_state, list_vowel)
            else :
                state_list[i] = state_list[i-1]
            state[state_list[i]].append(i)
        
        start = 0
        end = 0
        # print(state)

        for k, v in state.items():
            if v:
                if v[-1] - v[0]> end-start:
                    start = v[0]
                    end = v[-1]
                    # print(k, start, end)
        return end - start

```