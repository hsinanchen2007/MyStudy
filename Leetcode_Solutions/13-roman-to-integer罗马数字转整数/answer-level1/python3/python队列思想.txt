# 解题思路：
罗马数字转整数只有两种表示方式，要么一个字母转换为整数，要么两个字母合起来转换为整数。
使用一个队列来判断是否有组合字母：
- 遍历罗马数字字符串：
    1. 当队列中没有元素时，往队列中push元素；
    2. 当队列中有一个元素时，先往队列中push一个元素，再判断这两个元素是否能组成组合字母：
        1. 若能组成组合字母，将对应的整数值做累加处理，清空队列；
        2. 若无法组成组合字母，将队首元素弹出，并在弹出时将对应的整数值做累加处理。
- 最后可能会出现有一个元素留在队列中，因为s中倒数第二个字符和倒数第三个字符可能组成组合字母，因此需判断队列中是否有遗留元素，若是，将其弹出，并在弹出时将对应的整数值做累加处理。


```python
class Solution:
    def romanToInt(self, s: str) -> int:
        ans = 0
        hash_map = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000,
                    'IV': 4, 'IX': 9, 'XL': 40, 'XC': 90, 'CD': 400, 'CM': 900}
        queue = []

        for c in s:
            if not queue:
                queue.append(c)
            else:
                queue.append(c)
                if queue[0] + queue[1] in hash_map:
                    ans += hash_map.get(queue[0] + queue[1])
                    queue.clear()
                else:
                    ans += hash_map.get(queue.pop(0))

        if queue:
            ans += hash_map.get(queue.pop(0))
        return ans
```