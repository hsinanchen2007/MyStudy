```Python
class Solution:
    def maxCandies(self,
                   status,
                   candies,
                   keys,
                   containedBoxes,
                   initialBoxes) -> int:

        queue = list()
        list_box = list()
        used = list()
        for index in initialBoxes:
            if status[index]:
                queue.append(index)
            else:
                list_box.append(index)
        keyss = list()
        cnt = 0
        while len(queue) != 0:
            box_index = queue.pop(0)
            used.append(box_index)
            keyss += keys[box_index]
            cnt += candies[box_index]
            list_box += containedBoxes[box_index]
            for i, index in enumerate(list_box):
                if index not in used:
                    if status[index] or index in keyss:
                        queue.append(index)
                        list_box.pop(i)
        return cnt
```
