# 题解
为了去除重复的子集，第一时间想到排序。我们在78.子集上进行进一步的修改。可见[78.子集Leetcode](https://leetcode-cn.com/problems/subsets/solution/hui-su-die-dai-wei-yan-ma-qing-xi-si-lu-zhu-xing-f/)或[78.子集CSDN](https://blog.csdn.net/zhushaojiecumt/article/details/102985157)
## 排序+回溯

 1. 对数组进行排序，初始化结果$res=[]$，数组长度为$n$
 2. 定义回溯函数$track\_back(i,tmp)$，$i$表示当前访问的数组下标，$tmp$为中间子集。
 	* 将$tmp$加入到$res$中。
 	* 若$i==n$，说明当前路径已经访问完成，需要$return$。
 	* 执行遍历，遍历区间$[i,n)$：
 		+ 若 $j>i\ and \ nums[j]==nums[j-1]$，跳过，此步为了去除重复的子集。
 		+ 执行$track\_back(j+1,tmp+[nums[j]])$
 
 3. 执行$track\_back(0,[])$
 4. 返回$res$

### 复杂度分析
 - 时间复杂度：$O(n!)$。
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        n=len(nums)
        nums.sort()
        def track_back(i,tmp):
            res.append(tmp)
            if(i==n):
                return
            for j in range(i,n):
                if(j>i and nums[j]==nums[j-1]):
                    continue
                track_back(j+1,tmp+[nums[j]])
        res=[]
        track_back(0,[])
        return res
```
### Java（待完成）
## 排序+迭代
我们借助于$pre$来保存上个重复数字对应的子集。
一种思路，对于$[1,2,2,3]$,
初始化：
$res=[[]]$
$pre=[]$
遇到1：  

$pre$：$[[],[1]]$，用$res$拓展
$res$：$[[],[1]]$，$res=res+pre$
遇到2：   


$pre$：$[[2],[1,2]]$，用$res$拓展
$res$：$[[],[1],[2],[1,2]]$，$res=res+pre$
遇到2：   

$pre$：$[[2,2],[1,2,2]]$，用$pre$拓展
$res$：$[[],[1],[2],[1,2],[2,2],[1,2,2]]$，$res=res+pre$
遇到3：

$pre$：$[[3],[1,3],[2,3],[1,2,3],[2,2,3],[1,2,2,3]]$，用$res$拓展
$res$：$[[],[1],[2],[1,2],[2,2],[1,2,2],[3],[1,3],[2,3],[1,2,3],[2,2,3],[1,2,2,3]]$，$res=res+pre$


### 复杂度分析
 - 时间复杂度：$O(n!)$。
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        n=len(nums)
        nums.sort()
        res=[[]]
        pre=[]
        for i in range(n):
            if(i>0 and nums[i]==nums[i-1]):
                pre=[tmp+[nums[i]] for tmp in pre]
            else:
                pre=[tmp+[nums[i]] for tmp in res]
            res+=pre
        return res
```
### Java（待完成）
## 位掩码（以后再更新吧）
