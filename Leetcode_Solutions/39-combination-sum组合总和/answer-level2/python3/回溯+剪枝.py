### 解题思路
（1）常规想法都是循环查找，但是要根据数据中的值组合得到目标的值，循环次数不确定。这种情况下就可以采用递归方法
（2）往往递归是找到一个解就退出循环，本地需要找到多个解，那么在找到一个解之后，不要做返回操作，只需要记录下这个解组合
（3）本提求解的是解的组合，解的答案跟顺序无关，所以要考虑剪枝，在做遍历的时候起始值不应该是0，应该是当前位置右边以后的值

### 代码

```python3
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ListSub = []
        ListTotal = []
        def backtrack(index,val):
            if val==0:
                return True
            for i in range(index,len(candidates)):
                if val-candidates[i]>=0:
                    val1=val-candidates[i]
                    ListSub.append(candidates[i])
                    ret=backtrack(i,val1)
                    if ret:
                        ListTotal.append(ListSub[:])
                    else:
                        break
            ListSub.pop()
            return False
        backtrack(0,target)
        return ListTotal
```