# 题解
## 回溯+剪枝

 1. 初试化结果数组$res$
 2. 定义回溯函数$help(count,i,tmp,target)$，其中$count$表示当前已经使用的数字数，$i$表示当前访问的数字，$tmp$表示当前中间结果，$target$表示下一步的目标和。
  	+ 若$count==k$，说明已经使用了$k$个数：
  		* 若$target==0$，表示$tmp$的和等于$n$，将$tmp$加入$res$。
  		* return
  	+ 遍历区间$[i,10)$：
  		* 剪枝，若$j>target$，说明接下来的数字都比目标和大，$break$
  		* 执行回溯$help(count+1,j+1,tmp+[j],target-j)$
 
 3. 执行$help(0,1,[],n)$
 4. 返回$res$

### 复杂度分析
 - 时间复杂度：$O\left(n!\right)$，进行了一次遍历。
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        res=[]
        def helper(count,i,tmp,target):
            print(count,i,tmp,target)
            if(count==k):
                if(target==0):
                    res.append(tmp)
                return
            for j in range(i,10):
                if(j>target):
                    break
                helper(count+1,j+1,tmp+[j],target-j)
        helper(0,1,[],n)
        return res
```

