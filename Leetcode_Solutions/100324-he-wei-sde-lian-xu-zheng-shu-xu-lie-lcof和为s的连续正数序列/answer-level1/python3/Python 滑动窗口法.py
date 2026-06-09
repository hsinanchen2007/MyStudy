### 解题思路
1、定义一个滑动窗口，固定只能向右移动
2、直接取sum_a = sum(a[i:j])的值与target对比即可
3、当sum_a<target,右边窗口j向右走一个，再判断；当sum_a>target时，左边窗口i向右走一个，**注意：**此时右窗口应该是在i+1的位置上再来一次

### 代码
`
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        ##滑动窗口的方法：
        res = []
        i,j = 0,2
        a = [i for i in range(1,target)]
        while j<target:
            if sum(a[i:j])==target:
                res.append(a[i:j])
            if sum(a[i:j])<target:
                j+=1
            else:
                i+=1
                j=i+1
    
        return res

`