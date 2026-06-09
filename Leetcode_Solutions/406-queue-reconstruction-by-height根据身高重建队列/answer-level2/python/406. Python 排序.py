### 解题思路
[@lammmm](/u/lammmm/) 这位兄弟写的精选题解已经很好了，这里只是给出python实现，以及当做笔记。


（1）先排身高更高的，这是要防止后排入人员影响先排入人员位置
（2）每次排入新人员[h,k]时，已处于队列的人身高都>=h，所以新排入位置就是people[k]

先将people按照身高降序排序，又由于每次插入的位置是k，所以**相同身高需要按k升序排序**，理由我觉得也是防止后排入人员影响先排入人员的位置。
下面同样给出了快排的实现。


### 代码

```python
class Solution(object):
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        if people == []:
            return []

        def quick_sort(left, right):
            if right - left < 0:
                return 
            temp = people[left]
            p, q = left, right
            while p < q:
                while p < q and (people[q][0] < temp[0] or people[q][0] == temp[0] and people[q][1] > temp[1]):
                    q -= 1
                if p < q:
                    people[p] = people[q]
                    p += 1
                while p < q and (people[p][0] > temp[0] or people[p][0] == temp[0] and people[p][1] < temp[1]):
                    p += 1
                if p < q:
                    people[q] = people[p]
                    q -= 1
            people[p] = temp
            quick_sort(left, p - 1)
            quick_sort(p + 1, right)
        length = len(people)
        quick_sort(0, length - 1)
        print(people)
        res = []
        for h, k in people:
            res.insert(k, [h, k])
        return res
```