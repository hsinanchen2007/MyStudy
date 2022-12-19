### 解题思路
在准确猜中时，把结果保存到字典里
最后统计伪猜中的次数

如果字符只出现在`guess_map`或只出现在`solution_map`。min返回的结果就是0。
如果字符同时出现在`guess_map`和`solution_map`。min返回的结果就是对于这个字符的伪猜中次数

### 代码

```python
def masterMind(self, solution, guess):
    perfect = 0  # 猜中
    good = 0  # 伪猜中
    solution_map = {}
    guess_map = {}
    for i in range(len(guess)):
        if guess[i] == solution[i]:
            perfect += 1
        else:
            solution_map[solution[i]] = solution_map.get(solution[i], 0) + 1
            guess_map[guess[i]] = guess_map.get(guess[i], 0) + 1

    for a in guess_map:
        good += min(solution_map.get(a, 0), guess_map.get(a, 0))  # 取最小的表示solution 和 guess 元素个数要匹配

    return [perfect, good]
```