### 解题思路
此处撰写解题思路
一步步保存已有的钥匙、箱子，暴力判断能否解开任意一个箱子，能就更新数据，否则返回当前已有糖果
### 代码

```python3
class Solution:
    def maxCandies(self, status: List[int], candies: List[int], keys: List[List[int]], containedBoxes: List[List[int]], initialBoxes: List[int]) -> int:
        if not initialBoxes:
            return 0
        has_keys = set() # 拥有的钥匙
        has_boxes = initialBoxes # 拥有的箱子
        has_candies = 0 # 拥有的糖果
        has_open = [] # 已开的箱子
        while True:
            can_open = []
            for i in has_boxes: # 暴力找到可以开的箱子
                if status[i] == 1 or i in has_keys:
                    can_open.append(i)
            if not len(can_open):
                break
            for box in can_open:
                has_candies += candies[box]
                has_open.append(box) # 打开的箱子加一
                has_boxes.extend(containedBoxes[box]) # 获得新箱子
                has_boxes = list(set(has_boxes) - set(has_open)) # 判断已有箱子与打开的箱子是否重复，取差集
                has_keys = set.union(has_keys, set(keys[box])) # 更新已有钥匙
        return has_candies
```