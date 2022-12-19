执行用时 :
16 ms
, 在所有 Python 提交中击败了
95.45%
的用户
内存消耗 :
11.7 MB
, 在所有 Python 提交中击败了
65.00%
的用户

发现结果的值只与K有关，与N无关。
第一行：0

第二行：01

第三行：0110

第四行：01101001

第五行：0110100110010110

...

这么就得到了，对于K的值，只取决于int(K/2)的值，然后判断一下奇偶即可。

**这里需要注意一点的是，需要将K减1输入，因为K从1开始计数。**
```
class Solution(object):
    def kthGrammar(self, N, K):
        """
        :type N: int
        :type K: int
        :rtype: int
        """
        def getN(K):
            if K == 0:
                return 0
            elif K == 1:
                return 1
            else:
                if getN(int(K/2)) == 0:
                    if K % 2 == 0:
                        return 0
                    else:
                        return 1
                else:
                    if K % 2 == 0:
                        return 1
                    else:
                        return 0
        return getN(K-1)
```
