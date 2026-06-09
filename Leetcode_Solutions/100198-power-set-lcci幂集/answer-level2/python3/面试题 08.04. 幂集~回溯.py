### 解题思路
下面我们有两种方法：
#### 回溯(方法1)
![image.png](https://pic.leetcode-cn.com/e7a5f70a5db8ebb889b041304d61e4ad80cc56eea60d0e8c61f73a60164e6756-image.png)
**题目要求：解集不能包含重复的子集**
那么剪去图中的部分就能实现不包含重复的子集，如果你不这样做，你后面需要另外对所有的子集进行去重
代码实现：我们直接对取当前元素的后面的元素就能实现剪枝`nums[i+1:]`
#### 巧妙的方法(方法2)
遍历，遇到一个数就把所有子集加上该数组成新的子集，遍历完毕即是所有子集
开始：[]
遇到1：[],`[1]`
遇到2：[],[1],`[2] [1,2]`
遇到3：[],[1],[2],[1,2],`[3] [1,3] [2,3] [1,2,3]`

#### 看懂的点个赞哦！


### 代码

```python3
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:

        res = []
        print(nums[3:])

        def backtrack(nums, path, res):
            res.append(path)
            if nums == []:
                return 
            for i in range(len(nums)):
                backtrack(nums[i+1:] , path + [nums[i]], res)
        
        backtrack(nums, [], res)

        return res
            

        # res = [[]]
        # for num in nums:
        #     t = res[:]
        #     for lst in t:
        #         print(lst)
        #         temp = lst + [num]
        #         res.append(temp)
        # return res
```