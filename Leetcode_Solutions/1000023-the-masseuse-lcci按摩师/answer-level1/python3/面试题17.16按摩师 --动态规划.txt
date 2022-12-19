### 解题思路
**动态规划**解决0-1问题。这和**198小偷问题**相似。
通过**画网格**把**大问题分成小问题**依次解决。
**网格：**
行：第i个人   列：接收1/不接受0   表中元素值：最长时间
假设有A,B,C,D四个人预约时间分别为1，2，4，3，
可得初始表格：
```
- 0 1
A - -
B - -
C - -
D - -
```
处理A，若A接受/不接受，总的预约时间：
```
- 0 1
A 0 1
```
处理完A，再处理B：B不接收时，最长预约时间为A那一行的最大值；B接受时，要求A只能是不接收的状态，这时最长预约时间为B的预约时间+A不接收时总的最长预约时间。同时注意到这是个**马尔科夫过程**，得到状态转移方程：
`x[i][0]=max(x[i-1][0],x[i-1][1])`
`x[i][1]=x[i-1][0]+newnum`
得到：
```
- 0 1
B 1 2
C 2 5
D 5 6
```



### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        #动态规划：画网格/马尔科夫性
        if not nums:return 0
        if len(nums)==1:return nums[0]
        if len(nums)==2:return max(nums[0],nums[1])
        res0,res1=0,0#不接/接的初始化
        for item in nums:#对每行进行考量接与不接的结果
            res0,res1=max(res0,res1),res0+item
        return max(res0,res1)

```