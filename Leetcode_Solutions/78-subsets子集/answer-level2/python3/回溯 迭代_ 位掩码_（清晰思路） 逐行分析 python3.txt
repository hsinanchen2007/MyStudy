# 题解
第一时间很容易想到回溯，回溯是寻找全集的很好的办法
## 回溯
 1. 初始化结果$res$和数组长度$n$
 2. 定义回溯函数$track\_back(i,tmp)$，$i$表示当前访问的数组下标。$tmp$为中间结果。
 	* 若$i==n$，说明访问数组越界，return。
 	* 将$tmp$加入到$res$中。
 	* 遍历剩下的数组，进行回溯。对于$j$,在遍历区间$[i+1,n)$中：执行回溯$track\_back(j，tmp+[nums[j]])$
 3. 执行回溯$track\_back(-1,[])$
 4. 返回$res$

### 复杂度分析
 - 时间复杂度：$O(n!)$。
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res=[]
        n=len(nums)
        def track_back(i,tmp):
            if(i==n):
                return
            res.append(tmp)
            for j in range(i+1,n):
                track_back(j,tmp+[nums[j]])
        track_back(-1,[])
        return res
```

## 迭代
一种思路，对于$[1,2,3]$,
初始化：
$res=[]$
遇到1：  
$[1]$
$res$：$[[],[1]]$
遇到2：   
$[2]$
$[1,2]$
$res$：$[[],[1],[2],[1,2]]$
遇到3：
$[3]$
$[1,3]$
$[2,3]$
$[1,2,3]$
$res$：$[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]$
遇到一个数，将结果中的每一个子集数组加上当前元素，形成新的子集，并加入到$res$中。
### 复杂度分析
 - 时间复杂度：$O(n!)$。
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res=[[]]
        for num in nums:
            res=res+[[num]+i for i in res]
        return res
```

## 位掩码
对于$[1,2,3]$，可用三位二进制表示是否选择对应下标的数组元素。则有$8$种组合方式。
| 二进制<br>对应数字 | 1 | 2 |  3| 对应子集 |
|--|--|--|--|--|
| 0 | 0 |  0| 0 |  $[]$|
| 1 |  0|  0|  1|  $[3]$|
| 2 |  0|  1|  0|  $[2]$|
| 3 |  0|  1|  1|  $[2,3]$|
| 4 |  1|  0|  0|  $[1]$|
| 5 |  1|  0|  1|  $[1,3]$|
| 6 |  0|  1|  1|  $[2,3]$|
| 7 |  1|  1|  1|  $[1,2,3]$|

 1. 初始化数组长度$n$，最终结果的长度$res\_len=1<<n$，此处位运算表示的是$2^{n}$。
 2. 对于每种结果，对于$i$在遍历区间$[0,res\_len)$中:
 	* 初始化中间结果$cur=[]$
 	* 从数组第一位到最后一位进行遍历，对于$j$在遍历区间$[0,n)$中：
 		+ 若满足条件$i >> j \& 1$，表示第$j$位是否为1，若满足，则将该位元素加入中间结果$cur$中
 	* 将$cur$加入$res$
 
 3. 返回$res$

### 复杂度分析
 - 时间复杂度：$O(2^{n}*n)$。
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        res_len = 1 << n
        res = []
        for i in range(res_len):
            cur = []
            for j in range(n):
                if i >> j & 1:
                    cur.append(nums[j])
            res.append(cur)
        return res
```