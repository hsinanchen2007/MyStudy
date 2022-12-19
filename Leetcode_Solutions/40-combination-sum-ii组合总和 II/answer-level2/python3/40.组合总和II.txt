和39题一样的思想，不同的是候选集会改变，需要传递去掉选择元素之后的候选集，剪枝是门学问啊
```
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        # 加法回溯
        res = []
        def backtrack(choseList,canList):
            sum_num = sum(choseList)
            if sum_num == target:
                choseList.sort()
                if choseList not in res:
                    res.append(choseList)
                return 0
            elif sum_num > target:
                return 0
            else:
                for i in range(len(canList)):
                    # 剪枝
                    if canList[i] > target-sum_num:
                        pass
                    else:
                        # try 是为了保证i是最后一位数
                        try:
                            backtrack(choseList+[canList[i]],canList[:i]+canList[i+1:])
                        except:
                            backtrack(choseList+[canList[i]],canList[:i])

        
        backtrack([],candidates)
        return res

        # 减法回溯
        res = []
        def backtrack(choseList,canList,target):
            sum_num = sum(choseList)
            canList.sort()
            
            # 终止条件
            if target == 0:
                choseList.sort()
                if choseList not in res:
                    res.append(choseList)
                return 0

            # 候选集为空
            if len(canList)==0:
                return 0
            
            # 剪枝
            if target < canList[0]:
                return 0
            else:
                for i in range(len(canList)):
                    # try是为了保证i是最后一个元素
                    try:
                        backtrack(choseList+[canList[i]],canList[:i]+canList[i+1:],target-canList[i])
                    except:
                        backtrack(choseList+[canList[i]],canList[:i],target-canList[i])

        
        backtrack([],candidates,target)
        return res
```
![image.png](https://pic.leetcode-cn.com/b4632640f5939ae9a5a66a694df5ac6ed15e2b49193e9baada21d45ef6b7c882-image.png)

