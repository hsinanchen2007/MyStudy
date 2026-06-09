直接生成第k个排列，此时只需挨个找出下一个开头数字即可，步骤如下：

1、首先列出数组n_nums = [1,2,3,…,n]；

2、其次，由实例可以发现，其排列组合规律是由小到大，每个数字做一次开头，然后在剩下的数字中，再循环该规律。如[1,2,3]数组，1、2、3分别作开头数字为：
    "1**"
    "1**"
    "2**"
    "2**"
    "3**"
    "3**"
3、第k个排列的开头数字在n_nums中的位置怎么确定呢？

- 由于n-1个数字的排列组合有 (n-1)! 种，可以求出第k个排列在剩余n-1个数字排列组合中的位置索引 index_next = k % (n-1)!
- 然后可以求出第k个排列此时的开头数字，将其存入结果数组 res 中
4、寻找 n-1 排列中的第index_next个排列的开头数字，转入第3步，直至n_nums中的数字全部用完为止。使用递归完成

```
import math
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        if k > math.factorial(n):return 'IndexError'
        
        #直接生成第k个排列
        n_nums = [i+1 for i in range(n)]
        res = []
        
        def backtrace(n, n_nums, res, index):
            #终止条件
            if n == 0:return
            
            #剩余数字的组合数
            p = math.factorial(n-1)
            #index下一阶排列的位置,为0时即为第p个
            index_next = index % p
            
            #当前开头数字的位置po
            po = index // p
            if index_next != 0:
                po += 1
            else:
                index_next = p
            
            #由于数组从0开始编号，故减1
            res.append(str(n_nums[po-1]))
            # print(po,res)
            del n_nums[po-1]
            
            backtrace(n-1, n_nums, res, index_next)
        
        backtrace(n, n_nums, res, k)
            
        return ''.join(res)

执行结果：通过显示详情
执行用时 :36 ms, 在所有 python3 提交中击败了97.27%的用户
内存消耗 :13.9 MB, 在所有 python3 提交中击败了5.61%的用户
```
