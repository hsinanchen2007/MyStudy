本质上是DFS，DFS我们都知道一条path中同一个节点不能出现两次，所以一般都会使用seen或者visited集合来存储之前已经访问过的节点。而该题特殊在**同一层**搜索中，值相同的节点（值相同但节点不一定同，反应到这道题上就是nums中index不同但value相同）只能被选择一次。

比如nums: [1, 2', 2'', 3]
1 -> 2' -> 2'' -> 3
1 -> 2'' -> 2' -> 3
是两条重复的路径，这是因为在第二层搜索中， 2' 和 2'' 虽然是不同节点，但却拥有相同值，不能重复考虑

所以我们需要**两个集合**来排重：
一个是seen，防止同一条path中出现**相同节点**，那么我们用**下标来判断两个节点是否是同一个节点**。由于该集合贯穿整个搜索，所以需要回溯。
另一个是lvlseen，防止同一层搜索中出现**值相同的节点**，那么我们自然就用值来判断两个节点是否拥有相同值。由于该集合每层都有单独创建，每层各自用每层的，所以加入了就不用管了，不用回溯。
```
class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        seen = set()

        def backtrack(path, nums, depth):
            if len(path) == depth:
                res.append(path[:])
                return
            
            lvlseen = set()
            for i in range(len(nums)):
                if i not in seen and nums[i] not in lvlseen:
                    seen.add(i)#prevent the same element
                    lvlseen.add(nums[i])#prevent element with the same value. 
                    path.append(nums[i])
                    backtrack(path, nums, depth)
                    path.pop()
                    seen.remove(i)#needs to be backtracked since seen is used through the whole searching
        
        backtrack([], nums, len(nums))
        return res
    
#seen is to prevent select the totally same element(have the same index in nums) in one path
#lvlseen is to prevent selecting the element with the same value in one searching lvl.
```

回溯问题总结：
1.对于路径顺序不敏感的问题：
比如组合， （1，2） 与 （2，1）是重复的结果，必须传递index来避免倒回去搜索。比如考虑序列[2, 3, 4]的组合， 第一层搜索到2，第二层搜索到3，组合是[2, 3]。第一层如果搜索到3，第二层只能搜索3右边的数字，不能又回去搜索2，形成重复结果[3, 2]

如果原数列有重复数字，就需要先排序再回溯。因为我们传递index的目的就是不要倒回去搜索之前的数字，如果原数列有重复数字且不排序的话，比如[2', 3, 2''], 即使我们传递index， 也会形成[2', 3], [3, 2'']这样的重复结果。所以我们需要先排序，同时要加上lvlseen数组来保证每一层有同样值的数字只会搜索一次。第一层如果选了2', 就不能再选2''， 否则会出现[2', 3], [2'', 3]的重复情况

但这种问题不需要seen数组，因为我们已经通过传递index来避免倒回去搜索了，自然就不可能在一个path中把同一个元素搜索两次。比如[2, 3, 4]， 第一层2 ，第二层只可能是2右边的3或者4， 不可能再是2了，因为index从1开始

2.对于路径顺序敏感的问题：
比如排列， 我们不用传递index，但同时要加一个seen数组来保证同一个path中同一个元素只被搜索一次。

如果有重复数字，也需要加lvlseen数组。比如求[2', 2'', 3]排列， [2', 2'', 3]和[2'', 2', 3]是重复结果。

技巧总结：
路径顺序不敏感：传index
路径顺序不敏感 + 重复数字：传index + 排序 + lvlseen
路径顺序敏感：seen
路径顺序敏感 + 重复数字：seen + lvlseen