![image.png](https://pic.leetcode-cn.com/27f04e0315406a76c53695e5a9739ea881ec30eda878bac5707ce9f47bd66c14-image.png)


```

'''
模拟打开盒子过程，直到没有新盒子可以打开为止
'''

from typing import List
class Solution:
    def maxCandies(self, status: List[int], candies: List[int], keys: List[List[int]], containedBoxes: List[List[int]], initialBoxes: List[int]) -> int:
        visible_box = set(initialBoxes)
        key_in_hand = set()
        opened_box = set()

        while True:
            del_box = []
            add_box = []

            flag = False
            for box in visible_box:
                if status[box] == 1:
                    flag = True
                    del_box.append(box)
                    opened_box.add(box)

                    for key in keys[box]:
                        key_in_hand.add(key)

                    for new_box in containedBoxes[box]:
                        add_box.append(new_box)

            if not flag:
                break

            for box in add_box:
                visible_box.add(box)

            for box in del_box:
                visible_box.remove(box)

            for box in visible_box:
                if box in key_in_hand and status[box] == 0:
                    status[box] = 1

        ans = 0
        for box in opened_box:
            ans += candies[box]
        return ans
```
