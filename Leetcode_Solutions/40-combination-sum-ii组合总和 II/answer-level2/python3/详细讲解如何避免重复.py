与上一道题回朔完全相同，差的只是一个如何避免重复的问题

这个避免重复当思想是在是太重要了。
这个方法最重要的作用是，可以让同一层级，不出现相同的元素。但是却允许了不同层级之间的重复            
```
                  1
                 / \
                2   2  这种情况不会发生 
               /     \
              5       5
                例2
                  1
                 /
                2      这种情况确是允许的
               /
              2  
```
为何会有这种神奇的效果呢？
首先 cur-1 == cur 是用于判定当前元素是否和之前元素相同的语句。这个语句就能砍掉例1。可是问题来了，如果把所有当前与之前一个元素相同的都砍掉，那么例二的情况也会消失。 因为当第二个2出现的时候，他就和前一个2相同了。
                
那么如何保留例2呢？
那么就用cur > begin 来避免这种情况，你发现例1中的两个2是处在同一个层级上的，
例2的两个2是处在不同层级上的。在一个for循环中，所有被遍历到的数都是属于一个层级的。我们要让一个层级中，必须出现且只出现一个2，那么就放过第一个出现重复的2，但不放过后面出现的2。第一个出现的2的特点就是 cur == begin. 第二个出现的2 特点是cur > begin.

```


class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        if len(candidates) == 0:
            return []
        path = []
        res = []
        candidates.sort()
        self.__DFS(candidates, target, 0, path, res)
        return res

    def __DFS(self, candidates, target, begin, path, res):
        # 回朔点(递归出口
        path = path.copy()  #如果不先copy，那么append到res中到path也会随着path的变换而变化
        if target == 0:
            res.append(path)
            return

        if begin > len(candidates)-1:
            return

        #回朔入口
        for cur in range(begin, len(candidates)):
            if cur > begin and candidates[cur-1] == candidates[cur]:  #数组常见去重复的方法，对于重复的数值，我们只让第一个进入循环，后面的就不要再进入循环了
                continue
            temp = target - candidates[cur]
            #剪枝
            if temp < 0:
                return
            else:
                path.append(candidates[cur])
                self.__DFS(candidates, temp, cur+1, path, res) #一定是cur+1，
                path.pop()
```
