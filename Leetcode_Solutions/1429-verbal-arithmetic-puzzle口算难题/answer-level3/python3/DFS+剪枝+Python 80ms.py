看了下题解都很少提到剪枝，其他语言即使不剪枝也可以通过，然而试了下Python就直接超时了:(

比赛时提交的代码稍作优化，现在可以达到80ms：
![执行结果.png](https://pic.leetcode-cn.com/e420a422f6ff3e4b8f6324d25a2d7e7cb259c09b202deb149af10c52c2bebb71-%E6%89%A7%E8%A1%8C%E7%BB%93%E6%9E%9C.png)

### 解题思路

1. 对words和result的单词进行按位统计，得到左右式的字母计算公式，目标为两式相减为0
2. 从大系数的字母开始，通过DFS进行搜索
3. 在搜索时进行剪枝，判断当前状态是否有可能形成可行解，如果不可能，则不再往下搜索。判断方式为：目前可用的最大数字(0-9)乘以还没确定数字的所有字母的正系数和，加上当前目标值不能小于0；目前可用的最大数字(0-9)乘以还没确定数字的所有字母的负系数和，加上当前目标值不能大于0
4. 额外：记录了下开头的字母，使其不能为0

### 代码

```python3
class Solution:
    def isSolvable(self, words: List[str], result: str) -> bool:
        from collections import defaultdict
        letter_dict = defaultdict(int)
        not_zero_letter_set = set()
        for word in words:
            not_zero_letter_set.add(word[0])
            for i, letter in enumerate(word[::-1]):
                letter_dict[letter] += 10 ** i
        not_zero_letter_set.add(result[0])
        for i, letter in enumerate(result[::-1]):
            letter_dict[letter] -= 10 ** i
        arr = sorted(letter_dict.values(), key=lambda x: abs(x), reverse=True)
        not_zero_idx_set = {arr.index(letter_dict[letter]) for letter in not_zero_letter_set}

        length = len(arr)
        flag_num = [True] * 10
        def dfs(i, s):
            if i == length:
                if s == 0:
                    return True
                return False
            # 剪枝
            for num in range(10)[::-1]:
                if flag_num[num]:
                    if num * sum([arr[j] for j in range(i, length) if arr[j] > 0]) + s < 0 or \
                        num * sum([arr[j] for j in range(i, length) if arr[j] < 0]) + s > 0:
                        return False
                    break
            for num in range(10)[::-1]:
                if not flag_num[num] or (i in not_zero_idx_set and num == 0):
                    continue
                flag_num[num] = False
                if dfs(i + 1, s + arr[i] * num):
                    return True
                flag_num[num] = True
            return False
        return dfs(0, 0)
```
