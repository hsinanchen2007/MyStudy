Py3 双100%， 读题读到我都快不认识猜字了
```python
class Solution:
    def masterMind(self, solution: str, guess: str) -> List[int]:
        hash_sol = {"R":0, "Y":0, "G":0, "B":0}
        hash_gue = {"R":0, "Y":0, "G":0, "B":0}
        sum_1 = 0
        sum_2 = 0
        for i in range(4):
            if solution[i] == guess[i]:
                sum_1 += 1
            
            hash_sol[solution[i]] += 1
            hash_gue[guess[i]] += 1

        for i in ["R", "G", "B", "Y"]:
            sum_2 += min(hash_sol[i], hash_gue[i])

        return [sum_1, sum_2 - sum_1]
```
