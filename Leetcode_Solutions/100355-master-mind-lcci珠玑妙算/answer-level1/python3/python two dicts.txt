### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def masterMind(self, solution: str, guess: str) -> List[int]:
        perfect = 0
        good = 0
        solution_dict={}
        guess_dict={}
        for i in range(len(guess)):
            if solution[i]==guess[i]:
                perfect+=1
            else:
                solution_dict[solution[i]] = solution_dict.get(solution[i],0)+1
                guess_dict[guess[i]] = guess_dict.get(guess[i],0)+1
        for v in guess_dict:
            good+=min(solution_dict.get(v,0),guess_dict.get(v,0))
        return [perfect,good]
```