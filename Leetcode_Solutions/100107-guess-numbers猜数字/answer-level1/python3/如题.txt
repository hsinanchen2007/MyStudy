### 解题思路
此处撰写解题思路

### 代码

```python3
def check(c_list: List[int]):
        eles = [1,2,3]

        if len(c_list) !=3:
            return False

        ex_count = 0
        for e in c_list:
            if eles.count(e) == 0:
                ex_count += 1

        if ex_count == len(c_list):
            return False

        return True
    
    
class Solution:
    
    def game(self, guess: List[int], answer: List[int]) -> int:
        if check(guess) == False:
            return 0
        
        if check(answer) == False:
            return 0
        
        count = 0
        for i in range(0,len(guess)):
            if guess[i] == answer[i]:
                count+=1
        
        return count
    

```