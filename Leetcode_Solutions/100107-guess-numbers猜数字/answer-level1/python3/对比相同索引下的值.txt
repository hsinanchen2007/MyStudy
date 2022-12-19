### 解题思路
此处撰写解题思路
1.根据题意，guess的长度等于answer的长度
2.直接利用他们的相同索引下的值进行对比，相等则count+1

### 代码

```python3
class Solution:
    def game(self, guess: List[int], answer: List[int]) -> int:
        count=0
        for i in range(len(guess)):
            print(i)
            if guess[i]==answer[i]:
                count+=1
        return count
```