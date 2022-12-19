建议：先看一下精选题解的回溯图解，更容易理解一些。
                                                     
# 优化前
```
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        
        def back_fun(candidates, target):
            if target == 0:  # 递归停止条件
                res.append(path[:])
            for c in candidates:
                residue = target - c
                if residue < 0:  # 提前结束
                    break

                if not path:  # 结果去重
                    path.append(c)
                elif c < path[-1]:  # 下一层的递归用来计算的c值一定要比上一层的大
                    continue  # 因为要从头到尾遍历直到这一层的c值大于上一层，所以这里不能用break和cotinue
                else:
                    path.append(c)
                back_fun(candidates,residue)
                path.remove(c)  # 回溯算法的关键就在这里吧，如果当前层的target小于0了，那就说明该路径是错的，所以就remove一下把当前层的c值删掉(pop()也可以哦)，然后回到上一层。因为是递归，这一层结束就自动回到上一层了的for循环啦，然后用for循环的下一个值继续。

        res = []
        path = []
        candidates.sort()
        back_fun(candidates, target)
        return res
```

# 优化后

哪里可以优化：
```
elif c < path[-1]:  # 下一层的递归用来计算的c值一定要比上一层的大
    continue
```
因为每一层的递归都需要从头到尾遍历candidates，虽然用了continue来跳过它，但是还是浪费时间。

想法：
记录上一层c值的索引，在它的下一层直接遍历candidates中索引比它的部分。

代码：
```
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        
        def back_fun(candidates, target, start=0):
            if target == 0:  # 递归停止条件
                res.append(path[:])
            for idx in range(start, len(candidates)):
                residue = target - candidates[idx]
                if residue < 0:
                    break
                path.append(candidates[idx])
                back_fun(candidates,residue,idx)  # 该层的索引传到下一层作为它for循环的起始点
                path.pop()
        res = []
        path = []
        candidates.sort()
        back_fun(candidates, target)
        return res
```

