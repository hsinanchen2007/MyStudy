### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        # 排排坐 分糖果
        if candies <= 0:
            return []
        cur = 1
        remaind = candies
        index = 0
        answer = []
        for _ in range(num_people):
            if remaind > cur:
                answer.append(cur)
            else:
                answer.append(remaind)
                for _ in range(num_people - len(answer)):
                    answer.append(0)
                return answer
            remaind -= cur
            cur += 1
        # 接下来就是累加了 还是别用什么高级的东西了！
        while remaind > 0:
            if index == num_people:
                index = 0
            if remaind >= cur:
                answer[index] += cur
            else:
                answer[index] += remaind
                return answer
            remaind -= cur
            cur += 1
            index += 1
        for _ in range(num_people - len(answer)):
            answer.append(0)
        return answer

```