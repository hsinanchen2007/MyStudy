### 解题思路
#### 1.理解问题：
    寻找两个list中的共同项，并伴随“索引之和最小”这个约束条件
    一些细节：
        1）每个list都没有重复元素
        2）list长度有限制
        3）结果是个list
#### 2.如何实现：
    官方解题3
    遍历listl建立hashMap，list中的string为key，index为value，然后遍历list2更新ans。
    细节：
        如何正确更新ans：
            index_min改变的时候ans要完全更新
            index_min不变的情况下也有多解的可能性，此时ans中需要插入新的解

### 代码

```python3
class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        checklist = {}
        index_min = 2000
        ans = []
        
        for n in range(len(list1)):
            checklist[list1[n]] = n
        
        for m in range(len(list2)):
            temp = list2[m]
            if temp in checklist:
                if checklist[temp]+m < index_min:
                    index_min = checklist[temp] + m
                    ans = [temp]
                elif checklist[temp]+m == index_min:
                    ans.append(temp)
                else:
                    pass
            else:
                pass
        return ans 
        
```